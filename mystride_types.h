#define MAX 1000 // Max time
#define NUM 10
#define WEIGHT 100

typedef struct {
    char name;
    int arrival_time;
    int service_time;
    
    int end_time;
    int response_time;
    int stride;
} Process;

void print_result(Process w[], int p[][MAX]);
void print_data(Process w1[], Process w2[], int c1, int c2);
void print_workload(Process w[]);
void copy_workload(Process* w1, Process* w2);

void init_table(int t[NUM][MAX]);
void input_data(Process* w);
void input_auto(Process* w);
void input_stride(Process* w);

int Stride(Process *p, int t[NUM][MAX]);
int myStride(Process *p, int t[NUM][MAX]);
int find_min(int* arr);