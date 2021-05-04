#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include "mystride_types.h"

void print_result(Process w[], int p[][MAX]) {
    printf("   0");
    for (int i=5; i<=MAX; i+=5)
        printf("%20d", i);
    printf("\n   ");

    for (int i=0; i<MAX; i++)
        printf("|───");
    printf("│\n");

    for (int i=0; i<NUM; i++) {
        printf(" %c │", w[i].name);
        for (int j=0; j<MAX; j++)
            if (p[i][j])
                if (j%5==4)
                    printf("■■■│");
                else
                    printf("■■■■");
            else if (j%5==4)
                printf("   │");
            else
                printf("    ");
        printf("\n");
    }
}

void print_workload(Process w[]) {
    printf("     Arrival        Service       Stride\n");
    for (int i=0; i<NUM; i++)
        printf("%c: %10d  %10d  %10d\n", w[i].name, w[i].arrival_time, w[i].service_time, w[i].stride*100);
}

void print_data(Process w1[], Process w2[], int c1, int c2) {
    double av_end1, av_res1, av_end2, av_res2, temp;
    int sum_end1, sum_end2, sum_res1, sum_res2;
    sum_end1=sum_end2=sum_res1=sum_res2=0;
    for (int i=0; i<NUM; i++) {
        sum_end1 += w1[i].end_time;
        sum_end2 += w2[i].end_time;
        sum_res1 += w1[i].response_time;
        sum_res2 += w2[i].response_time;
    }
    temp = (double)NUM;
    printf("[Original Stride vs My stride]\n");
    printf("Context Switch: %d vs %d\n", c1, c2);
    printf("Average response_time: %.3f vs %.3f\n", sum_res1/temp, sum_res2/temp);
    printf("Average end_time: %.3f vs %.3f\n", sum_end1/temp, sum_end2/temp);
}
