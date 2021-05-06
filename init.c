#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include <math.h>
#include "mystride_types.h"

void input_auto(Process* w) {
    srand(time(NULL));
	int total = MAX;
	int weight = 10;
    int randTotal[NUM];
    int randAriv[NUM];
    int selected[NUM] = {0,};
    int next;
    randAriv[0] = 0;

   for (int i=0; i<NUM; i++) {
        if (i+1 == NUM) {
            randTotal[i] = total;
            randAriv[i] = 0;
        }
        else {
            randTotal[i]= rand()%(total/3+1) + rand()%(total/NUM+1) + 1;
            total -= randTotal[i];
            randAriv[i] = rand()%(MAX/4);
        }
        selected[i] = 1;


        w[i].ret_time = MAX / ((MAX/100)*(20/NUM)*(i+1));
    }

	for (int i=0; i<NUM; i++) {
        while(1) {
            next = rand()%NUM;
            if(selected[next]) break;
        }
		w[i].name = 'A'+i;
		w[i].arrival_time = randAriv[next];
		w[i].service_time = randTotal[next];
        w[i].end_time = 0;
        w[i].response_time = 0;

        selected[next]=0;
    }
}

void copy_workload(Process* w2, Process* w1) {
    Process temp[NUM];
    for (int i=0; i<NUM; i++) {
        w1[i].name = w2[i].name;
        w1[i].arrival_time = w2[i].arrival_time;
        w1[i].service_time = w2[i].service_time;
        w1[i].end_time = w2[i].end_time;
        w1[i].response_time = w2[i].response_time;
        w1[i].ret_time = w2[i].ret_time;
    }
}

void input_stride(Process* w) {
    srand(time(NULL));
    for (int i=0; i<NUM; i++)
        w[i].stride = rand()%9 + 1;
}

void init_table(int t[NUM][MAX]) {
    for (int i=0; i<NUM; i++)
        for (int j=0; j<MAX; j++)
            t[i][j]=0;
}

void input_my(Process* w) {
    w[0].name = 'C';
	w[0].arrival_time = 0;
	w[0].service_time = MAX*0.9;
    w[0].end_time = 0;
    w[0].response_time = 0;

    w[1].name = 'I';
	w[1].arrival_time = 0;
	w[1].service_time = MAX*0.1;
    w[1].end_time = 0;
    w[1].response_time = 0;
}
