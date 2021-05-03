#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include "mystride_types.h"

void input_auto(Process* w) {
    srand(time(NULL));
	int total = MAX;
	int weight = 10;
    int randTotal[NUM];
    int randAriv[NUM];
    int selected[NUM];
    int next;
    randAriv[0] = 0;

    for (int i=0; i<NUM; i++) {
        if (i+1 == NUM) randTotal[i] = total;
        else {
            randTotal[i]= rand()%(total/2) + 1;
            total -= randTotal[i];
        }
        selected[i] = 1;
    }

    for (int i=1; i<NUM; i++)
        randAriv[i] = rand()%15;

	for (int i=0; i<NUM; i++) {
        while(1) {
            next = rand()%NUM;
            if(selected[next]) break;
        }
		w[i].name = 'A'+i;
		w[i].arrival_time = randAriv[next];
		w[i].service_time = randTotal[next];
        selected[next]=0;
    }
    input_stride(w);
}

void input_stride(Process* w) {
    for (int i=0; i<NUM; i++) w[i].stride = WEIGHT;
}

void input_data(Process* w) {
    w[0].name = 'A';
    w[0].arrival_time = 0;
    w[0].service_time = 3;
    w[0].stride = 100;

    w[1].name = 'B';
    w[1].arrival_time = 2;
    w[1].service_time = 6;
    w[1].stride = 100;

    w[2].name = 'C';
    w[2].arrival_time = 4;
    w[2].service_time = 4;
    w[2].stride = 100;

    w[3].name = 'D';
    w[3].arrival_time = 6;
    w[3].service_time = 5;
    w[3].stride = 100;

    w[4].name = 'E';
    w[4].arrival_time = 8;
    w[4].service_time = 2;
    w[4].stride = 100;
}

void init_table(int t[NUM][MAX]) {
    for (int i=0; i<NUM; i++)
        for (int j=0; j<MAX; j++)
            t[i][j]=0;
}

