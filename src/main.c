#include "../include/libCrawlSequintally.h"
#include "../include/libCrawlParallel.h"
#include "time.h"
#include "dirent.h"
#include <sys/stat.h>
#define BUFF_SIZE 100

static void addFileName(char *path,int len, char *name){
    memcpy((void*)(path + len), name,  strlen(name) + 1);
}

static void addTestString(const char *str,char *path, char* fileName, int len){
    addFileName(path,len,fileName);
    FILE *mf = fopen(path,"w");

    fprintf(mf,"%s", str);
    fclose(mf);
}

static int createTestFiles(){

    char *path = NULL;
    path = getcwd(path,BUFF_SIZE);
    char *testFolder = "/files";
    size_t len = strlen(path);
    size_t testLen = strlen(testFolder);

    memcpy(path + len, testFolder, testLen + 1);
    len = (int)strlen(path);

    mkdir(path, (__mode_t) (S_IRWXU | S_IRWXG | S_IRWXO));

    const char* s1 = "Hi Amy! Your mum sent me a text. You forgot your inhaler. Why don’t you turn your phone on? Amy didn’t like technology. ";
    addTestString(s1,path,"/1.txt",len);

    const char* s2 = "Hi Amy! Your mum sent me a text. You forgot your inhaler. Why don’t you turn your phone on? Amy didn’t like technology. She ";
    addTestString(s2,path,"/2.txt",len);

    const char* s3 = "Hi Amy! Your mum sent me a text. You forgot your inhaler. Why don’t you turn your phone on? Amy didn’t like technology. She never ";
    addTestString(s3,path,"/3.txt",len);

    const char* s4 = "Hi Amy! Your mum sent me a text. You forgot your inhaler. Why don’t you turn your phone on? Amy didn’t like technology. She never sent ";
    addTestString(s4,path,"/4.txt",len);

    const char* s5 = "Hi Amy! Your mum sent me a text. You forgot your inhaler. Why don’t you turn your phone on? Amy didn’t like technology. She never sent text ";
    addTestString(s5,path,"/5.txt",len);

    const char* s6 = "Hi Amy! Your mum sent me a text. You forgot your inhaler. Why don’t you turn your phone on? Amy didn’t like technology. She never sent text messages ";
    addTestString(s6,path,"/6.txt",len);

    const char* s7 = "Hi Amy! Your mum sent me a text. You forgot your inhaler. Why don’t you turn your phone on? Amy didn’t like technology. She never sent text messages and ";
    addTestString(s7,path,"/7.txt",len);

    const char* s8 = "Hi Amy! Your mum sent me a text. You forgot your inhaler. Why don’t you turn your phone on? Amy didn’t like technology. She never sent text messages and she";
    addTestString(s8,path,"/8.txt",len);

    const char* s9 = "Hi Amy! Your mum sent me a text. You forgot your inhaler. Why don’t you turn your phone on? Amy didn’t like technology. She never sent text messages and she hated ";
    addTestString(s9,path,"/9.txt",len);

    const char* s10 = "Hi Amy! Your mum sent me a text. You forgot your inhaler. Why don’t you turn your phone on? Amy didn’t like technology. She never sent text messages and she hated Facebook";
    addTestString(s10,path,"/10.txt",len);

    free(path);
    return 1;
}

static void test(char *path){
    const char* test = "Hi Amy! Your mum sent me a text. You forgot your inhaler. Why don’t you turn your phone on? Amy didn’t like technology. She never sent ";
    Top *top1 = NULL;
    crawl(test,path,&top1);
    Top *top2 = NULL;
    crawlPrl(test,path,&top2);
    if(top1[0].levDistValue == top2[0].levDistValue){
        printf("OK\n");
    }
    else{
        printf("NO\n");
    }
    free(top1);
    free(top2);

    top1 = NULL;
    crawl(test,path ,&top1);
    top2 = NULL;
    crawlPrl(test,path,&top2);
    if(top1[1].levDistValue == top2[1].levDistValue){
        printf("OK\n");
    }
    else{
        printf("NO\n");
    }
    free(top1);
    free(top2);

    top1 = NULL;
    crawl(test,path,&top1);
    top2 = NULL;
    crawlPrl(test,path,&top2);
    if(top1[2].levDistValue == top2[2].levDistValue){
        printf("OK\n");
    }
    else{
        printf("NO\n");
    }
    free(top1);
    free(top2);

    top1 = NULL;
    crawl(test,path,&top1);
    top2 = NULL;
    crawlPrl(test,path,&top2);
    if(top1[3].levDistValue == top2[3].levDistValue){
        printf("OK\n");
    }
    else{
        printf("NO\n");
    }
    free(top1);
    free(top2);

    top1 = NULL;
    crawl(test,path,&top1);
    top2 = NULL;
    crawlPrl(test,path,&top2);
    if(top1[4].levDistValue == top2[4].levDistValue){
        printf("OK\n");
    }
    else{
        printf("NO\n");
    }
    free(top1);
    free(top2);

    top1 = NULL;
    crawl(test,path,&top1);
    if(strcmp(top1[3].fileName,"2.txt") == 0){
        printf("OK\n");
    }
    else{
        printf("NO\n");
    }
    free(top1);

    top1 = NULL;
    crawl(test,path,&top1);
    if(strcmp(top1[3].fileName, "2.txt") == 0){
        printf("OK\n");
    }
    else{
        printf("NO\n");
    }
    free(top1);

    top2 = NULL;
    crawlPrl(test,path,&top2);
    if(strcmp(top2[2].fileName,"3.txt") == 0){
        printf("OK\n");
    } else{
        printf("NO\n");
    }
    free(top2);

    top1 = NULL;
    crawl(test,path,&top1);
    if(strcmp(top1[1].fileName,"5.txt") == 0){
        printf("OK\n");
    }
    else{
        printf("NO\n");
    }
    free(top1);

    top2 = NULL;
    crawlPrl(test,path,&top2);
    if(strcmp(top2[0].fileName,"4.txt") == 0){
        printf("OK\n");
    }
    else{
        printf("NO\n");
    }
    free(top2);
}

int main(){
    char *path = NULL;
    path = getcwd(path,BUFF_SIZE);
    createTestFiles();
    char *testFolder = "/files";
    memcpy((void*)(path + strlen(path)), testFolder, strlen(testFolder) + 1);

    const char* testText = "Hi Amy! Your mum sent me a text. You forgot your inhaler. Why don’t you turn your phone on? Amy didn’t like technology. She never sent ";
    test(path);
    Top *top1 = NULL;
    clock_t begin = clock();
    crawl(testText, path ,&top1);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%f\n",time_spent);

    Top *top2 = NULL;
    begin = clock();
    crawlPrl(testText, path ,&top2);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%f\n",time_spent);

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
