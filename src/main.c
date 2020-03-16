#include "../include/crawlSequintally.h"
#include "../include/crawlParallel.h"
#include "time.h"

int main(){
    Top *top1 = NULL;
    clock_t begin = clock();
    Crawl("kokekrewrkwel","/home/kostikan/testDz1",&top1);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%f\n",time_spent);

    TopPrl *top2 = NULL;
    begin = clock();
    CrawlPrl("kokekrewrkwel","/home/kostikan/testDz1",&top2);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%f",time_spent);

    free(top1);
    free(top2);
    return 0;
}