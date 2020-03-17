#include "../include/libCrawlSequintally.h"
#include "../include/libCrawlParallel.h"
#include "time.h"
#include "dirent.h"
#include <sys/stat.h>

int main(){
    mkdir("/home/kostikan/CLionProject/dz2/files", (__mode_t) NULL);
    FILE *mf = fopen("/home/kostikan/CLionProjects/dz2/files/1.txt","w");
    const char* s1 = "kostyarwerwekekewrwejklfjklsdjklfjdsmvnkltwejklnvdmsjrkqejfsd,jekljds,mklwrjkldf,gjwrekljmfdm";
    fprintf(mf,"%s", s1);
    fclose(mf);

    mf = fopen("/home/kostikan/CLionProjects/dz2/files/2.txt","w");
    const char* s2 = "kostyrewmr34,2mlmrel";
    fprintf(mf,"%s", s2);
    fclose(mf);

    mf = fopen("/home/kostikan/CLionProjects/dz2/files/3.txt","w");
    const char* s3 = "kostrekerdekw;le23ewekeerwe";
    fprintf(mf,"%s", s3);
    fclose(mf);

    mf = fopen("/home/kostikan/CLionProjects/dz2/files/4.txt","w");
    const char* s4 = "kosrmemwmkewrmwermw";
    fprintf(mf,"%s", s4);
    fclose(mf);

    mf = fopen("/home/kostikan/CLionProjects/dz2/files/5.txt","w");
    const char* s5 = "kokekrewrkwelewrternsdmnjk24h3jfnsmdjw4hfmsdkjth4wnfdsmntwhvmfds";
    fprintf(mf,"%s", s5);
    fclose(mf);

    mf = fopen("/home/kostikan/CLionProjects/dz2/files/6.txt","w");
    const char* s6 = "rewrlewrewkewrwe;l";
    fprintf(mf,"%s", s6);
    fclose(mf);

    mf = fopen("/home/kostikan/CLionProjects/dz2/files/7.txt","w");
    const char* s7 = "432ljefsfsdrklkl;ewkrwe";
    fprintf(mf,"%s", s7);
    fclose(mf);

    mf = fopen("/home/kostikan/CLionProjects/dz2/files/8.txt","w");
    const char* s8 = "trendf,nlktjtkjrelkfje";
    fprintf(mf,"%s", s8);
    fclose(mf);

    mf = fopen("/home/kostikan/CLionProjects/dz2/files/9.txt","w");
    const char* s9 = "dsncmxetreomngfdmngfffdsr43rirweffmdnmcxuweiorjvkcx";
    fprintf(mf,"%s", s9);
    fclose(mf);

    mf = fopen("/home/kostikan/CLionProjects/dz2/files/10.txt","w");
    const char* s10 = "kokekrewrkwel";
    fprintf(mf,"%s", s10);
    fclose(mf);

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