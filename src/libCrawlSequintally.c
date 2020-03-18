#include "../include/libCrawlSequintally.h"
#include "dirent.h"
#include "limits.h"

int crawl(const char* pattern,const char *path,Top **top)
{
    DIR *mydir = opendir(path);
    if(mydir == NULL) {
        closedir(mydir);
        return 0;
    }
    int requestDataCount = 1;
    RequestData *data = (RequestData*)malloc(requestDataCount * sizeof(RequestData));
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

            if(count == requestDataCount){
                requestDataCount *= 2;
                RequestData *temp;
                temp = realloc(data,requestDataCount * sizeof(RequestData));
                if(temp == NULL)
                    return 0;
                data = temp;
            }
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
