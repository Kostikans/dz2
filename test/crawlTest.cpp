#include "gtest/gtest.h"

extern "C" {
    #include "../include/libCrawlSequintally.h"
    #include "../include/libCrawlParallel.h"
}

int getLastOf(char *path){
    int count  = 0;
    int i = 0;
    int t = 0;
    while(path[i] != '\0'){
        if(path[i] == '/') {
            count += (t);
            t = 0;
        }
        ++i;
        ++t;
    }
    return count;
}

TEST(case1,test1){

    char *paths = get_current_dir_name();
    char *testFolder = (char*)"/files";
    int len = getLastOf(paths);
    char *path = (char*)malloc(sizeof(char) * (len + strlen(testFolder)));
    memcpy(path,paths,strlen(paths));
    memcpy((void*)(path + len),testFolder, len + strlen(testFolder) + 1);

    Top *top1;
    Crawl("kokekrewrkwel",path,&top1);
    TopPrl *top2;
    CrawlPrl("kokekrewrkwel",path,&top2);
    ASSERT_EQ(top1[0].levDistValue, top2[0].levDistValue);
    free(top1);
    free(top2);
}

TEST(case2,test2)
{
    char *paths = get_current_dir_name();
    char *testFolder = (char*)"/files";
    int len = getLastOf(paths);
    char *path = (char*)malloc(sizeof(char) * (len + strlen(testFolder)));
    memcpy(path,paths,strlen(paths));
    memcpy((void*)(path + len),testFolder, len + strlen(testFolder) + 1);

    Top *top1;
    Crawl("kokekrewrkwel",path ,&top1);
    TopPrl *top2;
    CrawlPrl("kokekrewrkwel",path,&top2);
    ASSERT_EQ(top1[1].levDistValue, top2[1].levDistValue);
    free(top1);
    free(top2);
}

TEST(case3,test3)
{
    char *paths = get_current_dir_name();
    char *testFolder = (char*)"/files";
    int len = getLastOf(paths);
    char *path = (char*)malloc(sizeof(char) * (len + strlen(testFolder)));
    memcpy(path,paths,strlen(paths));
    memcpy((void*)(path + len),testFolder, len + strlen(testFolder) + 1);

    Top *top1;
    Crawl("kokekrewrkwel",path,&top1);
    TopPrl *top2;
    CrawlPrl("kokekrewrkwel",path,&top2);
    ASSERT_EQ(top1[2].levDistValue ,top2[2].levDistValue);
    free(top1);
    free(top2);
}

TEST(case4,test4){
    char *paths = get_current_dir_name();
    char *testFolder = (char*)"/files";
    int len = getLastOf(paths);
    char *path = (char*)malloc(sizeof(char) * (len + strlen(testFolder)));
    memcpy(path,paths,strlen(paths));
    memcpy((void*)(path + len),testFolder, len + strlen(testFolder) + 1);

    Top *top1;
    Crawl("kokekrewrkwel",path,&top1);
    TopPrl *top2;
    CrawlPrl("kokekrewrkwel",path,&top2);
    ASSERT_EQ(top1[3].levDistValue, top2[3].levDistValue);
    free(top1);
    free(top2);
}

TEST(case5,test5){
    char *paths = get_current_dir_name();
    char *testFolder = (char*)"/files";
    int len = getLastOf(paths);
    char *path = (char*)malloc(sizeof(char) * (len + strlen(testFolder)));
    memcpy(path,paths,strlen(paths));
    memcpy((void*)(path + len),testFolder, len + strlen(testFolder) + 1);

    Top *top1;
    Crawl("kokekrewrkwel",path,&top1);
    TopPrl *top2;
    CrawlPrl("kokekrewrkwel",path,&top2);
    ASSERT_EQ(top1[4].levDistValue, top2[4].levDistValue);
    free(top1);
    free(top2);
}

TEST(case6,test6){
    char *paths = get_current_dir_name();
    char *testFolder = (char*)"/files";
    int len = getLastOf(paths);
    char *path = (char*)malloc(sizeof(char) * (len + strlen(testFolder)));
    memcpy(path,paths,strlen(paths));
    memcpy((void*)(path + len),testFolder, len + strlen(testFolder) + 1);

    Top *top1;
    Crawl("kokekrewrkwel",path,&top1);
    const char * t = "2.txt";
    ASSERT_EQ(*top1[3].fileName, *t);
    free(top1);
}

TEST(case7,test7){
    char *paths = get_current_dir_name();
    char *testFolder = (char*)"/files";
    int len = getLastOf(paths);
    char *path = (char*)malloc(sizeof(char) * (len + strlen(testFolder)));
    memcpy(path,paths,strlen(paths));
    memcpy((void*)(path + len),testFolder, len + strlen(testFolder) + 1);

    Top *top1;
    Crawl("kokekrewrkwel",path,&top1);
    const char * t = "10.txt";
    ASSERT_EQ(*top1[0].fileName, *t);
    free(top1);
}

TEST(case8,test8){
    char *paths = get_current_dir_name();
    char *testFolder = (char*)"/files";
    int len = getLastOf(paths);
    char *path = (char*)malloc(sizeof(char) * (len + strlen(testFolder)));
    memcpy(path,paths,strlen(paths));
    memcpy((void*)(path + len),testFolder, len + strlen(testFolder) + 1);

    TopPrl *top2;
    CrawlPrl("kokekrewrkwel",path,&top2);
    const char *t = "2.txt";
    ASSERT_EQ(*top2[3].fileName, *t);
    free(top2);
}

TEST(case9,test9){
    char *paths = get_current_dir_name();
    char *testFolder = (char*)"/files";
    int len = getLastOf(paths);
    char *path = (char*)malloc(sizeof(char) * (len + strlen(testFolder)));
    memcpy(path,paths,strlen(paths));
    memcpy((void*)(path + len),testFolder, len + strlen(testFolder) + 1);

    Top *top1;
    Crawl("kokekrewrkwel",path,&top1);
    const char *t = "4.txt";
    ASSERT_EQ(*top1[1].fileName, *t);
    free(top1);
}

TEST(case10,test10){
    char *paths = get_current_dir_name();
    char *testFolder = (char*)"/files";
    int len = getLastOf(paths);
    char *path = (char*)malloc(sizeof(char) * (len + strlen(testFolder)));
    memcpy(path,paths,strlen(paths));
    memcpy((void*)(path + len),testFolder, len + strlen(testFolder) + 1);

    TopPrl *top2;
    CrawlPrl("kokekrewrkwel",path,&top2);
    const char *t = "3.txt";
    ASSERT_EQ( *top2[4].fileName, *t);
    free(top2);
}
