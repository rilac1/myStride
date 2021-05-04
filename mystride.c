#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include "mystride_types.h"

int Stride(Process w[], int t[NUM][MAX]) {
    init_table(t);
    int stride[NUM];
    int remain[NUM];
    int pass_val[NUM];
    int arrive[NUM];
    int next, temp;
    int contextS = 0;
    for (int i=0; i<NUM; i++) {
        pass_val[i] = 1e9;
        arrive[i] = w[i].arrival_time;
        stride[i] = w[i].stride;
        remain[i] = w[i].service_time;
    }
    pass_val[find_min(arrive)] = 0;
    for(int run_time = 0; run_time < MAX; run_time++) {
        for (int i=0; i<NUM; i++)
            if (arrive[i] == run_time)
                pass_val[i] = pass_val[find_min(pass_val)];
        temp = next;
        next = find_min(pass_val);
        if (temp != next)
            contextS++;
        if (remain[next] == w[next].service_time)
            w[next].response_time = run_time;
        t[next][run_time] = 1;
        remain[next]--;
        if (remain[next]==0) {
            pass_val[next] = 1e8;
            w[next].end_time = run_time - w[next].arrival_time + contextS/10;;
        }
        pass_val[next] += stride[next];   
    }
    return contextS;
}

int myStride(Process w[], int t[NUM][MAX] ) {
    init_table(t);
    int stride[NUM];
    int remain[NUM];
    int pass_val[NUM];
    int arrive[NUM];
    int next, quantum, temp;
    int running = -1;
    int contextS = 0;

    for (int i=0; i<NUM; i++) {
        stride[i] = WEIGHT;
        remain[i] = w[i].service_time;
        arrive[i] = w[i].arrival_time;
        pass_val[i] = 1e8;
    }
    pass_val[find_min(arrive)] = WEIGHT;

    for(int run_time = 0; run_time < MAX; run_time++) {
        for (int i=0; i<NUM; i++)
            if (arrive[i] == run_time)
                pass_val[i] = pass_val[find_min(pass_val)] - WEIGHT;

        if (running<0) {
            temp = next;
            next = find_min(pass_val);
            if (temp != next)
                contextS++;
            if (remain[next] == w[next].service_time)
                w[next].response_time = run_time;
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
		        pass_val[next] = 1e8;
                w[next].end_time = run_time - w[next].arrival_time + contextS/10;
            }
            else if (running == quantum) {
                stride[next] += (running * WEIGHT);
                running = -1;
            }
        }
    }
    return contextS;
}

int find_min(int* arr) {
    int min = 1e8;
    int ret;
    for (int i=0; i<NUM; i++) {
        if (arr[i]<min) {
            min = arr[i];
            ret = i; 
        }
    }
    return ret;
}