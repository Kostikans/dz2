#include "../include/libCrawlSequintally.h"
#include "../include/libCrawlParallel.h"
#include "time.h"
#include "dirent.h"
#include <sys/stat.h>

void addFileName(char *path,int len, char *name){
    memcpy((void*)(path + len), name, len + strlen(name) + 1);
}

static void addTestString(const char *str,char *path, char* fileName, int len){
    addFileName(path,len,fileName);
    FILE *mf = fopen(path,"w");

    fprintf(mf,"%s", str);
    fclose(mf);

}

static int createTestFiles(){
    char *path = NULL;
    path = get_current_dir_name();
    char *testFolder = "/files";

    int len = (int)strlen(path);
    char *tmp = NULL;
    tmp = (char*)realloc(path,sizeof(char) * (len * 3));
    if(tmp != NULL){
        path = tmp;
    }

    mempcpy((void*)(path + strlen(path)),testFolder,strlen(path) + strlen(testFolder) + 1);
    len = (int)strlen(path);
    mkdir(path, (__mode_t) (S_IRWXU | S_IRWXG | S_IRWXO));

    const char* s1 = "kostyarwerwekekewrwejklfjklsdjklfjdsmvnkltwejklnvdmsjrkqejfsd,jekljds,mklwrjkldf,gjwrekljmfdm";
    addTestString(s1,path,"/1.txt",len);

    const char* s2 = "kostyrewmr34,2mlmrel";
    addTestString(s2,path,"/2.txt",len);

    const char* s3 = "kostrekerdekw;le23ewekeerwe";
    addTestString(s3,path,"/3.txt",len);

    const char* s4 = "kosrmemwmkewrmwermw";
    addTestString(s4,path,"/4.txt",len);

    const char* s5 = "kokekrewrkwelewrternsdmnjk24h3jfnsmdjw4hfmsdkjth4wnfdsmntwhvmfds";
    addTestString(s5,path,"/5.txt",len);

    const char* s6 = "rewrlewrewkewrwe;l";
    addTestString(s6,path,"/6.txt",len);

    const char* s7 = "432ljefsfsdrklkl;ewkrwe";
    addTestString(s7,path,"/7.txt",len);

    const char* s8 = "trendf,nlktjtkjrelkfje";
    addTestString(s8,path,"/8.txt",len);

    const char* s9 = "dsncmxetreomngfdmngfffdsr43rirweffmdnmcxuweiorjvkcx";
    addTestString(s9,path,"/9.txt",len);

    const char* s10 = "kokekrewrkwel";
    addTestString(s10,path,"/10.txt",len);

    free(path);
    return 1;
}

void test(char *path){
    Top *top1 = NULL;
    crawl("kokekrewrkwel",path,&top1);
    Top *top2 = NULL;
    crawlPrl("kokekrewrkwel",path,&top2);
    if(top1[0].levDistValue == top2[0].levDistValue){
        printf("OK\n");
    }
    else{
        printf("NO\n");
    }
    free(top1);
    free(top2);

    top1 = NULL;
    crawl("kokekrewrkwel",path ,&top1);
    top2 = NULL;
    crawlPrl("kokekrewrkwel",path,&top2);
    if(top1[1].levDistValue == top2[1].levDistValue){
        printf("OK\n");
    }
    else{
        printf("NO\n");
    }
    free(top1);
    free(top2);

    top1 = NULL;
    crawl("kokekrewrkwel",path,&top1);
    top2 = NULL;
    crawlPrl("kokekrewrkwel",path,&top2);
    if(top1[2].levDistValue == top2[2].levDistValue){
        printf("OK\n");
    }
    else{
        printf("NO\n");
    }
    free(top1);
    free(top2);

    top1 = NULL;
    crawl("kokekrewrkwel",path,&top1);
    top2 = NULL;
    crawlPrl("kokekrewrkwel",path,&top2);
    if(top1[3].levDistValue == top2[3].levDistValue){
        printf("OK\n");
    }
    else{
        printf("NO\n");
    }
    free(top1);
    free(top2);

    top1 = NULL;
    crawl("kokekrewrkwel",path,&top1);
    top2 = NULL;
    crawlPrl("kokekrewrkwel",path,&top2);
    if(top1[4].levDistValue == top2[4].levDistValue){
        printf("OK\n");
    }
    else{
        printf("NO\n");
    }
    free(top1);
    free(top2);

    top1 = NULL;
    crawl("kokekrewrkwel",path,&top1);
    if(strcmp(top1[3].fileName,"2.txt") == 0){
        printf("OK\n");
    }
    else{
        printf("NO\n");
    }
    free(top1);

    top1 = NULL;
    crawl("kokekrewrkwel",path,&top1);
    if(strcmp(top1[0].fileName, "10.txt") == 0){
        printf("OK\n");
    }
    else{
        printf("NO\n");
    }
    free(top1);

    top2 = NULL;
    crawlPrl("kokekrewrkwel",path,&top2);
    if(strcmp(top2[2].fileName,"6.txt") == 0){
        printf("OK\n");
    } else{
        printf("NO\n");
    }
    free(top2);

    top1 = NULL;
    crawl("kokekrewrkwel",path,&top1);
    if(strcmp(top1[1].fileName,"4.txt") == 0){
        printf("OK\n");
    }
    else{
        printf("NO\n");
    }
    free(top1);

    top2 = NULL;
    crawlPrl("kokekrewrkwel",path,&top2);
    if(strcmp(top2[4].fileName,"3.txt") == 0){
        printf("OK\n");
    }
    else{
        printf("NO\n");
    }
    free(top2);
}

int main(){
    createTestFiles();
    char * path = get_current_dir_name();
    char *testFolder = "/files";

    int len = (int)strlen(path);
    path = (char*)realloc(path,sizeof(char) * (len * 3));
    mempcpy((void*)(path + strlen(path)),testFolder,strlen(path) + strlen(testFolder) + 1);

    test(path);

    Top *top1 = NULL;
    clock_t begin = clock();
    crawl("kokekrewrkwel",path,&top1);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%f\n",time_spent);

    Top *top2 = NULL;
    begin = clock();
    crawlPrl("kokekrewrkwel", path ,&top2);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%f",time_spent);

    printf("\n");
    for(int i = 0; i < 5; ++i){
        printf("%s ",top1[i].fileName);
    }
    printf("\n");
    for(int i = 0; i < 5; ++i){
        printf("%s ",top2[i].fileName);
    }

    free(top1);
    free(top2);
    free(path);
    return 0;
}
