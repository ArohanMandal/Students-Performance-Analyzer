#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

struct Student {
    int rollNumber;
    char name[50];

    float cProgramming;
    float mathematics;
    float physics;
    float english;
    float aiFundamentals;

    float total;
    float percentage;
};

struct Student students[MAX_STUDENTS];

int studentCount = 0;


void addStudent() {

    if (studentCount >= MAX_STUDENTS) {
        printf("\nStudent limit reached!\n");
        return;
    }

    struct Student newStudent;

    printf("\n===== ADD NEW STUDENT =====\n");

    printf("Enter Roll Number: ");
    scanf("%d", &newStudent.rollNumber);

    printf("Enter Student Name: ");
    scanf(" %[^\n]", newStudent.name);

    printf("\nEnter marks out of 100\n");

    printf("C Programming: ");
    scanf("%f", &newStudent.cProgramming);

    printf("Mathematics: ");
    scanf("%f", &newStudent.mathematics);

    printf("Physics: ");
    scanf("%f", &newStudent.physics);

    printf("English: ");
    scanf("%f", &newStudent.english);

    printf("AI Fundamentals: ");
    scanf("%f", &newStudent.aiFundamentals);


    newStudent.total =
        newStudent.cProgramming +
        newStudent.mathematics +
        newStudent.physics +
        newStudent.english +
        newStudent.aiFundamentals;


    newStudent.percentage = newStudent.total / 5;


    students[studentCount] = newStudent;

    studentCount++;

    printf("\nStudent added successfully!\n");
}


void viewStudents() {

    if (studentCount == 0) {
        printf("\nNo student records available.\n");
        return;
    }

    printf("\n===== STUDENT RECORDS =====\n");

    for (int i = 0; i < studentCount; i++) {

        printf("\nStudent %d\n", i + 1);

        printf("Roll Number: %d\n",
               students[i].rollNumber);

        printf("Name: %s\n",
               students[i].name);

        printf("C Programming: %.2f\n",
               students[i].cProgramming);

        printf("Mathematics: %.2f\n",
               students[i].mathematics);

        printf("Physics: %.2f\n",
               students[i].physics);

        printf("English: %.2f\n",
               students[i].english);

        printf("AI Fundamentals: %.2f\n",
               students[i].aiFundamentals);

        printf("Total Marks: %.2f / 500\n",
               students[i].total);

        printf("Percentage: %.2f%%\n",
               students[i].percentage);
    }
}


int main() {

    int choice;

    while (1) {

        printf("\n");
        printf("====================================\n");
        printf("   STUDENT PERFORMANCE ANALYZER\n");
        printf("====================================\n");

        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("0. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);


        switch (choice) {

            case 1:
                addStudent();
                break;

            case 2:
                viewStudents();
                break;

            case 0:
                printf("\nThank you for using the program!\n");
                return 0;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}