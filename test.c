#include <stdio.h>
#include <stdlib.h>

int main(){
    int* arr;
    arr = (int*)malloc(10*sizeof(int));
    printf("%p",&arr);
    return 0;
}