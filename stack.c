#include <stdio.h>
#include <stdlib.h>

// define stack structure
struct Stack 
{
    int size;
    int top;
    int* arr;
};

void show(struct Stack* s)
{
    if(s->top == -1){
        printf("stack is empty");
    } else {
        for (int i = 0; i < s->size; i++)
        {
            printf("\n%d",s->arr[i]);
        }
        
    }
}

void push(struct Stack* s, int data){
    if(s->top == s->size-1){
        printf("\nstack overflow");
    }else {
        printf("\ntop value at entry %d",s->top);
        s->top = s->top+1;
        s->arr[s->top] = data;
    }
}

void pop(struct Stack* s){
    if(s->top == -1){
        printf("stack underflow");
    }else{
        printf("\npopped %d",s->arr[s->top]);
        s->arr[s->top] = NULL;
        s->top = s->top-1;
    }
}

int main(){
    struct Stack s;
    struct Stack* s_ptr = &s;
    s_ptr->top =  -1;
    s_ptr->size = 10;
    s_ptr->arr = (int *)malloc(s_ptr->size*sizeof(int));
    
    // show empty stack
    // show(s_ptr);

    // // add data to stack
    // s_ptr->arr[0] = 10;
    // s_ptr->top = s_ptr->top + 1;

    // show(s_ptr);

    push(s_ptr,10);
    push(s_ptr,20);
    push(s_ptr,30);
    push(s_ptr,40);
    push(s_ptr,50);
    push(s_ptr,60);
    push(s_ptr,70);
    push(s_ptr,80);
    push(s_ptr,90);
    push(s_ptr,100);
    push(s_ptr,110);

    // show full stack
    printf("\n showing full stack..");
    show(s_ptr);

    pop(s_ptr);
    pop(s_ptr);
    pop(s_ptr);

    // show remaining stack
    printf("\n showing remaining stack after popping..");
    show(s_ptr);

    printf("\nreached the end");
    return 0;
}