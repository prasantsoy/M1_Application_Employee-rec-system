#include <stdio.h>

void addrecord()
{
    system("cls");
    fseek(fp, 0, SEEK_END);
    char another = 'y';
    while (another == 'y') {
        printf("\nEnter Name : ");
        scanf("%s", e.name);
        printf("\nEnter Age : ");
        scanf("%d", &e.age);
        printf("\nEnter Salary : ");
        scanf("%f", &e.salary);
        printf("\nEnter EMP-ID : ");
        scanf("%d", &e.id);
        fwrite(&e, size, 1, fp);
        printf("\nWant to add another"
               " record (Y/N) : ");
        fflush(stdin);
        scanf("%c", &another);
    }
}
void deleterecord()
{
    system("cls");
    char empname[50];
    char another = 'y';
    while (another == 'y') {
        printf("\nEnter employee "
               "name to delete : ");
        scanf("%s", empname);
        ft = fopen("temp.txt", "wb");
        rewind(fp);
        while (fread(&e, size,
                     1, fp)
               == 1) {
            if (strcmp(e.name,
                       empname)
                != 0)
                fwrite(&e, size, 1, ft);
        }
        fclose(fp);
        fclose(ft);
        remove("data.txt");
        rename("temp.txt", "data.txt");
        fp = fopen("data.txt", "rb+");
        printf("\nWant to delete another"
               " record (Y/N) :");
        fflush(stdin);
        another = getche();
    }
}

void displayrecord()
{
    system("cls");
    // sets pointer to start
    // of the file
    rewind(fp);
    printf("\n========================="
           "==========================="
           "======");
    printf("\nNAME\t\tAGE\t\tSALARY\t\t"
           "\tID\n",
           e.name, e.age,
           e.salary, e.id);
    printf("==========================="
           "==========================="
           "====\n");
    while (fread(&e, size, 1, fp) == 1)
        printf("\n%s\t\t%d\t\t%.2f\t%10d",
               e.name, e.age, e.salary, e.id);
    printf("\n\n\n\t");
    system("pause");
}

void modifyrecord()
{
    system("cls");
    char empname[50];
    char another = 'y';
  
    while (another == 'y') {
        printf("\nEnter employee name"
               " to modify : ");
        scanf("%s", empname);
        rewind(fp);
        // While File is open
        while (fread(&e, size, 1, fp) == 1) {
            // Compare the employee name
            // with ename
            if (strcmp(e.name, empname) == 0) {
                printf("\nEnter new name:");
                scanf("%s", e.name);
                printf("\nEnter new age :");
                scanf("%d", &e.age);
                printf("\nEnter new salary :");
                scanf("%f", &e.salary);
                printf("\nEnter new EMP-ID :");
                scanf("%d", &e.id);
  
                fseek(fp, -size, SEEK_CUR);
                fwrite(&e, size, 1, fp);
                break;
            }
        }
        // Ask for modifying another record
        printf("\nWant to modify another"
               " record (Y/N) :");
        fflush(stdin);
        scanf("%c", &another);
    }
}