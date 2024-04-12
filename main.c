#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include "main.h"

int main()
{
    char option;

    while (1)
    {
        system("cls");
        printf("\t\t>>>>>>>>>>>>>>>>> Student Database System <<<<<<<<<<<<<<<<\n");
        printf("\n1. Add Student Database");
        printf("\n2. Display All Students Information");
        printf("\n3. Update/Edit Student Information");
        printf("\n4. Fill the presence or absence");
        printf("\n5. create the file of present students in school");
        printf("\n6. Create Standard wise file");
        printf("\n7. Save All Information in Text file");
        printf("\n0. Exit");

        printf("\n\n-->Enter Your Option: ");
        fflush(stdin);
        scanf(" %c", &option);

        switch (option)
        {
        case '1':
            add_database();
            break;
        case '2':
            display_info();
            break;
        case '3':
            update_info();
            break;
        case '4':
            fill_the_presence_or_absence();
            break;
        case '5':
            create_file_present_students_in_school();
            break;
        case '6':
            create_Standard_wise_file();
            break;
        case '7':
            save();
            break;
        case '0':
            printf("\n\t\t\t>>>>>>>>>>>>>>>>> Thank You <<<<<<<<<<<<<<<<");
            return 0;
            break;
        default:
            printf("\n\t\t\tInvalid Option, Please Enter Right Option !\n");
        }
    }
    return 0;
}