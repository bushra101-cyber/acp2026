#include <stdio.h>
#include <string.h>
void inputStrings(char str1[], char str2[])
{
    printf("Enter first string : ");
    fgets(str1, 100, stdin);
    str1[strcspn(str1, "\n")] = 0; // Remove newline

    printf("Enter second string : ");
    fgets(str2, 100, stdin);
    str2[strcspn(str2, "\n")] = 0; // Remove newline
}
int compareStrings(char str1[], char str2[])
{
    int i = 0;

    while (str1[i] != '\0' && str2[i] != '\0')
    {
        if (str1[i] > str2[i])
        {
            return 1;
        }
        if (str1[i] < str2[i])
        {
            return -1;
        }
        i++;
    }

    if (str1[i] == '\0' && str2[i] == '\0')
    {
        return 0;
    }
    else if (str1[i] == '\0')
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

void output(int result)
{
    if (result == 0)
    {
        printf("String 1 is equal to String 2\n");
    }
    else if (result == 1)
    {
        printf("String 1 is lexicographically larger than String 2\n");
    }
    else
    {
        printf("String 2 is lexicographically larger than String 1\n");
    }
}

int main()
{
    char str1[100], str2[100];

    inputStrings(str1, str2);
    int result = compareStrings(str1, str2);
    output(result);

    return 0;
}