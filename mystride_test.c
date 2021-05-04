#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include "mystride_types.h"

int main() {
    Process workload1[NUM];
    Process workload2[NUM];
    int table[NUM][MAX];

    input_auto(workload1);
    input_auto(workload2);

    input_stride(workload1);
    print_workload(workload1);
    
    Stride(workload1, table);
    myStride(workload2, table);
}