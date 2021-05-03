#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include "mystride_types.h"

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

