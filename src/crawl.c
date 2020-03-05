#include "crawl.h"
#include "dirent.h"

size_t fileRequest(char *pattern, char *path,char *top)
{
    FILE * file;
    if((file = fopen(path,"r")) == NULL) {
        printf("Failed to open file. path:");
        printf("%s",path);
        return 0;
    }
    size_t patternLen = strlen(pattern);
    const size_t bufSize = 1024 * 1024;
    char buffer[bufSize];
    fgets(buffer,bufSize,file);

    int *levDist = (int*)calloc(sizeof(int),patternLen + 1);
    levDist[0] = 0;
    int insertCost = 1;
    int deleteCost = 1;
    int replaceCost = 1;
    for(size_t i = 1; i < patternLen; ++i){
        levDist[i] = levDist[i-1] + deleteCost;
    }
    for(size_t j = 1;j <= bufSize; ++j){
        int previousDiag = levDist[0];
        int previousDiagSave;
        levDist[0] += insertCost;
        for(size_t i = 1; i <= patternLen;++i){
            if(buffer[j-1] == '\n' || pattern[i-1] == '\n')
                continue;
            previousDiagSave = levDist[i];
            if(pattern[i-1] == buffer[j-1]){
                levDist[i] = previousDiag;
            }
            else{
                levDist[i] = min(min(levDist[i-1] + deleteCost, levDist[i] + insertCost),
                        previousDiag + 1);
            }
            previousDiag = previousDiagSave;
        }
        if(buffer[j] == '\0')
            break;
    }
    for(int i = 0; i <= patternLen; ++i)
    {
        printf("%d ",levDist[i]);
    }
    //printf("%d",levDist[patternLen]);
    printf("%s","  ");
    printf("%s",buffer);
    printf("%c",'\n');
    fclose(file);
}
char* crawl(char* pattern,char *path)
{
    DIR *mydir = opendir(path);
    char top[5];
    if(mydir == NULL) {
        return 0;
    }
    struct dirent *entry;
    while(entry = readdir(mydir)) {
        char* name = entry->d_name;
        if(strcmp(name,".") && strcmp(name,"..")) {
            char* filePath = cat(path,name);
            fileRequest(pattern, filePath,top);
            free(filePath);
        }
        else
            continue;
    }
    free(mydir);
}
char* cat(char *s1, char *s2) {
    if(s1 == NULL || s2 == NULL)
        return 0;
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);

    char *result = (char*)malloc((len1 + len2 + 2) * sizeof(char));
    if(result == NULL)
        return NULL;
    memcpy(result,s1,len1);
    result[len1] = '/';
    memcpy(result+len1 + 1,s2,len2+1);

    return result;
}

int min(const int a1, const int a2){
    if(a1 <= a2)
        return a1;
    else
        return a2;
}