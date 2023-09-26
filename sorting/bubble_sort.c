// implement bubble sort

#include <stdio.h>

void printArray(int *array, int size)
{
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf(" %d", array[i]);
    }
}

void bubbleSort(int *array, int size)
{
    int isSortedArray = 1;
    for (int i = 0; i < size - 1; i++) // for each pass
    {
        for (int j = 0; j < size - 1 - i; j++) // for each comparison
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;

                isSortedArray = 0;
            }
        }
        if (isSortedArray)
        {
            printf("\n Array is already sorted!");
            return;
        }
    }
}

int main()
{
    int array[] = {10, 7, 2, 3, 9, 4};
    // int array[] = {1, 2, 3, 4, 5, 6, 7};
    int size = 6;
    printArray(array, size);
    bubbleSort(array, size);
    printArray(array, size);

    return 0;
}