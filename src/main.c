#include "crawl.h"
#include "time.h"

int main(){
    Top *top1 = NULL;
    clock_t begin = clock();
    sequentialCrawl("kokekrewrkwel","/home/kostikan/testDz1",&top1);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%f\n",time_spent);

    Top *top2 = NULL;
    begin = clock();
    parallelCrawl("kokekrewrkwel","/home/kostikan/testDz1",&top2);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%f",time_spent);

    free(top1);
    free(top2);
    return 0;
};