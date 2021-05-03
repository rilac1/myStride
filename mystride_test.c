#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include "mystride_types.h"

int main() {
    Process workload[NUM];
    int table[NUM][MAX];
    input_data(workload);

    Stride(workload, table);
    myStride(workload, table);
}