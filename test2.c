#include <stdio.h>
#include <stdlib.h>

struct stack 
{
    int size;
    int top;
    // int* arr;
};

int main(){
    struct stack* s;
    s->top =  -1;
    s->size = 10;
    // s->arr = (int*)malloc(s->size*sizeof(int));
    printf("reached the end");
    return 0;
}