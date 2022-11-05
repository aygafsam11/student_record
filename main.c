#include <stdio.h>
#include <conio.h>

//Function
void addStudent();
void searchStudent();
void studentRecord();
void deleteStudent();
//Structure
struct student{
    char regNo[20];
    char firs_name[50];
    char last_name[50];
    char email[100];
    int phone;
    char level[10];
};
void main()
{
    int choice;
    while(choice != 5){
        printf(" \n");
        printf("\t\t\t\t------STUDENT MANAGEMENT RECORD------");
        printf("\n\n\n\t\t\t\t 1. Add Student Record\n");
        printf("\t\t\t\t 2. View Student Records\n");
        printf("\t\t\t\t 3. Search Student Records\n");
        printf("\t\t\t\t 4. Delete Student Records\n");
        printf("\t\t\t\t 5. Exit\n");
        printf("\t\t\t\t\ __________________________________\n");
        printf("\t\t\t\t\t ");
        scanf("%d", &choice);
    }
}
