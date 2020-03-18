#include "../include/libCrawlParallel.h"
#include "dirent.h"
#include "limits.h"

void threadsRunPrl(pthread_t **threads,int pullSize)
{
    for(size_t i = 0; i < pullSize; ++i)
    {
        pthread_join(*threads[i],NULL);
    }
}

int crawlPrl(const char* pattern,const char *path,Top **top){
    int ThreadsCount = get_nprocs();
    DIR *mydir = opendir(path);
    if(mydir == NULL) {
        closedir(mydir);
        return 0;
    }
    int count = 0;

    pthread_t *pthread[ThreadsCount];
    for(int i = 0; i < ThreadsCount; ++i)
        pthread[i] = NULL;

    int requestDataCount = 1;
    RequestData *data = (RequestData*)malloc(requestDataCount * sizeof(RequestData));

    struct dirent *entry;
    int ThreadCount = 0;
    entry = readdir(mydir);
    while(entry) {
        entry = readdir(mydir);
        if(!entry){
            int temp = count - ThreadCount;
            for(int i = 0; i < ThreadCount;++i){
                pthread_create(pthread[i], NULL, (void *(*)(void *)) fileRequest, &data[temp + i]);
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
            char* filePath = cat((char*)path,name);

            if(count == requestDataCount){
                requestDataCount *= 2;
                RequestData *temp;
                temp = realloc(data,requestDataCount * sizeof(RequestData));
                if(temp == NULL)
                    return 0;
                data = temp;
            }

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
                    pthread_create(pthread[i], NULL, (void *(*)(void *))fileRequest, &data[count - i]);
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
    createTop(data,count,top);
    free(data);
    closedir(mydir);
    return 1;
}

