#include <stdio.h>
// pointers

void main()
{
    int a = 10;
    int *ptr = &a;
    printf("%d\n", *ptr);
    printf("%p\n", (void *)ptr);
    printf("%p\n", (void *)&a);
}