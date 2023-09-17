#include <stdio.h>

void insert(int arr[], int value, int index, int size)
{
    for (int i = size - 1; i >= index; i--)
    {
        /* code */
        arr[i + 1] = arr[i];
    }
    arr[index] = value;
}

void delete(int arr[], int index, int size)
{
    for (int i = index; i < size; i++)
    {
        /* code */
        arr[i] = arr[i + 1];
    }
}

void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        /* code */
        printf("%d ", arr[i]);
    }
    printf("\nprint completed\n");
}

int linearSearch(int arr[], int size, int search_value)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == search_value)
        {
            return i;
        }
    }
    // if not found
    return -1;
}

int binarySearch(int arr[], int size, int search_value)
{
    int low = 0;
    int high = size - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == search_value)
        {
            return mid;
        }
        else
        {
            if (search_value > arr[mid])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    int size = 100;
    int arr[100] = {};

    for (int i = 0; i < size; i++)
    {
        arr[i] = i + 1;
        printf("%d ", arr[i]);
    }

    // insert(arr, 10, 1, 5);
    // print(arr, 6);
    // delete (arr, 2, 6);
    // print(arr, 5);

    int search_value = 4;
    int index = binarySearch(arr, size, search_value);
    if (index >= 0)
    {
        printf("\n search value %d found at index %d", search_value, index);
    }
    else
    {
        printf("search value not found");
    }
    return 0;
}