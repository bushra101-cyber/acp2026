#include <stdio.h>
#include <string.h>

void input(char *str)
{
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = 0; // Remove newline
}

void concatenate_strings(char *str1, char *str2)
{
    int i, j;

    // Find length of str1 using while loop
    i = 0;
    while (str1[i] != '\0')
    {
        i++;
    }

    // Copy str2 to end of str1 using do-while loop
    j = 0;
    do
    {
        str1[i + j] = str2[j];
        j++;
    } while (str2[j - 1] != '\0');

    str1[i + j - 1] = '\0'; // Null terminate result
}

void display(char *str)
{
    printf("Concatenated string: %s\n", str);
}

int main()
{
    char str1[100], str2[100];

    input(str1);
    input(str2);

    concatenate_strings(str1, str2);
    display(str1);

    return 0;
}