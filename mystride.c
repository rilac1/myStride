#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include "mystride_types.h"

void Stride(Process w[], int t[NUM][MAX]) {
    init_table(t);
    int stride[NUM];
    int remain[NUM];
    int pass_val[NUM];
    for (int i=0; i<NUM; i++) {
        pass_val[i] = 0;
        stride[i] = w[i].stride;
        remain[i] = w[i].service_time;
    }

    for(int i = 0; i < MAX; i++) {
        int min_idx = 0;
        int min_pass = 1e9; //가장 작은 pass val 을 구하기위한 임의의 숫자

        /* 가장 작은 pass val을 가진 process의 i ndex 구하기*/
        for (int j = 0; j < NUM; j++) {
            if(pass_val[j] < min_pass && remain[j]>0) {
                min_pass = pass_val[j];
                min_idx = j;
            }
        }
        if (min_pass == 1e9) break;
        t[min_idx][i] = 1;
        remain[min_idx]--;
        pass_val[min_idx] += stride[min_idx];   
    }

    printf("\t 【Stride】\n");
    print_result(w, t);
}

void myStride(Process w[], int t[NUM][MAX] ) {
    init_table(t);
    int stride[NUM];
    int remain[NUM];
    int pass_val[NUM];
    int arrive[NUM];
    int next, quantum;
    int running = -1;

    for (int i=0; i<NUM; i++) {
        stride[i] = w[i].stride;
        remain[i] = w[i].service_time;
        arrive[i] = w[i].arrival_time;
        pass_val[i] = 1e9;
    }
    pass_val[find_min(arrive)] = WEIGHT;
    for(int run_time = 0; run_time < MAX; run_time++) {
        for (int i=0; i<NUM; i++)
            if (arrive[i] == run_time)
                pass_val[i] = pass_val[find_min(pass_val)] - WEIGHT;

        if (running<0) {
            next = find_min(pass_val);
            quantum = (stride[next] / WEIGHT);
            running = 0;
        }
        if (running>=0) {
            t[next][run_time] = 1;
            running++;
            remain[next]--;
            pass_val[next] += (running*WEIGHT);

            if(remain[next] == 0) {
                running = -1;
		        pass_val[next] = 1e9;
            }
            else if (running == quantum) {
                stride[next] += (running * WEIGHT);
                running = -1;
            }
        }
    }

    printf("\t 【My Stride】\n");
    print_result(w, t);
}

int find_min(int* arr) {
    int min = 1e9;
    int ret;
    for (int i=0; i<NUM; i++) {
        if (arr[i]<min) {
            min = arr[i];
            ret = i; 
        }
    }
    return ret;
}