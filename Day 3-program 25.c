#include <stdio.h>

#define SIZE 100

void inArray(int * a, int size);
void printArray(int * a, int size);

int sortAscending(int * num1, int * num2);
int sortDescending(int * num1, int * num2);

void sort(int * a, int size, int (* compare)(int *, int *));



int main()
{
    int a[SIZE];
    int n;
    printf("Enter array size: ");
    scanf("%d", &n);
    printf("Enter elements in array: ");
    inArray(a, n);


    printf("\n\nElements before sorting: ");
    printArray(a, n);
    printf("\n\nArray in ascending order: ");
    sort(a, n, sortAscending);
    printArray(a, n);
    printf("\nArray in descending order: ");
    sort(a, n, sortDescending);
    printArray(a, n);

    
    return 0;
}
void inArray(int * arr, int size)
{
    int * arrEnd = (arr + size - 1);
    while(arr <= arrEnd)
        scanf("%d", arr++);
}
void printArray(int * arr, int size)
{
    int * arrEnd = (arr + size - 1);
    while(arr <= arrEnd)
        printf("%d, ", *(arr++));
}
int sortAscending(int * n1, int * n2)
{
    return (*n1) - (*n2);
}
int sortDescending(int * n1, int * n2)
{
    return (*n2) - (*n1);
}
void sort(int * arr, int size, int (* compare)(int *, int *))
{
    int * arrEnd  = (arr + size - 1);
    int * curElem = arr;
    int * elemToSort;
    while(curElem <= arrEnd)
    {
        elemToSort = curElem;
        while(elemToSort <= arrEnd)
        {
            if(compare(curElem, elemToSort) > 0)
            {
                *curElem    ^= *elemToSort;
                *elemToSort ^= *curElem;
                *curElem    ^= *elemToSort;
            }

            elemToSort++;
        }
        curElem++;
    }
}
