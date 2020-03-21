#pragma once

#define  _GNU_SOURCE
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "stdio.h"
#define FILE_NAME_BUFFER_SIZE 100

typedef struct Top{
    char fileName[FILE_NAME_BUFFER_SIZE];
    int levDistValue;
}Top;

typedef struct RequestData
{
    char *name;
    const char *pattern;
    const char *path;
    int levDist;
} RequestData;

char* cat(const char *s1,const char *s2);
int min(int a1, int a2);
int freeRequestData(RequestData *data);
int createTop(RequestData *data,int count,Top **top);
int initTop(Top *top);
int fileRequest(RequestData *data);
int createBuffer(char **buffer,RequestData *data);
