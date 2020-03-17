#include "../include/crawlParallel.h"
#include "dirent.h"
#include "limits.h"

#define FILES_COUNT 500

void threadsRunPrl(pthread_t **threads,int pullSize)
{
    for(size_t i = 0; i < pullSize; ++i)
    {
        pthread_join(*threads[i],NULL);
    }
}

int fileRequestPrl(RequestDataPrl *data)
{
    FILE * file;
    if((file = fopen(data->path,"r")) == NULL) {
        printf("Failed to open file. path:");
        printf("%s",data->path);
        return 0;
    }
    size_t patternLen = strlen(data->pattern);
    size_t fileSize = 0;

    fseek(file, 0, SEEK_END);
    fileSize = ftello(file);
    char buffer[fileSize * sizeof(char)];
    fseek(file, 0, 0);
    fgets(buffer,fileSize,file);
    fclose(file);

    int *levDist = (int*)calloc(sizeof(int),patternLen + 1);
    if(levDist == NULL)
        return 0;
    levDist[0] = 0;
    int insertCost = 1;
    int deleteCost = 1;
    int replaceCost = 1;
    for(size_t i = 1; i < patternLen; ++i){
        levDist[i] = levDist[i-1] + deleteCost;
    }
    for(size_t j = 1;j <= fileSize; ++j){
        int previousDiag = levDist[0];
        int previousDiagSave;
        levDist[0] += insertCost;
        for(size_t i = 1; i <= patternLen;++i){
            if(buffer[j-1] == '\n' || data->pattern[i-1] == '\n')
                continue;
            previousDiagSave = levDist[i];
            if(data->pattern[i-1] == buffer[j-1]){
                levDist[i] = previousDiag;
            }
            else{
                levDist[i] = minPrl(minPrl(levDist[i-1] + deleteCost, levDist[i] + insertCost),
                                 previousDiag + replaceCost);
            }
            previousDiag = previousDiagSave;
        }
        if(buffer[j] == '\0')
            break;
    }
    data->levDist = levDist[patternLen];
    free(levDist);
    return 1;
}

int CrawlPrl(const char* pattern,const char *path,TopPrl **top){
    int ThreadsCount = get_nprocs();
    DIR *mydir = opendir(path);
    if(mydir == NULL) {
        free(mydir);
        return 0;
    }
    int count = 0;

    pthread_t *pthread[ThreadsCount];
    for(int i = 0; i < ThreadsCount; ++i)
        pthread[i] = NULL;
    RequestDataPrl *data = (RequestDataPrl*)malloc(FILES_COUNT * sizeof(RequestDataPrl));
    struct dirent *entry;
    int ThreadCount = 0;
    entry = readdir(mydir);
    while(entry) {
        entry = readdir(mydir);
        if(!entry){
            int temp = count - ThreadCount;
            for(int i = 0; i < ThreadCount;++i){
                pthread_create(pthread[i], NULL, (void *(*)(void *)) fileRequestPrl, &data[temp + i]);
            }
            threadsRunPrl(pthread,ThreadCount);
            for(int i = 0; i < ThreadCount;++i){
                free(pthread[i]);
                free((char*)data[temp + i].path);
            }
            break;
        }
        char* name = entry->d_name;
        if(strcmp(name,".") != 0 && strcmp(name,"..") != 0) {

            char* filePath = catPrl((char*)path,name);
            data[count].name = name;
            data[count].pattern = pattern;
            data[count].path = (char*)calloc(sizeof(char),strlen(filePath) + 1);
            if(data[count].path == NULL)
                return 0;
            if(!memcpy((char*)data[count].path,filePath,strlen(filePath) * sizeof(char)))
                return 0;

            pthread[ThreadCount] = (pthread_t*) malloc(sizeof(pthread_t));
            if(pthread[ThreadCount] == NULL)
                return 0;
            ++ThreadCount;
            if(ThreadCount == ThreadsCount)
            {
                for(int i = 0; i < ThreadCount;++i){
                    pthread_create(pthread[i], NULL, (void *(*)(void *))fileRequestPrl, &data[count - i]);
                }
                threadsRunPrl(pthread,ThreadCount);
                for(int i = 0; i < ThreadCount;++i){
                    free(pthread[i]);
                    free((char*)data[count - i].path);
                }
                ThreadCount = 0;
            }
            count++;
            free(filePath);
        }
    }
    createTopPrl(data,count,top);
    free(data);
    free(mydir);
    return 1;
}
char* catPrl(char *s1, char *s2) {
    if(s1 == NULL || s2 == NULL)
        return 0;
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);

    char *result = (char*)malloc((len1 + len2 + 2) * sizeof(char));
    if(result == NULL)
        return NULL;
    memcpy(result,s1,len1);
    result[len1] = '/';
    memcpy(result+len1 + 1,s2,len2+1);

    return result;
}

int minPrl(const int a1, const int a2){
    if(a1 <= a2)
        return a1;
    else
        return a2;
}
int freeRequestDataPrl(RequestDataPrl *data){
    free((char*)data->path);
    free(data);
    return 1;
}

int createTopPrl(RequestDataPrl *data,int count,TopPrl **top){
    *top = (TopPrl*)malloc(5 * sizeof(TopPrl));
    for(int i = 0; i < 5; ++i){
        (*top)[i].levDistValue = INT_MAX;
    }

    int min = INT_MAX;
    int currentMin = -1;
    int pos = 0;
    for(int i = 0; i < 5; ++i) {
        for (int j = 0; j < count; ++j) {
            if ( min > data[j].levDist && data[j].levDist > currentMin) {
                min = data[j].levDist;
                pos = j;
            }
        }
        currentMin = min;
        min = INT_MAX;
        (*top)[i].fileName = data[pos].name;
        (*top)[i].levDistValue = data[pos].levDist;
    }
    for(int i = 0; i < 5; ++i){
        printf("%d %s%c",(*top)[i].levDistValue,(*top)[i].fileName,'\n');
    }
    return 1;
}
