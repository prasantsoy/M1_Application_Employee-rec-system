//#include "unity.h"
#include <stdio.h>


 /** structure that represent a employee */
struct emp{
        char name[40]; ///name of employee
        int age; /// age of employee
        float bs; /// basic salary of employee
        int ID;
    };
    struct emp e; /// structure variable creation
    FILE *fp, *ft; /// file pointers
    char another;
    long int recsize; /// size of each record of employee
    char empname[40]; /// string to store name of the employee

void add();
void list();
void modify();
void del();
void flush();