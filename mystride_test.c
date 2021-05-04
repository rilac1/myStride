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
    int a, b;

    input_auto(workload1);
    copy_workload(workload1, workload2);
    input_stride(workload1);

    print_workload(workload1);
    
    a = Stride(workload1, table);
    if (MAX<=45) {
        printf("\t 【Stride】\n");
        print_result(workload1, table);
    }
    b = myStride(workload2, table);
    if (MAX<=45) {
        printf("\t 【myStride】\n");
        print_result(workload2, table);
    }

    print_data(workload1, workload2, a, b);
}