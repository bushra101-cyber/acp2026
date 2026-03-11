#include <stdio.h>
void input(int n, float arr[n]) // entering the array elements
{
    printf("Enter elements : \n");
    for (int i = 0; i < n; i++)
        scanf("%f", &arr[i]);
}
int find(int n, float arr[n]) // finding max value and index
{
    int max_index = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[max_index])
            max_index = i;
    }
    return max_index;
}
void output(float arr[], int max_index) // displaying result
{
    printf("max value = %.2f, index= %d\n", arr[max_index], max_index);
}
int main()
{
    int n, max_index;
    printf("Enter the number of elements:\n");
    scanf("%d", &n);
    float arr[n];
    input(n, arr); // calling the functions
    max_index = find(n, arr);
    output(arr, max_index);
    return 0;
}