#include "gtest/gtest.h"

extern "C" {
    #include "crawl.h"
}

TEST(case1,test1){
    Top *top1;
    sequentialCrawl("kokekrewrkwel","/home/kostikan/testDz1",&top1);
    Top *top2;
    parallelCrawl("kokekrewrkwel","/home/kostikan/testDz1",&top2);
    free(top1);
    free(top2);
}

TEST(case2,test2){
    Top *top1;
    sequentialCrawl("kokekrewrkwel","/home/kostikan/testDz1",&top1);
    Top *top2;
    parallelCrawl("kokekrewrkwel","/home/kostikan/testDz1",&top2);
    free(top1);
    free(top2);
}

TEST(case3,test3){
    Top *top1;
    sequentialCrawl("kokekrewrkwel","/home/kostikan/testDz1",&top1);
    Top *top2;
    parallelCrawl("kokekrewrkwel","/home/kostikan/testDz1",&top2);
    free(top1);
    free(top2);
}

TEST(case4,test4){
    Top *top1;
    sequentialCrawl("kokekrewrkwel","/home/kostikan/testDz1",&top1);
    Top *top2;
    parallelCrawl("kokekrewrkwel","/home/kostikan/testDz1",&top2);
    free(top1);
    free(top2);
}

TEST(case5,test5){
    Top *top1;
    sequentialCrawl("kokekrewrkwel","/home/kostikan/testDz1",&top1);
    Top *top2;
    parallelCrawl("kokekrewrkwel","/home/kostikan/testDz1",&top2);
    free(top1);
    free(top2);
}

TEST(case6,test6){
    Top *top1;
    sequentialCrawl("kokekrewrkwel","/home/kostikan/testDz1",&top1);
    Top *top2;
    parallelCrawl("kokekrewrkwel","/home/kostikan/testDz1",&top2);
    free(top1);
    free(top2);
}

TEST(case7,test7){
    Top *top1;
    sequentialCrawl("kokekrewrkwel","/home/kostikan/testDz1",&top1);
    Top *top2;
    parallelCrawl("kokekrewrkwel","/home/kostikan/testDz1",&top2);
    free(top1);
    free(top2);
}

TEST(case8,test8){
    Top *top1;
    sequentialCrawl("kokekrewrkwel","/home/kostikan/testDz1",&top1);
    Top *top2;
    parallelCrawl("kokekrewrkwel","/home/kostikan/testDz1",&top2);
    free(top1);
    free(top2);
}

TEST(case9,test9){
    Top *top1;
    sequentialCrawl("kokekrewrkwel","/home/kostikan/testDz1",&top1);
    Top *top2;
    parallelCrawl("kokekrewrkwel","/home/kostikan/testDz1",&top2);
    free(top1);
    free(top2);
}

TEST(case10,test10){
    Top *top1;
    sequentialCrawl("kokekrewrkwel","/home/kostikan/testDz1",&top1);
    Top *top2;
    parallelCrawl("kokekrewrkwel","/home/kostikan/testDz1",&top2);
    free(top1);
    free(top2);
}
