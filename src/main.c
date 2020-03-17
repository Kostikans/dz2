#include "../include/libCrawlSequintally.h"
#include "../include/libCrawlParallel.h"
#include "time.h"

int main(){
    Top *top1 = NULL;
    clock_t begin = clock();
    Crawl("kokekrewrkwel","/home/kostikan/CLionProjects/dz2/files",&top1);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%f\n",time_spent);

    TopPrl *top2 = NULL;
    begin = clock();
    CrawlPrl("kokekrewrkwel","/home/kostikan/CLionProjects/dz2/files",&top2);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%f",time_spent);

    free(top1);
    free(top2);
    return 0;
}