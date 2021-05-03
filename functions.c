#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include "mystride_types.h"

void print_result(Process w[], int p[][MAX]) {
    printf("   0");
    for (int i=5; i<=MAX; i+=5)
        printf("%20d", i);
    printf("\n   ");

    for (int i=0; i<MAX; i++)
        printf("|───");
    printf("│\n");

    for (int i=0; i<NUM; i++) {
        printf(" %c │", w[i].name);
        for (int j=0; j<MAX; j++)
            if (p[i][j])
                if (j%5==4)
                    printf("■■■│");
                else
                    printf("■■■■");
            else if (j%5==4)
                printf("   │");
            else
                printf("    ");
        printf("\n");
    }
}
