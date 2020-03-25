#include "../include/libCrawlParallel.h"
#include "dirent.h"
static void threadsWait(pthread_t **threads,int pullSize);
static int runThreads(pthread_t **pthread,RequestData *data,int count, int pullSize);
static void freeDataOnError(RequestData *data,DIR *dir, char *filePath);
static int growRequestData(RequestData **data,int *requestDataCount);
static int initRequestData(RequestData *data,int count ,char *name,const char *pattern,char *filePath);

int initRequestData(RequestData *data,int count, char *name,const char *pattern,char *filePath){
    data[count].name = name;
    data[count].pattern = pattern;
    data[count].path = (char*)calloc(sizeof(char),strlen(filePath) + 1);
    if(data[count].path == NULL) {
        return 0;
    }
    memcpy((char*)data[count].path,filePath,strlen(filePath) * sizeof(char));
    return 1;
}

int runThreads(pthread_t **pthread, RequestData *data,int count ,int pullSize){
    for(int i = 0; i < pullSize;++i){
        int err =  pthread_create(pthread[i], NULL, (void *(*)(void *)) fileRequest, &data[count + i]);
        if(err != 0){
            return 0;
        }
    }
    threadsWait(pthread,pullSize);
    for(int i = 0; i < pullSize;++i){
        free(pthread[i]);
        free((char*)data[count + i].path);
    }
    return 1;
}
void freeDataOnError(RequestData *data,DIR *dir, char *filePath){
    free(data);
    closedir(dir);
    free(filePath);
}

void threadsWait(pthread_t **threads,int pullSize)
{
    for(size_t i = 0; i < pullSize; ++i)
    {
        pthread_join(*threads[i],NULL);
    }
}
int growRequestData(RequestData **data,int *requestDataCount){
    *requestDataCount *= 2;
    RequestData *temp;
    temp = realloc(*data,*requestDataCount * sizeof(RequestData));
    if(temp == NULL) {
        return 0;
    }
    *data = temp;
    return *requestDataCount;
}

int crawlPrl(const char* pattern,const char *path,Top **top){
    if(pattern == NULL || path == NULL)
        return 0;
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
    if (data == NULL){
        closedir(mydir);
        return 0;
    }

    struct dirent *entry;
    int ThreadCount = 0;
    entry = readdir(mydir);
    while(entry) {
        entry = readdir(mydir);
        if(!entry){
            int temp = count - ThreadCount;
            runThreads(pthread, data, temp, ThreadCount);
            break;
        }
        char* name = entry->d_name;
        if(strcmp(name,".") != 0 && strcmp(name,"..") != 0) {
            char* filePath = cat((char*)path,name);

            if(count == requestDataCount){
                requestDataCount = growRequestData(&data,&requestDataCount);
                if(requestDataCount == 0) {
                    freeDataOnError(data, mydir, filePath);
                    return 0;
                }
            }

            if(initRequestData(data,count,name,pattern,filePath) == 0){
                freeDataOnError(data,mydir,filePath);
                return 0;
            }

            pthread[ThreadCount] = (pthread_t*)malloc(sizeof(pthread_t));
            if(pthread[ThreadCount] == NULL) {
                freeDataOnError(data,mydir,filePath);
                return 0;
            }
            ++ThreadCount;
            if(ThreadCount == ThreadsCount)
            {
                int temp = count - ThreadCount + 1;
                runThreads(pthread, data, temp, ThreadCount);
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

