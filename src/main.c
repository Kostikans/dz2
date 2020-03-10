#include "crawl.h"
#include "time.h"

int main(){
    clock_t begin = clock();
    sequentialCrawl("kokekrewrkwel","/home/kostikan/testDz1");
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%f\n",time_spent);

    begin = clock();
    parallelCrawl("kokekrewrkwel","/home/kostikan/testDz1");
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%f",time_spent);

    return 0;
};