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
    

    // Experiment Mode
    /*
    int cs[2] = {0,};
    double result[4] = {0,}; // av_res1, av_res2, av_end1, av_end2
    experiment(cs, result);
    print_data(cs, result);
    */
   

   // Compare "CPU bound vs IO bound"
   /*
    Process workload[NUM];
    int table[NUM][MAX];
    int cs[2] = {0,};
    input_my(workload);
    input_stride(workload);
    print_workload(workload);
    cs[0] = Stride(workload, table);
    cs[1] = myStride(workload, table);

    printf("%d %d\n", cs[0],cs[1]);
    */
}