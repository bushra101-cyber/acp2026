#include <stdio.h>
#include <string.h>
void inputStrings(char str1[1000], char str2[1000])
{
    printf("Enter two words/sentences. \n");
    printf("Enter first string:");
    scanf("%999s", str1);
    printf("Enter second string:");
    scanf("%999s", str2);
}
int compareStrings(char str1[1000], char str2[1000])
{
    int result = strcmp(str1, str2);
    if (result == 0)
    {
        return 0;
    }
    else if (result > 0)
    {
        return 1;
    }
    else if (result < 0)
    {
        return -1;
    }
}
void outputStrings(int result)
{
    if (result == 0)
    {
        printf("Both strings are equal\n");
    }
    else if (result > 0)
    {
        printf("String 1 is lexicographically larger than String 2\n");
    }
    else if (result == -1)
    {
        printf("String 2 is lexicographically larger than String 1\n");
    }
}
int main()
{
    char strA[1000], strB[1000];
    int result;
    inputStrings(strA, strB);
    result = compareStrings(strA, strB);
    outputStrings(result);
    return 0;
}