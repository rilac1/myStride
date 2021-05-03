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
    input_auto(workload);

    print_workload(workload);
    Stride(workload, table);
    myStride(workload, table);
}