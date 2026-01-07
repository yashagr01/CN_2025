#include <stdio.h>
#include <string.h>

// Nested structure for Date of Birth
struct dob {
    int day;
    int month;
    int year;
};

// Structure for student information
struct student_info {
    int roll_no;
    char name[50];
    float CGPA;
    struct dob age;
};

// Function to print structure (call-by-value)
void display_by_value(struct student_info s) {
    printf("\n[Call-by-Value Function]");
    printf("\nRoll No: %d", s.roll_no);
    printf("\nName: %s", s.name);
    printf("\nCGPA: %.2f", s.CGPA);
    printf("\nDOB: %02d-%02d-%04d\n", s.age.day, s.age.month, s.age.year);
}

// Function to print structure (call-by-address)
void display_by_address(struct student_info *s) {
    printf("\n[Call-by-Address Function]");
    printf("\nRoll No: %d", s->roll_no);
    printf("\nName: %s", s->name);
    printf("\nCGPA: %.2f", s->CGPA);
    printf("\nDOB: %02d-%02d-%04d\n", s->age.day, s->age.month, s->age.year);
}

int main() {
    struct student_info student;

    // Assign values
    student.roll_no = 23052368;
    strcpy(student.name, "Yash Agarwal");
    student.CGPA = 8.56;
    student.age.day =05;
    student.age.month = 8;
    student.age.year = 2004;

    // Call both functions
    display_by_value(student);
    display_by_address(&student);

    return 0;
}

