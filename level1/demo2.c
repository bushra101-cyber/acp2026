#include <stdio.h>
typedef struct
{
    char name[50];
    float length;
    float width;
    float area;
} Rectangle;
Rectangle input()
{
    Rectangle rect;
    printf("Enter name:\n");
    scanf("%s", rect.name);
    printf("Enter length:\n");
    scanf("%f", &rect.length);
    printf("Enter width:\n");
    scanf("%f", &rect.width);
    return rect;
}
float calculate(Rectangle rect)
{
    return rect.length * rect.width;
}
void compare(Rectangle r1, Rectangle r2, Rectangle r3)
{
    printf("\nArea of %s, %s, %s = %.2f, %.2f, %.2f\n", r1.name, r2.name, r3.name, r1.area, r2.area, r3.area);

    if (r1.area > r2.area && r1.area > r3.area)
    {
        printf("\nLargest rectangle: %s\n", r1.name);
    }
    else if (r2.area > r1.area && r2.area > r3.area)
    {
        printf("\nLargest rectangle: %s\n", r2.name);
    }
    else if (r3.area > r1.area && r3.area > r2.area)
    {
        printf("\nLargest rectangle: %s\n", r3.name);
    }
    else
    {
        printf("\nTwo or more rectangles have equal largest area.\n");
    }
}
int main()
{
    Rectangle r1, r2, r3;
    r1 = input();
    r2 = input();
    r3 = input();
    r1.area = calculate(r1);
    r2.area = calculate(r2);
    r3.area = calculate(r3);
    compare(r1, r2, r3);
    return 0;
}