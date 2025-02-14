#define MAX 10000

typedef struct {
    int stack[MAX];
    int sp;
} STACK;

STACK *new_stack();
void push(STACK *s, int n);
int pop(STACK *s);
