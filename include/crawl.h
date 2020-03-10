#pragma once
#define  _GNU_SOURCE
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct RequestData
{
    char *pattern;
    char *path;
    char *top;
} RequestData;

void* fileRequest(RequestData *data);
char* sequentialCrawl(char* pattern,char *path);
char* parallelCrawl(char* pattern,char *path);
char* cat(char *s1, char *s2);
int min(int a1, int a2);
size_t threadsRun(pthread_t **threads,int pullSize);
void* freeRequestData(RequestData *data);