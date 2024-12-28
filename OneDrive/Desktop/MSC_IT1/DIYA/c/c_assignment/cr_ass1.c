#include <stdio.h>
#include <string.h>

typedef struct {
    int roll_number;
    char name[50];
    float marks[5];
    float total_marks;
    float percentage;
} Student;

void inputStudentData(Student students[], int num_students) {
    for (int i = 0; i < num_students; i++) {
        printf("Enter data for student %d:\n", i + 1);
        printf("Roll number: ");
        scanf("%d", &students[i].roll_number);
        getchar(); // Clear the newline character from input buffer

        printf("Name: ");
        fgets(students[i].name, sizeof(students[i].name), stdin);
        // Remove trailing newline if it exists
        size_t len = strlen(students[i].name);
        if (len > 0 && students[i].name[len - 1] == '\n') {
            students[i].name[len - 1] = '\0';
        }

        printf("Enter marks for 5 subjects:\n");
        for (int j = 0; j < 5; j++) {
            printf("Subject %d: ", j + 1);
            scanf("%f", &students[i].marks[j]);
        }
        printf("\n");
    }
}

void calculateResults(Student students[], int num_students) {
    for (int i = 0; i < num_students; i++) {
        students[i].total_marks = 0;
        for (int j = 0; j < 5; j++) {
            students[i].total_marks += students[i].marks[j];
        }
        students[i].percentage = (students[i].total_marks / 500) * 100;
    }
}

void printStudentData(Student students[], int num_students) {
    printf("\nStudent Data:\n");
    printf("-------------------------------------------------------------\n");
    printf("%-10s %-20s %-15s %-10s\n", "Roll No.", "Name", "Total Marks", "Percentage");
    printf("-------------------------------------------------------------\n");
    for (int i = 0; i < num_students; i++) {
        printf("%-10d %-20s %-15.2f %-10.2f%\n",
               students[i].roll_number,
               students[i].name,
               students[i].total_marks,
               students[i].percentage);
    }
}

int main() {
    int num_students;
    
    // Ask the user to input the number of students
    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    // Dynamically allocate memory for the students based on the user input
    Student students[num_students];

    inputStudentData(students, num_students);
    calculateResults(students, num_students);
    printStudentData(students, num_students);

    return 0;
}
