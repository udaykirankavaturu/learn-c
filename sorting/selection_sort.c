// implement selection sort algorithm

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

void selectionSort(int *array, int size)
{
    int minIndex;
    // loop for passes
    for (int i = 0; i < size - 1; i++)
    {
        minIndex = i;
        // loop for comparisons
        for (int j = i + 1; j < size; j++)
        {
            if (array[j] < array[minIndex])
            {
                // lower element found, update minIndex
                minIndex = j;
            }
        }
        // swap with minIndex
        int temp = array[i];
        array[i] = array[minIndex];
        array[minIndex] = temp;
    }
}

int main()
{
    // int array[] = {10, 3, 6, 8, 4, 1};
    // int array[] = {10, 7, 8, -12, 24, 6};
    int array[] = {1, 2, 3, 4, 5, 6};
    int size = 6;
    printArray(array, size);
    selectionSort(array, size);
    printArray(array, size);
    return 0;
}