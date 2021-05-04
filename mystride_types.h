#define MAX 45  // Max time
#define NUM 5 
#define WEIGHT 100

typedef struct {
    char name;
    int arrival_time;
    int service_time;
    int stride;
    
    int contextS;
    int end_time[NUM];
    int reponse_time[NUM];
} Process;

void print_result(Process w[], int p[][MAX]);
void print_workload(Process w[]);

void init_table(int t[NUM][MAX]);
void input_data(Process* w);
void input_auto(Process* w);
void input_stride(Process* w);

void Stride(Process *p, int t[NUM][MAX]);
void myStride(Process *p, int t[NUM][MAX]);
int find_min(int* arr);