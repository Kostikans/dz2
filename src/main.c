#include "../include/libCrawlSequintally.h"
#include "../include/libCrawlParallel.h"
#include "time.h"
#include "dirent.h"
#include <sys/stat.h>

void addFileName(char *path,int len, char *name){
    memcpy((void*)(path + len), name, len + strlen(name) + 1);
}

int main(){
     char *path = NULL;
    path = get_current_dir_name();
    char *testFolder = "/files";

    int len = (int)strlen(path);
    path = (char*)realloc(path,sizeof(char) * (len * 3));
    mempcpy((void*)(path + strlen(path)),testFolder,strlen(path) + strlen(testFolder) + 1);
    len = (int)strlen(path);
    mkdir(path, (__mode_t) (S_IRWXU | S_IRWXG | S_IRWXO));

    addFileName(path,len,"/1.txt");
    FILE *mf = fopen(path,"w");
    const char* s1 = "kostyarwerwekekewrwejklfjklsdjklfjdsmvnkltwejklnvdmsjrkqejfsd,jekljds,mklwrjkldf,gjwrekljmfdm";
    fprintf(mf,"%s", s1);
    fclose(mf);

    addFileName(path,len,"/2.txt");
    mf = fopen(path,"w");
    const char* s2 = "kostyrewmr34,2mlmrel";
    fprintf(mf,"%s", s2);
    fclose(mf);

    addFileName(path,len,"/3.txt");
    mf = fopen(path,"w");
    const char* s3 = "kostrekerdekw;le23ewekeerwe";
    fprintf(mf,"%s", s3);
    fclose(mf);

    addFileName(path,len,"/4.txt");
    mf = fopen(path,"w");
    const char* s4 = "kosrmemwmkewrmwermw";
    fprintf(mf,"%s", s4);
    fclose(mf);

    addFileName(path,len,"/5.txt");
    mf = fopen(path,"w");
    const char* s5 = "kokekrewrkwelewrternsdmnjk24h3jfnsmdjw4hfmsdkjth4wnfdsmntwhvmfds";
    fprintf(mf,"%s", s5);
    fclose(mf);

    addFileName(path,len,"/6.txt");
    mf = fopen(path,"w");
    const char* s6 = "rewrlewrewkewrwe;l";
    fprintf(mf,"%s", s6);
    fclose(mf);

    addFileName(path,len,"/7.txt");
    mf = fopen(path,"w");
    const char* s7 = "432ljefsfsdrklkl;ewkrwe";
    fprintf(mf,"%s", s7);
    fclose(mf);

    addFileName(path,len,"/8.txt");
    mf = fopen(path,"w");
    const char* s8 = "trendf,nlktjtkjrelkfje";
    fprintf(mf,"%s", s8);
    fclose(mf);

    addFileName(path,len,"/9.txt");
    mf = fopen(path,"w");
    const char* s9 = "dsncmxetreomngfdmngfffdsr43rirweffmdnmcxuweiorjvkcx";
    fprintf(mf,"%s", s9);
    fclose(mf);

    addFileName(path,len,"/10.txt");
    mf = fopen(path,"w");
    const char* s10 = "kokekrewrkwel";
    fprintf(mf,"%s", s10);
    fclose(mf);

    addFileName(path,len,"/1.txt");
    Top *top1 = NULL;
    clock_t begin = clock();

    path = get_current_dir_name();

    len = (int)strlen(path);
    path = (char*)realloc(path,sizeof(char) * (len * 3));
    mempcpy((void*)(path + strlen(path)),testFolder,strlen(path) + strlen(testFolder) + 1);

    Crawl("kokekrewrkwel",path,&top1);

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%f\n",time_spent);

    TopPrl *top2 = NULL;
    begin = clock();
    CrawlPrl("kokekrewrkwel", path ,&top2);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%f",time_spent);

    free(top1);
    free(top2);
    free(path);
    return 0;
}