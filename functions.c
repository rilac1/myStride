#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include "mystride_types.h"

void experiment(int* cs, double* result) {
    for (int i=0; i<EXPERIMENT; i++) {
        Process workload1[NUM];
        Process workload2[NUM];
        int table[NUM][MAX];
        input_auto(workload1);
        copy_workload(workload1, workload2);
        input_stride(workload1);

        cs[0] += Stride(workload1, table);
        cs[1] += myStride(workload2, table);
        extract_data(result, workload1, workload2);
    }
    cs[0] /= EXPERIMENT;
    cs[1] /= EXPERIMENT;
    for (int i=0; i<4; i++)
        result[i] /= (double)EXPERIMENT;
}

void extract_data(double* result, Process w1[], Process w2[])  {
    int sum_result[4] = {0,};
    for (int i=0; i<NUM; i++) {
        sum_result[0] += w1[i].response_time;
        sum_result[1] += w2[i].response_time;
        sum_result[2] += w1[i].end_time;
        sum_result[3] += w2[i].end_time;
    }
    for (int i=0; i<4; i++)
        result[i] += (double)sum_result[i]/(double)NUM;
}


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

void print_data(int* cs, double* result) {
    printf("Total execution time: %d\n", MAX);
    printf("[Original Stride vs My stride]\n");
    printf("Context Switch: %d vs %d\n", cs[0], cs[1]);
    printf("Average response_time: %.3f vs %.3f\n", result[0], result[1]);
    printf("Average end_time: %.3f vs %.3f\n", result[2], result[3]);
}
