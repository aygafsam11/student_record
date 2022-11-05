#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

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
    char dept[100];
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

        switch(choice){
    case 1:
        system("cls");
        addStudent();
        system("cls");
        break;
        }
    }
}

void addStudent(){
    char another;
    FILE *fp;
    struct student info;

    do{
        system("cls");
        printf("\t\t\t\t--------Add Student Info---------\n\n\n");
        fp = fopen("Student_info.txt","a");
        printf("\n\t\t\tEnter Registration Number : ");
        scanf("%s", &info.regNo);
        printf("\n\t\t\tEnter First name : ");
        scanf("%s", &info.firs_name);
        printf("\n\t\t\tEnter Last Name : ");
        scanf("%s", &info.last_name);
        printf("\n\t\t\tEnter Department : ");
        scanf("%s", &info.dept);
        printf("\n\t\t\tEnter Level : ");
        scanf("%s", &info.level);
        printf("\n\t\t\tEnter Email : ");
        scanf("%s", &info.email);
        printf("\n\t\t\tEnter Phone Number : ");
        scanf("%i", &info.phone);
        printf("\n\t\t\t______________________________\n");

        if(fp==NULL){
            fprintf(stderr,"\t\t\t Can't open file\n");
        }else{
            printf("\t\t\tStudent Record Stored Successfully.\n");
        }

        fwrite(&info,sizeof(struct student),1,fp);
        fclose(fp);

        printf("\t\t\tDo you want to add another record?(y/n) : ");
        scanf("&c",&another);

    }while(another=='y' || another=='Y');
}
