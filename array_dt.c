// building a custom array data structure

#include <stdio.h>
#include <stdlib.h>

struct myArray
{
    int *ptr;
};

void createArray(struct myArray *a)
{
    a->ptr = (int *)malloc(10 * sizeof(int));
}

void setValue(struct myArray *a)
{

    for (int i = 0; i < 10; i++)
    {
        a->ptr[i] = i;
    }
}

void showArray(struct myArray *a)
{
    for (int i = 0; i < 10; i++)
    {
        /* code */
        printf("%d ", a->ptr[i]);
    }
}

int getValue(struct myArray *a, int index)
{
    return a->ptr[index];
}

int main()
{
    struct myArray arr;
    createArray(&arr);
    setValue(&arr);
    showArray(&arr);
    int value = getValue(&arr, 3);
    printf("\n%d", value);
    return 0;
}