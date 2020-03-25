#include "../include/utils.h"
#include "limits.h"

#define TOP_SIZE 5

char* cat(const char *s1,const char *s2){
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
int min(int a1, int a2){
    if(a1 <= a2)
        return a1;
    else
        return a2;
}

int createBuffer(char **buffer, RequestData *data){
    FILE * file;
    if((file = fopen(data->path,"r")) == NULL) {
        printf("Failed to open file. path:");
        printf("%s",data->path);
        return 0;
    }

    size_t fileSize = 0;
    fseek(file, 0, SEEK_END);
    fileSize = ftello(file);
    *buffer = (char*)malloc(fileSize * sizeof(char));
    if(*buffer == NULL) {
        fclose(file);
        return 0;
    }
    fseek(file, 0, 0);
    if(fgets(*buffer,fileSize,file) == NULL) {
        free(buffer);
        fclose(file);
        return 0;
    }
    fclose(file);
    return fileSize;
}

int fileRequest(RequestData *data)
{
    char *buffer = NULL;
    int fileSize =  createBuffer(&buffer,data);
    if(fileSize == 0){
        free(buffer);
        return 0;
    }

    size_t patternLen = strlen(data->pattern);
    int *levDist = (int*)calloc(sizeof(int),patternLen + 1);
    if(levDist == NULL) {
        free(levDist);
        free(buffer);
        return 0;
    }
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
                levDist[i] = min(min(levDist[i-1] + deleteCost, levDist[i] + insertCost),
                                 previousDiag + replaceCost);
            }
            previousDiag = previousDiagSave;
        }
        if(buffer[j] == '\0')
            break;
    }
    data->levDist = levDist[patternLen];
    free(levDist);
    free(buffer);
    return 1;
}

int initTop(Top *top){
    top->levDistValue = INT_MAX;
    for(int i = 0; i < FILE_NAME_BUFFER_SIZE;++i)
    {
        top->fileName[i] = '0';
    }
    return 1;
}

int createTop(RequestData *data,int count,Top **top){
    if(data == NULL)
        return 0;
    *top = (Top*)malloc(TOP_SIZE * sizeof(Top));
    if(*top == NULL)
        return 0;
    for(int i = 0; i < TOP_SIZE; ++i){
        initTop(&(*top)[i]);
    }

    int min = INT_MAX;
    int currentMin = -1;
    int pos = 0;
    for(int i = 0; i < TOP_SIZE; ++i) {
        for (int j = 0; j < count; ++j) {
            if ( min > data[j].levDist && data[j].levDist > currentMin) {
                min = data[j].levDist;
                pos = j;
            }
        }
        currentMin = min;
        min = INT_MAX;
        int j = 0;
        for(j = 0; j < strlen(data[pos].name); ++j){
            (*top)[i].fileName[j] = data[pos].name[j];
        }
        (*top)[i].fileName[j] = '\0';
        (*top)[i].levDistValue = data[pos].levDist;
    }
    return 1;
}

