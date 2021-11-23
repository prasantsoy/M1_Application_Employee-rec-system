#include <stdio.h>
#include <string.h>
#include "filer.h"


void flush()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void add()
{
fseek(fp,0,SEEK_END); /// search the file and move cursor to end of the file
                                        /// here 0 indicates moving 0 distance from the end of the file
                another = 'y';
                while(another == 'y')
                {                                   /// if user want to add another record
                    flush();
                    printf("\nEnter name: ");
                    fgets(e.name, 40, stdin);
                    printf("\nEnter age: ");
                    scanf("%d", &e.age);
                    printf("\nEnter basic salary: ");
                    scanf("%f", &e.bs);
                    printf("\nEnter employee ID: ");
                    scanf("%d", &e.ID);
                    printf("Added successfully");
  
                    fwrite(&e,recsize,1,fp); /// write the record in the file
  
                    printf("\nAdd another record(y/n) ");
                    fflush(stdin);
                    scanf("\n%c", &another);
                }
}

void list()
{
    rewind(fp); ///this moves file cursor to start of the file
                while(fread(&e,recsize,1,fp)==1){ /// read the file and fetch the record one record per fetch
                    printf("\n%s %d %.2f %d\n",e.name,e.age,e.bs,e.ID); /// print the name, age, basic salary and ID
                }
}

void modify()
{
    another = 'y';
    int empid;
                while(another == 'y'){
                    printf("Enter the employee id to modify: ");
                    scanf("%d", &empid);
                    rewind(fp);
                    while(fread(&e,recsize,1,fp)==1)
                    { /// fetch all record from file
                        if(e.ID==empid)                                                //if(strcmp(e.name,empname)==0)
                        { ///if entered name matches with that in file
                            printf("\nEnter new name,age,bs and ID: ");
                            scanf("%s%d%f%d",e.name,&e.age,&e.bs,&e.ID);
                            //scanf("%d",&e.ID);
                            fseek(fp,-recsize,SEEK_CUR); /// move the cursor 1 step back from current position
                            fwrite(&e,recsize,1,fp); /// override the record
                            printf("Updated successfully");
                            break;
                            }
                        }
                        printf("\nModify another record(y/n)");
                        fflush(stdin);
                        scanf("\n%c", &another);
                    }
}

void del()
{
    another = 'y';
                while(another == 'y'){
                    flush();
                    printf("\nEnter name of employee to delete: ");
                    fgets(empname,40, stdin);
                    ft = fopen("Temp.dat","wb");  /// create a intermediate file for temporary storage
                    rewind(fp); /// move record to starting of file
                    while(fread(&e,recsize,1,fp) == 1){ /// read all records from file
                        if(strcmp(e.name,empname) != 0){ /// if the entered record match
                            fwrite(&e,recsize,1,ft); /// move all records except the one that is to be deleted to temp file
                        }
                    }
                    fclose(fp);
                    fclose(ft);
                    remove("EMP.DAT"); /// remove the orginal file
                    rename("Temp.dat","EMP.DAT"); /// rename the temp file to original file name
                    fp = fopen("EMP.DAT", "rb+");
                    printf("Delete another record(y/n)");
                    fflush(stdin);
                    scanf("\n%c", &another);
                }
}