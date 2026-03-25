#include <stdio.h>
#include <stdlib.h>

struct Student
{
    int roll_no;
    char name[50];
    float marks;
};

void inputStudents(struct Student students[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &students[i].roll_no);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Marks: ");
        scanf("%f", &students[i].marks);
    }
}

void writeToTextFile(struct Student students[], int n, const char *filename)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("Error opening file %s for writing!\n", filename);
        return;
    }

    fprintf(file, "%d\n", n); // Write number of students first
    for (int i = 0; i < n; i++)
    {
        fprintf(file, "%d %s %.2f\n",
                students[i].roll_no,
                students[i].name,
                students[i].marks);
    }

    fclose(file);
    printf("Data written to %s successfully!\n", filename);
}

int readFromTextFile(struct Student students[], const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error opening file %s for reading!\n", filename);
        return 0;
    }

    int n;
    fscanf(file, "%d", &n); // Read number of students

    for (int i = 0; i < n; i++)
    {
        fscanf(file, "%d %s %f",
               &students[i].roll_no,
               &students[i].name,
               &students[i].marks);
    }

    fclose(file);
    return n;
}

void printStudents(struct Student students[], int n)
{
    printf("\n--- Student Records ---\n");
    printf("Roll No\tName\t\tMarks\n");
    printf("------\t----\t\t-----\n");

    for (int i = 0; i < n; i++)
    {
        printf("%6d\t%-15s\t%.2f\n", students[i].roll_no, students[i].name, students[i].marks);
    }
}

int main()
{
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student students1[100], students2[100];
    inputStudents(students1, n);
    writeToTextFile(students1, n, "students.txt");
    int read_count = readFromTextFile(students2, "students.txt");
    printf("\nOriginal array:\n");
    printStudents(students1, n);
    printf("\nRead from file array:\n");
    printStudents(students2, read_count);

    return 0;
}