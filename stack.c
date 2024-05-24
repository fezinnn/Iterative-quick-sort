#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

t_stack* create_stack(int n){
    t_stack *p = (t_stack *) malloc(sizeof(t_stack));
    p->max = n;
    p->items = (t_elem *) malloc(sizeof(t_elem) * n);
    p->top_index = -1;
    return p;
}

int is_full(t_stack *p){
    return p->top_index >= p->max - 1;
}

int is_empty(t_stack *p){
    return p->top_index == -1;
}

int push(t_stack *p, t_elem x){
    if(is_full(p)){
      return 0;  
    }
    
    p->top_index++;
    p->items[p->top_index] = x;

    return 1;
}

int pop(t_stack *p) {
    if (is_empty(p)) {
        return -1;
    }
    return p->items[(p->top_index)--];
}
