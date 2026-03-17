#include <stdio.h>
typedef struct
{
    float length;
    float width;
    float area;
} Rectangle;
void input(int n, Rectangle rects[n])
{
    for (int i = 0; i < n; i++)
    {
        printf("Enter length and breadth of rectangle %d:\n", i + 1);
        scanf("%f%f", &rects[i].length, &rects[i].width);
    }
}
void calculate_area(int n, Rectangle rects[n])
{
    for (int i = 0; i < n; i++)
    {
        rects[i].area = rects[i].length * rects[i].width;
    }
}
int findLargestArea(int n, Rectangle rects[n])
{
    int largestIndex = 0;
    for (int i = 0; i < n; i++)
    {
        if (rects[i].area > largestIndex)
        {
            largestIndex = i;
        }
    }
    return largestIndex;
}
void output(int largestIndex, Rectangle rects[], int n)
{
    printf("Areas of rectangles: \n");
    for (int i = 0; i < n; i++)
    {
        printf("Rectangle %d area = %.2f\n", i + 1, rects[i].area);
    }
    printf("The rectangle %d at index %d is largest with area = %.2f.\n", largestIndex + 1, largestIndex, rects[largestIndex].area);
}
int main()
{
    int largestIndex, n;
    printf("Enter number of rectangles : \n");
    scanf("%d", &n);
    Rectangle rects[n];
    input(n, rects);
    calculate_area(n, rects);
    largestIndex = findLargestArea(n, rects);
    output(largestIndex, rects, n);
    return 0;
}