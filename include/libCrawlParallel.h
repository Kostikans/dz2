#pragma once
#include "../include/utils.h"
#include <pthread.h>
#include <sys/sysinfo.h>

int crawlPrl(const char* pattern,const char *path,Top **top);
void threadsRunPrl(pthread_t **threads,int pullSize);
