#include "gtest/gtest.h"

extern "C" {
    #include "../include/crawlSequintally.h"
#include "../include/crawlParallel.h"
}

TEST(case1,test1){
    Top *top1;
    Crawl("kokekrewrkwel","/home/kostikan/testDz1",&top1);
    TopPrl *top2;
    CrawlPrl("kokekrewrkwel","/home/kostikan/testDz1",&top2);
    ASSERT_EQ(top1[0].levDistValue, top2[0].levDistValue);
    free(top1);
    free(top2);
}

TEST(case2,test2){
    Top *top1;
    Crawl("kokekrewrkwel","/home/kostikan/testDz1",&top1);
    TopPrl *top2;
    CrawlPrl("kokekrewrkwel","/home/kostikan/testDz1",&top2);
    ASSERT_EQ(top1[1].levDistValue, top2[1].levDistValue);
    free(top1);
    free(top2);
}

TEST(case3,test3){
    Top *top1;
    Crawl("kokekrewrkwel","/home/kostikan/testDz1",&top1);
    TopPrl *top2;
    CrawlPrl("kokekrewrkwel","/home/kostikan/testDz1",&top2);
    ASSERT_EQ(top1[2].levDistValue, top2[2].levDistValue);
    free(top1);
    free(top2);
}

TEST(case4,test4){
    Top *top1;
    Crawl("kokekrewrkwel","/home/kostikan/testDz1",&top1);
    TopPrl *top2;
    CrawlPrl("kokekrewrkwel","/home/kostikan/testDz1",&top2);
    ASSERT_EQ(top1[3].levDistValue, top2[3].levDistValue);
    free(top1);
    free(top2);
}

TEST(case5,test5){
    Top *top1;
    Crawl("kokekrewrkwel","/home/kostikan/testDz1",&top1);
    TopPrl *top2;
    CrawlPrl("kokekrewrkwel","/home/kostikan/testDz1",&top2);
    ASSERT_EQ(top1[4].levDistValue, top2[4].levDistValue);
    free(top1);
    free(top2);
}

TEST(case6,test6){
    Top *top1;
    Crawl("kokekrewrkwel","/home/kostikan/testDz1",&top1);
    const char * t = "8.txt";
    ASSERT_EQ(*top1[3].fileName, *t);
    free(top1);
}

TEST(case7,test7){
    Top *top1;
    Crawl("kokekrewrkwel","/home/kostikan/testDz1",&top1);
    const char * t = "10.txt";
    ASSERT_EQ(*top1[0].fileName, *t);
    free(top1);
}

TEST(case8,test8){
    TopPrl *top2;
    CrawlPrl("kokekrewrkwel","/home/kostikan/testDz1",&top2);
    const char *t = "2.txt";
    ASSERT_EQ(*top2[2].fileName, *t);
    free(top2);
}

TEST(case9,test9){
    Top *top1;
    Crawl("kokekrewrkwel","/home/kostikan/testDz1",&top1);
    const char *t = "4.txt";
    ASSERT_EQ(*top1[1].fileName, *t);
    free(top1);
}

TEST(case10,test10){
    TopPrl *top2;
    CrawlPrl("kokekrewrkwel","/home/kostikan/testDz1",&top2);
    const char *t = "9.txt";
    ASSERT_EQ( *top2[4].fileName, *t);
    free(top2);
}
