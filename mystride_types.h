#define MAX 20  // Max time
#define NUM 5 
#define WEIGHT 100

typedef struct {
    char name;
    int arrival_time;
    int service_time;
    int stride;
} Process;

void print_result(Process w[], int p[][MAX]);
void init_table(int t[NUM][MAX]);
void input_data(Process* w);

void Stride(Process *p, int t[NUM][MAX]);
void myStride(Process *p, int t[NUM][MAX]);
int find_min(int* arr);