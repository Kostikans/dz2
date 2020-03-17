#pragma once
#define  _GNU_SOURCE
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct Top{
    char fileName[50];
    int levDistValue;
}Top;

typedef struct RequestData
{
    char *name;
    const char *pattern;
    const char *path;
    int levDist;
} RequestData;

int fileRequest(RequestData *data);
int Crawl(const char* pattern,const char *path,Top **top);
char* cat(char *s1, char *s2);
int min(int a1, int a2);
int freeRequestData(RequestData *data);
int createTop(RequestData *data,int count,Top **top);
int initTop(Top *top);