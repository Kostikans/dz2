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

int fileRequestPrl(RequestDataPrl *data);
int CrawlPrl(const char* pattern,const char *path,TopPrl **top);
char* catPrl(char *s1, char *s2);
int minPrl(int a1, int a2);
void threadsRunPrl(pthread_t **threads,int pullSize);
int freeRequestDataPrl(RequestDataPrl *data);
int createTopPrl(RequestDataPrl *data,int count,TopPrl **top);