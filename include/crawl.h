#pragma once
#define  _GNU_SOURCE
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct Top{
    char *fileName;
    int levDistValue;
}Top;

typedef struct RequestData
{
    char *name;
    const char *pattern;
    const char *path;
    int levDist;
} RequestData;

void* fileRequest(RequestData *data);
void* sequentialCrawl(const char* pattern,const char *path,Top **top);
void* parallelCrawl(const char* pattern,const char *path,Top **top);
char* cat(char *s1, char *s2);
int min(int a1, int a2);
size_t threadsRun(pthread_t **threads,int pullSize);
void* freeRequestData(RequestData *data);
void* createTop(RequestData *data,int count,Top **top);