// count sort
#include <stdio.h>
#include <stdlib.h>

void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int getMax(int *arr, int n)
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

void countSort(int *arr, int n)
{
    // find max
    int max = getMax(arr, n);

    // create sort array
    int *sort_array = (int *)malloc(sizeof(int) * (max + 1));

    // initialise sort array with zeroes
    for (int i = 0; i < max + 1; i++)
    {
        sort_array[i] = 0;
    }

    // traverse given array and update counts
    for (int i = 0; i < n; i++)
    {
        sort_array[arr[i]]++;
    }

    // traverse sort array and print
    for (int i = 0; i < max + 1; i++)
    {
        while (sort_array[i] > 0)
        {
            printf("%d ", i);
            sort_array[i]--;
        }
    }
}

int main()
{
    int arr[] = {5, 3, 4, 7, 8, 2, 4, 2, 3};
    int n = 9;
    countSort(arr, n);
    // print(arr, n);
    return 0;
}