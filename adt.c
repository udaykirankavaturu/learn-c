// abstract data type in c
// building an array
#include <stdio.h>
#include <stdlib.h>

// defining a structure
struct udayArray
{
    int total_size;
    int used_size;
    int *ptr;
};

void createArray(struct udayArray *a, int tSize, int uSize)
{
    a->total_size = tSize;
    a->used_size = uSize;
    a->ptr = (int *)malloc(tSize * sizeof(int));
}

void setVal(struct udayArray *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        /* code */
        printf("Enter element %d", i);
        scanf("%d", &a->ptr[i]);
    }
}

void show(struct udayArray *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        /* code */
        printf("%d\n", a->ptr[i]);
    }
}

int main()
{
    struct udayArray marks;
    createArray(&marks, 10, 2);
    setVal(&marks);
    show(&marks);
    return 0;
}