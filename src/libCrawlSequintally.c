#include "../include/libCrawlSequintally.h"
#include "dirent.h"
#include "limits.h"

#define FILES_COUNT 500

int crawl(const char* pattern,const char *path,Top **top)
{
    DIR *mydir = opendir(path);
    if(mydir == NULL) {
        closedir(mydir);
        return 0;
    }
    RequestData *data = (RequestData*)malloc(FILES_COUNT * sizeof(RequestData));
    int count = 0;
    struct dirent *entry;
    entry = readdir(mydir);
    while(entry) {
        entry = readdir(mydir);
        if(!entry)
            break;
        char* name = entry->d_name;
        if(strcmp(name,".") != 0 && strcmp(name,"..") != 0) {
            char* filePath = cat((char*)path,name);
            data[count].name = name;
            data[count].pattern = pattern;
            data[count].path = filePath;
            fileRequest(&data[count]);
            ++count;
            free(filePath);
        }
    }
    createTop(data,count,top);
    free(data);
    free(mydir);
    return 1;
}
