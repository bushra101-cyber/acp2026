#include <stdio.h>
void read_array(int n, int arr[])
{
    printf("Enter an array:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}
void print_array(int n, int arr[])
{
    printf("The array is : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void swap_array(int n, int a[n], int b[n])
{
    int temp[n];
    for (int i = 0; i < n; i++)
    {
        temp[i] = a[i];
        a[i] = b[i];
        b[i] = temp[i];
    }
}
int main()
{
    int n;
    printf("Enter array size : ");
    scanf("%d", &n);
    int arr1[n], arr2[n];
    printf("Read array 1:");
    read_array(n, arr1);
    printf("Read array 2:");
    read_array(n, arr2);
    printf("Before swap: \n");
    printf("Array 1 : ");
    print_array(n, arr1);
    printf("Array 2 : ");
    print_array(n, arr2);
    swap_array(n, arr1, arr2);
    printf("After swap : \n");
    printf("Array 1 :");
    print_array(n, arr1);
    printf("Array 2 : ");
    print_array(n, arr2);
    return 0;
}