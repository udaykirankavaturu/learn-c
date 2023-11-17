// implement insertion sort
#include <stdio.h>

void printArray(int *array, int size)
{
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf(" %d", array[i]);
    }
    printf("\n");
}

void insertionSort(int *array, int size)
{
    // loop for pass
    int key;
    int j;
    for (int i = 1; i < size; i++)
    {
        key = array[i];

        // using for loop
        for (j = i - 1; j >= 0 && array[j] > key; j--)
        {
            array[j + 1] = array[j];
        }

        // using while loop
        // j = i - 1;
        // while (j >= 0 && array[j] > key)
        // {
        //     array[j + 1] = array[j];
        //     j--;
        // }
        array[j + 1] = key;
    }
}

int main()
{
    int array[] = {10, 7, 8, -12, 24, 6};
    // int array[] = {1, 2, 3, 4, 5, 6};
    int size = 6;
    printArray(array, size);
    insertionSort(array, size);
    printArray(array, size);
    return 0;
}
