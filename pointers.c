#include <stdio.h>
// pointers

int main()
{
    int a = 10;
    int *ptr = &a;
    printf("%d\n", *ptr);
    printf("%p\n", (void *)ptr);
    printf("%p\n", (void *)&a);
    return 0;
}