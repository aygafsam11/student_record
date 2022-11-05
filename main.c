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
    char first_name[50];
    char last_name[50];
    char dept[100];
    char email[100];
    int phone[11];
    char level[5];
};
/**Main Function */
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
        case 2:
            system("cls");
            studentRecord();
            printf("\t\t\tPress any key to EXIT\n");
            getch();
            system("cls");
            break;
        }
    }
}

void addStudent(){
    char add;
    FILE *fp;
    struct student info;

    do{
        system("cls");
        printf("\t\t\t\t--------Add Student Info---------\n\n\n");
        fp = fopen("student_info.txt","a");
        printf("\n\t\t\tEnter Registration Number : ");
        scanf("%s", &info.regNo);
        printf("\n\t\t\tEnter First name : ");
        scanf("%s", &info.first_name);
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
        printf("\n\t\t\t__________________________\n");

        if(fp==NULL){
            fprintf(stderr,"\t\t\t Can't open file\n");
        }else{
            printf("\t\t\t Student Record Stored Successfully.\n");
        }

        fwrite(&info, sizeof(struct student),1,fp);
        fclose(fp);

        printf("\t\t\t Do you want to add another record?(y/n) : ");
        scanf("&s",&add);

    }while(add=='y' || add=='Y');
}

void studentRecord(){
    FILE *fp;
    struct student info;
    fp = fopen("student_info.txt", "r");

    printf("\t\t\t\t----------Student Records------------\n\n\n");

    if(fp==NULL){
        fprintf(stderr, "\t\t\t\tCan't open file\n");
    }else{
            printf("\t\t\t\tStudent Records\n");
            printf("\t\t\t\t________________\n\n");
        }
    while(fread(&info, sizeof(struct student),1,fp)){
        printf("\n\t\t\t\tStudent Registration Number : %s", info.regNo);
        printf("\n\t\t\t\tStudent FullName : %s %s", info.first_name, info.last_name);
        printf("\n\t\t\t\tStudent Department : %s", info.dept);
        printf("\n\t\t\t\tStudent Level : %s", info.level);
        printf("\n\t\t\t\tStudent Email Address : %s", info.email);
        printf("\n\t\t\t\tStudent Phone Number : %i", info.phone);
        printf("\n\t\t\t\t_______________________________\n");
    }
    fclose(fp);
    getch();
}
