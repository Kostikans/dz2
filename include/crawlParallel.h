#pragma once
#define  _GNU_SOURCE
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/sysinfo.h>

typedef struct TopPrl{
    char *fileName;
    int levDistValue;
}TopPrl;

typedef struct RequestDataPrl
{
    char *name;
    const char *pattern;
    const char *path;
    int levDist;
} RequestDataPrl;

void* fileRequestPrl(RequestDataPrl *data);
void* CrawlPrl(const char* pattern,const char *path,TopPrl **top);
char* catPrl(char *s1, char *s2);
int minPrl(int a1, int a2);
size_t threadsRunPrl(pthread_t **threads,int pullSize);
void* freeRequestDataPrl(RequestDataPrl *data);
void* createTopPrl(RequestDataPrl *data,int count,TopPrl **top);