#ifndef STACK_H
#define STACK_H

typedef int t_elem;

typedef struct{
    int max;
    int top_index;
    t_elem *items;
} t_stack;

t_stack* create_stack(int n);
int is_full(t_stack *p);
int is_empty(t_stack *p);
int push(t_stack *p, t_elem x);
int pop(t_stack *p);

#endif