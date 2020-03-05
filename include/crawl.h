#pragma once
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

size_t fileRequest(char *pattern, char *path,char *top);
char* crawl(char* patter,char *path);
char* cat(char *s1, char *s2);
int min(int a1, int a2);