#include <stdio.h>
#include <stdlib.h>

int *create_array(int n)
{
    // Allocate memory for n integers
    int *arr = (int *)malloc(n * sizeof(int));

    // Check for allocation failure
    if (arr == NULL)
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    return arr;
}

void initialize_array(int *arr, int n)
{
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void print_array(int *arr, int n)
{
    printf("Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void delete_array(int **arr)
{
    // Double pointer: set original pointer to NULL after free
    if (*arr != NULL)
    {
        free(*arr);
        *arr = NULL; // Prevent dangling pointer
        printf("Memory freed safely.\n");
    }
}

int main()
{
    int n;
    int *dynamic_arr = NULL;

    printf("Enter array size: ");
    scanf("%d", &n);

    // Create dynamic array
    dynamic_arr = create_array(n);
    if (dynamic_arr == NULL)
    {
        printf("Cannot proceed - exiting.\n");
        return 1;
    }

    // Initialize
    initialize_array(dynamic_arr, n);

    // Display
    print_array(dynamic_arr, n);

    // Safe cleanup
    delete_array(&dynamic_arr);

    // Verify NULL
    if (dynamic_arr == NULL)
    {
        printf("No dangling pointers!\n");
    }

    return 0;
}
