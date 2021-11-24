/**
 * @file main.c
 * @author Prasant Soy (prasantyos@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-11-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h> ///for input output functions like printf, scanf
#include <stdlib.h>
#include <string.h>  ///string operations
#include "filer.h"
 

 
/** Main function started */
  
int main(){
    
    char choice;
    
    /** open the file in binary read and write mode
    * if the file EMP.DAT already exists then it open that file in read write mode
    * if the file doesn't exit it simply create a new copy
    */
    fp = fopen("EMP.DAT","rb+");
    if(fp == NULL){
        fp = fopen("EMP.DAT","wb+");
        if(fp == NULL){
            printf("Connot open file");
            exit(1);
        }
    }
  
    /// sizeo of each record i.e. size of structure variable e
    recsize = sizeof(e);
  
    /// infinite loop continues untile the break statement encounter
    while(1)
    {
        printf("1. Add Record\n"); /// option for add record
        printf("2. List Records\n"); /// option for showing existing record
        printf("3. Modify Records\n"); /// option for editing record
        printf("4. Delete Records\n"); /// option for deleting record
        printf("5. Exit\n"); /// exit from the program
        printf("Your Choice: "); /// enter the choice 1, 2, 3, 4, 5
        fflush(stdin); /// flush the input buffer
        scanf("\n%c", &choice); /// get the input from keyboard

        switch(choice)
        {
            
            case '1':

            add();  /// if user press 1

            break;

            case '2':

            list();
            
            break;

            case '3':  /// if user press 3 then do editing existing record
            
            modify();

            break;


            case '4':

            del();

                break;

            case '5':

                fclose(fp);  /// close the file
                exit(0); /// exit from the program
        }
    }
    return 0;
}