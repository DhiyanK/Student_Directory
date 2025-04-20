#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    int rollNo;
    char name[50];
    int age;
    float marks;
};

int fun_choice();
void AddStudent(struct student *, int *, int);
void ViewStudent(struct student *, int);
void deleteStudent(struct student *, int *);
void searchStudent(struct student *, int);
void UpdateStudent(struct student *, int);

int main(void) {
    int num;
    printf("Enter the total number of students: ");
    scanf("%d", &num);

    struct student *s1;
    s1 = (struct student *)malloc(num * sizeof(struct student));
    if (s1 == NULL) {
        printf("Memory Allocation failed\n");
        return 1;
    }

    int student_count = 0;
    int choice;

    while (1) {
        choice = fun_choice();
        if (choice == 1) {
            AddStudent(s1, &student_count, num);
        } else if (choice == 2) {
            ViewStudent(s1, student_count);
        } else if (choice == 3) {
            searchStudent(s1, student_count);
        } else if (choice == 4) {
            UpdateStudent(s1, student_count);
        } else if (choice == 5) {
            deleteStudent(s1, &student_count);
        } else if (choice == 6) {
            printf("Exiting the program...\n");
            free(s1);
            return 0;
        } else {
            printf("Wrong Input\n");
        }
    }
    return 0;
}

// Menu function
int fun_choice() {
    int choice;
    printf("\n----- MENU -----\n");
    printf("1. Add Student\n");
    printf("2. View Students\n");
    printf("3. Search Student\n");
    printf("4. Update Student\n");
    printf("5. Delete Student\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Add a new student
void AddStudent(struct student *S, int *count, int max) {
    if (*count >= max) {
        printf("Cannot enter more students, maximum limit reached.\n");
        return;
    }

    printf("Enter the Roll No: ");
    scanf("%d", &S[*count].rollNo);
    printf("Enter the Name: ");
    scanf("%s", S[*count].name);
    printf("Enter the Age: ");
    scanf("%d", &S[*count].age);
    printf("Enter the Marks: ");
    scanf("%f", &S[*count].marks);

    (*count)++;
    printf("Student added successfully.\n");
}

// View all students
void ViewStudent(struct student *S, int count) {
    if (count == 0) {
        printf("No students to display.\n");
        return;
    }

    printf("\n=== Student List ===\n");
    for (int i = 0; i < count; i++) {
        printf("Student %d: Name: %s | Roll No: %d | Age: %d | Marks: %.2f\n",
               i + 1, S[i].name, S[i].rollNo, S[i].age, S[i].marks);
    }
}

// Search for a student
void searchStudent(struct student *s, int count) {
    if (count == 0) {
        printf("No students to search.\n");
        return;
    }

    int roll;
    printf("Enter the Roll No to search: ");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++) {
        if (s[i].rollNo == roll) {
            printf("Found: Name: %s | Roll No: %d | Age: %d | Marks: %.2f\n",
                   s[i].name, s[i].rollNo, s[i].age, s[i].marks);
            return;
        }
    }
    printf("Student with Roll No %d not found.\n", roll);
}

// Update a student's info
void UpdateStudent(struct student *s, int count) {
    if (count == 0) {
        printf("No students to update.\n");
        return;
    }

    int roll;
    printf("Enter Roll No to update: ");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++) {
        if (s[i].rollNo == roll) {
            printf("Enter new Name: ");
            scanf("%s", s[i].name);
            printf("Enter new Age: ");
            scanf("%d", &s[i].age);
            printf("Enter new Marks: ");
            scanf("%f", &s[i].marks);
            printf("Student updated successfully!\n");
            return;
        }
    }
    printf("Student with Roll No %d not found.\n", roll);
}

// Delete a student
void deleteStudent(struct student *s, int *count) {
    if (*count == 0) {
        printf("No students to delete.\n");
        return;
    }

    int roll;
    printf("Enter Roll No to delete: ");
    scanf("%d", &roll);

    for (int i = 0; i < *count; i++) {
        if (s[i].rollNo == roll) {
            for (int j = i; j < *count - 1; j++) {
                s[j] = s[j + 1]; // shift left
            }
            (*count)--;
            printf("Student deleted successfully!\n");
            return;
        }
    }
    printf("Student with Roll No %d not found.\n", roll);
}
