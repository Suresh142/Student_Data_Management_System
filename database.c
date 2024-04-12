#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include "main.h"

void add_database()
{
    FILE *fileOne = fopen("Master.txt", "ab+");

    if (fileOne == NULL)
    {
        printf("\n\t\t\tError !\n");
    }

    Student stundentInformation;

    system("cls");

    printf("\t\t\t>>>>>>>>>>>>>>>>> Create Student Account <<<<<<<<<<<<<<<<\n");

    printf("\n\t\t\tEnter Student's First Name : ");
    getchar();
    gets(stundentInformation.firstName);
    printf("\t\t\tEnter Student's last Name : ");
    gets(stundentInformation.lastName);
    // Calculate roll number (auto-increment)
    fseek(fileOne, 0, SEEK_END);
    long fileSize = ftell(fileOne);
    itoa((fileSize / sizeof(stundentInformation)) + 1, stundentInformation.rollNo, 10);
    printf("\t\t\tEnter Student Standard(1...10) : ");
    gets(stundentInformation.standard);
    printf("\t\t\tEnter Student Class(A...D) : ");
    gets(stundentInformation.class);
    printf("\t\t\tEnter Student's E-Mail Id without @gmail.com : ");
    gets(stundentInformation.email);
    strcat(stundentInformation.email, "@gmail.com");
    strcpy(stundentInformation.attendance, "NA");

    fwrite(&stundentInformation, sizeof(stundentInformation), 1, fileOne);

    printf("\n\n\t\t\tInformations have been stored sucessfully\n");
    printf("\n\n\t\t\tEnter any keys to continue.......");
    getch();

    fclose(fileOne);
}

void display_info()
{
    FILE *fileOne = fopen("Master.txt", "rb");

    if (fileOne == NULL)
    {
        printf("\n\t\t\tError !\n");
    }

    Student stundentInformation;

    system("cls");

    printf("\t\t\t\t>>>>>>>>>>>>>>>>> All Students Information <<<<<<<<<<<<<<<<\n");

    printf("\n\n\t\t%-10s%-15s%-15s%-10s%-10s%-30s%-15s\n", "Roll No.", "First_Name", "Last_Name", "Standard", "Class", "E-Mail Id", "Attendence");
    printf("\t\t-----------------------------------------------------------------------------------------------------------");

    while (fread(&stundentInformation, sizeof(stundentInformation), 1, fileOne) == 1)
    {
        printf("\n\n\t\t%-10s%-15s%-15s%-10s%-10s%-35s%-15s", stundentInformation.rollNo, stundentInformation.firstName, stundentInformation.lastName, stundentInformation.standard, stundentInformation.class, stundentInformation.email, stundentInformation.attendance);
    }

    printf("\n\n\t\tEnter any keys to continue.......");
    getch();

    fclose(fileOne);
}

void update_info()
{
    FILE *fileOne = fopen("Master.txt", "rb");
    FILE *temp = fopen("temp.txt", "wb");

    Student studentInformation, tempInformation;

    int choice, flag = 0;

    if (fileOne == NULL || temp == NULL)
    {
        printf("\n\t\t\tError !\n");
    }

    system("cls");

    printf("\t\t\t\t>>>>>>>>>>>>>>>>> Update/Edit Students Information <<<<<<<<<<<<<<<<\n");
    int option;
    printf("\n\t\t\t1.Student's Roll No.\n\t\t\t2.Student's First_Name No.\n\t\t\t3.Student's Email-Id\n\n\tSelect Option : ");
    scanf("%d", &option);
    getchar();
    printf("\t\t\tProvide info. to search the selected option : ");
    switch (option)
    {
    case 1:
        strcpy(tempInformation.rollNo, "\n");
        gets(tempInformation.rollNo);
        break;
    case 2:
        strcpy(tempInformation.firstName, "\n");
        gets(tempInformation.firstName);
        break;
    case 3:
        strcpy(tempInformation.email, "\n");
        gets(tempInformation.email);
        break;
    default:
        printf("Invalid Option.....!");
        break;
    }

    while (fread(&studentInformation, sizeof(studentInformation), 1, fileOne) == 1)
    {
        if (strcmp(studentInformation.rollNo, tempInformation.rollNo) == 0)
        {
            flag++;
            printf("\n\t\t\tChoose your option :\n\t\t\t1.Update Student First_Name\n\t\t\t2.Update Student last_Name\n\t\t\t3.Update Student Standard\n\t\t\t4.Update Student Class\n\t\t\t5.Update Student  E-mail Id\n\t\t\t6.Update Student Attendence");
            printf("\n\n\t\t\tEnter Your Option : ");
            scanf("%d", &choice);
            if (choice == 1)
            {
                printf("\n\t\t\tEnter Student's First_Name to Update: ");
                getchar();
                gets(tempInformation.firstName);
                strcpy(studentInformation.firstName, tempInformation.firstName);

                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
                printf("\n\n\t\t\tUpdated successfully!\n\n");
            }
            else if (choice == 2)
            {
                printf("\n\t\t\tEnter Student's last_Name to Update: ");
                getchar();
                gets(tempInformation.lastName);
                strcpy(studentInformation.lastName, tempInformation.lastName);

                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
                printf("\n\n\t\t\tUpdated successfully!\n\n");
            }
            else if (choice == 3)
            {
                printf("\n\t\t\tEnter Student's Standard to Update: ");
                getchar();
                gets(tempInformation.standard);
                strcpy(studentInformation.standard, tempInformation.standard);

                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
                printf("\n\n\t\t\tUpdated successfully!\n\n");
            }
            else if (choice == 4)
            {
                printf("\n\t\t\tEnter Student's Class to Update: ");
                getchar();
                gets(tempInformation.class);
                strcpy(studentInformation.class, tempInformation.class);

                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
                printf("\n\n\t\t\tUpdated successfully!\n\n");
            }
            else if (choice == 5)
            {
                printf("\n\t\t\tEnter Student's Class to Update: ");
                getchar();
                gets(tempInformation.email);
                strcpy(studentInformation.email, tempInformation.email);

                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
                printf("\n\n\t\t\tUpdated successfully!\n\n");
            }
            else if (choice == 6)
            {
                printf("\n\t\t\tEnter Student's Attendence to Update: ");
                getchar();
                gets(tempInformation.attendance);
                strcpy(studentInformation.attendance, tempInformation.attendance);

                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
                printf("\n\n\t\t\tUpdated successfully!\n\n");
            }
            else
            {
                printf("\n\t\t\tInvalid Option.");
                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
            }
        }
        else if (strcmp(studentInformation.firstName, tempInformation.firstName) == 0)
        {
            flag++;
            printf("\n\t\t\tChoose your option :\n\t\t\t1.Update Student First_Name\n\t\t\t2.Update Student last_Name\n\t\t\t3.Update Student Standard\n\t\t\t4.Update Student Class\n\t\t\t5.Update Student  E-mail Id\n\t\t\t6.Update Student Attendence");
            printf("\n\n\t\t\tEnter Your Option : ");
            scanf("%d", &choice);
            if (choice == 1)
            {
                printf("\n\t\t\tEnter Student's First_Name to Update: ");
                getchar();
                gets(tempInformation.firstName);
                strcpy(studentInformation.firstName, tempInformation.firstName);

                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
                printf("\n\n\t\t\tUpdated successfully!\n\n");
            }
            else if (choice == 2)
            {
                printf("\n\t\t\tEnter Student's last_Name to Update: ");
                getchar();
                gets(tempInformation.lastName);
                strcpy(studentInformation.lastName, tempInformation.lastName);

                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
                printf("\n\n\t\t\tUpdated successfully!\n\n");
            }
            else if (choice == 3)
            {
                printf("\n\t\t\tEnter Student's Standard to Update: ");
                getchar();
                gets(tempInformation.standard);
                strcpy(studentInformation.standard, tempInformation.standard);

                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
                printf("\n\n\t\t\tUpdated successfully!\n\n");
            }
            else if (choice == 4)
            {
                printf("\n\t\t\tEnter Student's Class to Update: ");
                getchar();
                gets(tempInformation.class);
                strcpy(studentInformation.class, tempInformation.class);

                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
                printf("\n\n\t\t\tUpdated successfully!\n\n");
            }
            else if (choice == 5)
            {
                printf("\n\t\t\tEnter Student's Class to Update: ");
                getchar();
                gets(tempInformation.email);
                strcpy(studentInformation.email, tempInformation.email);

                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
                printf("\n\n\t\t\tUpdated successfully!\n\n");
            }
            else if (choice == 6)
            {
                printf("\n\t\t\tEnter Student's Attendence to Update: ");
                getchar();
                gets(tempInformation.attendance);
                strcpy(studentInformation.attendance, tempInformation.attendance);

                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
                printf("\n\n\t\t\tUpdated successfully!\n\n");
            }
            else
            {
                printf("\n\t\t\tInvalid Option.");
                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
            }
        }
        else if (strcmp(studentInformation.email, tempInformation.email) == 0)
        {
            flag++;
            printf("\n\t\t\tChoose your option :\n\t\t\t1.Update Student First_Name\n\t\t\t2.Update Student last_Name\n\t\t\t3.Update Student Standard\n\t\t\t4.Update Student Class\n\t\t\t5.Update Student  E-mail Id\n\t\t\t6.Update Student Attendence");
            printf("\n\n\t\t\tEnter Your Option : ");
            scanf("%d", &choice);
            if (choice == 1)
            {
                printf("\n\t\t\tEnter Student's First_Name to Update: ");
                getchar();
                gets(tempInformation.firstName);
                strcpy(studentInformation.firstName, tempInformation.firstName);

                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
                printf("\n\n\t\t\tUpdated successfully!\n\n");
            }
            else if (choice == 2)
            {
                printf("\n\t\t\tEnter Student's last_Name to Update: ");
                getchar();
                gets(tempInformation.lastName);
                strcpy(studentInformation.lastName, tempInformation.lastName);

                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
                printf("\n\n\t\t\tUpdated successfully!\n\n");
            }
            else if (choice == 3)
            {
                printf("\n\t\t\tEnter Student's Standard to Update: ");
                getchar();
                gets(tempInformation.standard);
                strcpy(studentInformation.standard, tempInformation.standard);

                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
                printf("\n\n\t\t\tUpdated successfully!\n\n");
            }
            else if (choice == 4)
            {
                printf("\n\t\t\tEnter Student's Class to Update: ");
                getchar();
                gets(tempInformation.class);
                strcpy(studentInformation.class, tempInformation.class);

                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
                printf("\n\n\t\t\tUpdated successfully!\n\n");
            }
            else if (choice == 5)
            {
                printf("\n\t\t\tEnter Student's Class to Update: ");
                getchar();
                gets(tempInformation.email);
                strcpy(studentInformation.email, tempInformation.email);

                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
                printf("\n\n\t\t\tUpdated successfully!\n\n");
            }
            else if (choice == 6)
            {
                printf("\n\t\t\tEnter Student's Attendence to Update: ");
                getchar();
                gets(tempInformation.attendance);
                strcpy(studentInformation.attendance, tempInformation.attendance);

                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
                printf("\n\n\t\t\tUpdated successfully!\n\n");
            }
            else
            {
                printf("\n\t\t\tInvalid Option.");
                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
            }
        }
        else
        {
            fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
        }
    }

    fclose(fileOne);
    fclose(temp);

    remove("Master.txt");
    rename("temp.txt", "Master.txt");

    if (flag == 0)
    {
        printf("\n\t\t\tStudent Roll No./First Name/E-mail Id is not found");
    }

    printf("\n\n\t\t\tEnter any keys to continue.......");
    getch();
}

void create_Standard_wise_file()
{
    system("cls");

    printf("\t\t\t\t>>>>>>>>>>>>>>>>> Create_Standard_wise_file <<<<<<<<<<<<<<<<\n");
    FILE *class_ptr, *fileOne = fopen("Master.txt", "rb");
    if (fileOne == NULL)
    {
        printf("Error in File opening");
        exit(0);
    }

    Student studentInformation;
    static int c1 = 1, c2 = 1, c3 = 1, c4 = 1, c5 = 1, c6 = 1, c7 = 1, c8 = 1, c9 = 1, c10 = 1;
    char C1 = 'O', C2 = 'O', C3 = 'O', C4 = 'O', C5 = 'O', C6 = 'O', C7 = 'O', C8 = 'O', C9 = 'O', C10 = 'O';
    char *class[20] = {"Standard_1.txt", "Standard_2.txt", "Standard_3.txt", "Standard_4.txt", "Standard_5.txt", "Standard_6.txt", "Standard_7.txt", "Standard_8.txt", "Standard_9.txt", "Standard_10.txt"};
    for (int i = 0; i < 10; i++)
    {
        remove(class[i]);
    }
    while (fread(&studentInformation, sizeof(studentInformation), 1, fileOne) == 1)
    {
        if (strcmp(studentInformation.standard, "1") == 0)
        {
            class_ptr = fopen(class[0], "ab+");
            if (class_ptr == NULL)
            {
                printf("Error in File opening");
                exit(0);
            }
            if (C1 == 'O')
            {
                C1 = 'O';
                fprintf(class_ptr, "Time : %s\nDate : %s\n\n", __TIME__, __DATE__);
                fprintf(class_ptr, "%-10s%-15s%-15s%-4s/%-4s   %-15s\n", "Roll No.", "First_Name", "Last_Name", "Std.", "Cls", "Attendence");
            }
            fprintf(class_ptr, "%-10d%-15s%-15s%s/%s   %13s\n", c1++, studentInformation.firstName, studentInformation.lastName, studentInformation.standard, studentInformation.class, studentInformation.attendance);
        }
        else if (strcmp(studentInformation.standard, "2") == 0)
        {
            class_ptr = fopen(class[1], "ab+");
            if (class_ptr == NULL)
            {
                printf("Error in File opening");
                exit(0);
            }
            if (C2 == 'O')
            {
                C2 = 'O';
                fprintf(class_ptr, "Time : %s\nDate : %s\n\n", __TIME__, __DATE__);
                fprintf(class_ptr, "%-10s%-15s%-15s%-4s/%-4s   %-15s\n", "Roll No.", "First_Name", "Last_Name", "Std.", "Cls", "Attendence");
            }
            fprintf(class_ptr, "%-10d%-15s%-15s%s/%s   %13s\n", c10++, studentInformation.firstName, studentInformation.lastName, studentInformation.standard, studentInformation.class, studentInformation.attendance);
        }
        else if (strcmp(studentInformation.standard, "3") == 0)
        {
            class_ptr = fopen(class[2], "ab+");
            if (class_ptr == NULL)
            {
                printf("Error in File opening");
                exit(0);
            }
            if (C3 == 'O')
            {
                C3 = 'O';
                fprintf(class_ptr, "Time : %s\nDate : %s\n\n", __TIME__, __DATE__);
                fprintf(class_ptr, "%-10s%-15s%-15s%-4s/%-4s   %-15s\n", "Roll No.", "First_Name", "Last_Name", "Std.", "Cls", "Attendence");
            }
             fprintf(class_ptr, "%-10d%-15s%-15s%s/%s   %13s\n", c10++, studentInformation.firstName, studentInformation.lastName, studentInformation.standard, studentInformation.class, studentInformation.attendance);
        }
        else if (strcmp(studentInformation.standard, "4") == 0)
        {
            class_ptr = fopen(class[3], "ab+");
            if (class_ptr == NULL)
            {
                printf("Error in File opening");
                exit(0);
            }
            if (C4 == 'O')
            {
                C4 = 'O';
                fprintf(class_ptr, "Time : %s\nDate : %s\n\n", __TIME__, __DATE__);
                fprintf(class_ptr, "%-10s%-15s%-15s%-4s/%-4s   %-15s\n", "Roll No.", "First_Name", "Last_Name", "Std.", "Cls", "Attendence");
            }
             fprintf(class_ptr, "%-10d%-15s%-15s%s/%s   %13s\n", c10++, studentInformation.firstName, studentInformation.lastName, studentInformation.standard, studentInformation.class, studentInformation.attendance);
        }
        else if (strcmp(studentInformation.standard, "5") == 0)
        {
            class_ptr = fopen(class[4], "ab+");
            if (class_ptr == NULL)
            {
                printf("Error in File opening");
                exit(0);
            }
            if (C5 == 'O')
            {
                C5 = 'O';
                fprintf(class_ptr, "Time : %s\nDate : %s\n\n", __TIME__, __DATE__);
                fprintf(class_ptr, "%-10s%-15s%-15s%-4s/%-4s   %-15s\n", "Roll No.", "First_Name", "Last_Name", "Std.", "Cls", "Attendence");
            }
            fprintf(class_ptr, "%-10d%-15s%-15s%s/%s   %13s\n", c10++, studentInformation.firstName, studentInformation.lastName, studentInformation.standard, studentInformation.class, studentInformation.attendance);
        }
        else if (strcmp(studentInformation.standard, "6") == 0)
        {
            class_ptr = fopen(class[5], "ab+");
            if (class_ptr == NULL)
            {
                printf("Error in File opening");
                exit(0);
            }
            if (C6 == 'O')
            {
                C6 = 'O';
                fprintf(class_ptr, "Time : %s\nDate : %s\n\n", __TIME__, __DATE__);
                fprintf(class_ptr, "%-10s%-15s%-15s%-4s/%-4s   %-15s\n", "Roll No.", "First_Name", "Last_Name", "Std.", "Cls", "Attendence");
            }
            fprintf(class_ptr, "%-10d%-15s%-15s%s/%s   %13s\n", c10++, studentInformation.firstName, studentInformation.lastName, studentInformation.standard, studentInformation.class, studentInformation.attendance);
        }
        else if (strcmp(studentInformation.standard, "7") == 0)
        {
            class_ptr = fopen(class[6], "ab+");
            if (class_ptr == NULL)
            {
                printf("Error in File opening");
                exit(0);
            }
            if (C7 == 'O')
            {
                C7 = 'O';
                fprintf(class_ptr, "Time : %s\nDate : %s\n\n", __TIME__, __DATE__);
                fprintf(class_ptr, "%-10s%-15s%-15s%-4s/%-4s   %-15s\n", "Roll No.", "First_Name", "Last_Name", "Std.", "Cls", "Attendence");
            }
            fprintf(class_ptr, "%-10d%-15s%-15s%s/%s   %13s\n", c10++, studentInformation.firstName, studentInformation.lastName, studentInformation.standard, studentInformation.class, studentInformation.attendance);
        }
        else if (strcmp(studentInformation.standard, "8") == 0)
        {
            class_ptr = fopen(class[7], "ab+");
            if (class_ptr == NULL)
            {
                printf("Error in File opening");
                exit(0);
            }
            if (C8 == 'O')
            {
                C8 = '?';
                fprintf(class_ptr, "Time : %s\nDate : %s\n\n", __TIME__, __DATE__);
                fprintf(class_ptr, "%-10s%-15s%-15s%-4s/%-4s   %-15s\n", "Roll No.", "First_Name", "Last_Name", "Std.", "Cls", "Attendence");
            }
            fprintf(class_ptr, "%-10d%-15s%-15s%s/%s   %13s\n", c10++, studentInformation.firstName, studentInformation.lastName, studentInformation.standard, studentInformation.class, studentInformation.attendance);
        }
        else if (strcmp(studentInformation.standard, "9") == 0)
        {
            class_ptr = fopen(class[8], "ab+");
            if (class_ptr == NULL)
            {
                printf("Error in File opening");
                exit(0);
            }
            if (C9 == 'O')
            {
                C9 = '?';
                fprintf(class_ptr, "Time : %s\nDate : %s\n\n", __TIME__, __DATE__);
                fprintf(class_ptr, "%-10s%-15s%-15s%-4s/%-4s   %-15s\n", "Roll No.", "First_Name", "Last_Name", "Std.", "Cls", "Attendence");
            }
            fprintf(class_ptr, "%-10d%-15s%-15s%s/%s   %13s\n", c10++, studentInformation.firstName, studentInformation.lastName, studentInformation.standard, studentInformation.class, studentInformation.attendance);
        }
        else if (strcmp(studentInformation.standard, "10") == 0)
        {
            class_ptr = fopen(class[9], "ab+");
            if (class_ptr == NULL)
            {
                printf("Error in File opening");
                exit(0);
            }
            if (C10 == 'O')
            {
                C10 = '?';
                fprintf(class_ptr, "Time : %s\nDate : %s\n\n", __TIME__, __DATE__);
                fprintf(class_ptr, "%-10s%-15s%-15s%-4s/%-4s   %-15s\n", "Roll No.", "First_Name", "Last_Name", "Std.", "Cls", "Attendence");
            }
            fprintf(class_ptr, "%-10d%-15s%-15s%s/%s   %13s\n", c10++, studentInformation.firstName, studentInformation.lastName, studentInformation.standard, studentInformation.class, studentInformation.attendance);
        }
    }
    fclose(class_ptr);
}

void save()
{
    system("cls");

    printf("\t\t\t\t>>>>>>>>>>>>>>>>> Save All Student's Record <<<<<<<<<<<<<<<<\n");
    char file_name[100];
    printf("Enter File name: ");
    scanf("%s", file_name);
    strcat(file_name, ".txt");
    FILE *save = fopen(file_name, "ab+");
    FILE *fileOne = fopen("Master.txt", "rb");
    if (save == NULL || fileOne == NULL)
    {
        printf("\n\t\t\tError !\n");
    }
    Student studentInformation;
    while (fread(&studentInformation, sizeof(studentInformation), 1, fileOne) == 1)
    {
        fprintf(save, "%-10s%-15s%-15s%-10s%-10s%-35s%-15s\n", studentInformation.rollNo, studentInformation.firstName, studentInformation.lastName, studentInformation.standard, studentInformation.class, studentInformation.attendance);
    }
    fclose(save);
    fclose(fileOne);
}

void fill_the_presence_or_absence()
{
    system("cls");

    printf("\t\t\t\t>>>>>>>>>>>>>>>>> Fill The Presence or Absence <<<<<<<<<<<<<<<<\n");
    FILE *fileOne = fopen("Master.txt", "rb");
    FILE *temp = fopen("temp.txt", "wb");
    if (fileOne == NULL || temp == NULL)
    {
        printf("Error in File opening\n");
        exit(0);
    }
    FILE *class_ptr;
    Student studentInformation;
    char *school[20] = {"Present_std1.txt", "Present_std2.txt", "Present_std3.txt", "Present_std4.txt", "Present_std5.txt", "Present_std6.txt", "Present_std7.txt", "Present_std8.txt", "Present_std9.txt", "Present_std10.txt"};
    for (int i = 0; i < 10; i++)
    {
        remove(school[i]);
    }
    while (fread(&studentInformation, sizeof(studentInformation), 1, fileOne) == 1)
    {
        system("cls");
        printf("Roll No.: %s\nName: %s%s\nStd./cls: %s/%s\n", studentInformation.rollNo, studentInformation.firstName, studentInformation.lastName, studentInformation.standard, studentInformation.class);
        printf("\n\n\t\tFill Presence(P)/Absence(A) : ");
        fflush(stdin);
        gets(studentInformation.attendance);
        fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
    }
    fclose(fileOne);
    fclose(temp);
    remove("Master.txt");
    rename("temp.txt", "Master.txt");
    fileOne = fopen("Master.txt", "rb");
    temp = fopen("temp.txt", "wb");
    char option, c1 = 'O', c2 = 'O', c3 = 'O', c4 = 'O', c5 = 'O', c6 = 'O', c7 = 'O', c8 = 'O', c9 = 'O', c10 = 'O';
    int flag = 0;

    printf("Do you want create different file of present students for different standard for current date :");
    scanf(" %c", &option);

    while (option == 'Y' || option == 'y')
    {
        while (fread(&studentInformation, sizeof(studentInformation), 1, fileOne) == 1)
        {
            if (strcmp(studentInformation.attendance, "P") == 0)
            {
                flag++;
                if (strcmp(studentInformation.standard, "1") == 0)
                {
                    class_ptr = fopen(school[0], "a+");
                    if (c1 == 'O')
                    {
                        c1 = '0';
                        fprintf(class_ptr, "Time : %s\nDate : %s\n\n", __TIME__, __DATE__);
                        fprintf(class_ptr, "%-10s%-15s%-15s%-4s/%-4s   %-15s\n", "Roll No.", "First_Name", "Last_Name", "Std.", "Cls", "Attendence");
                    }
                    fprintf(class_ptr, "%-10s%-15s%-15s%s/%s%13s\n", studentInformation.rollNo, studentInformation.firstName, studentInformation.lastName, studentInformation.standard, studentInformation.class, studentInformation.attendance);
                }
                else if (strcmp(studentInformation.standard, "2") == 0)
                {
                    class_ptr = fopen(school[1], "a+");
                    if (c2 == 'O')
                    {
                        c2 = '0';
                        fprintf(class_ptr, "Time : %s\nDate : %s\n\n", __TIME__, __DATE__);
                        fprintf(class_ptr, "%-10s%-15s%-15s%-4s/%-4s   %-15s\n", "Roll No.", "First_Name", "Last_Name", "Std.", "Cls", "Attendence");
                    }
                    fprintf(class_ptr, "%-10s%-15s%-15s%s/%s%13s\n", studentInformation.rollNo, studentInformation.firstName, studentInformation.lastName, studentInformation.standard, studentInformation.class, studentInformation.attendance);
                }
                else if (strcmp(studentInformation.standard, "3") == 0)
                {
                    class_ptr = fopen(school[2], "a+");
                    if (c3 == 'O')
                    {
                        c3 = '0';
                        fprintf(class_ptr, "Time : %s\nDate : %s\n\n", __TIME__, __DATE__);
                        fprintf(class_ptr, "%-10s%-15s%-15s%-4s/%-4s   %-15s\n", "Roll No.", "First_Name", "Last_Name", "Std.", "Cls", "Attendence");
                    }
                    fprintf(class_ptr, "%-10s%-15s%-15s%s/%s%13s\n", studentInformation.rollNo, studentInformation.firstName, studentInformation.lastName, studentInformation.standard, studentInformation.class, studentInformation.attendance);
                }
                else if (strcmp(studentInformation.standard, "4") == 0)
                {
                    class_ptr = fopen(school[3], "a+");
                    if (c4 == 'O')
                    {
                        c4 = '0';
                        fprintf(class_ptr, "Time : %s\nDate : %s\n\n", __TIME__, __DATE__);
                        fprintf(class_ptr, "%-10s%-15s%-15s%-4s/%-4s   %-15s\n", "Roll No.", "First_Name", "Last_Name", "Std.", "Cls", "Attendence");
                    }
                    fprintf(class_ptr, "%-10s%-15s%-15s%s/%s%13s\n", studentInformation.rollNo, studentInformation.firstName, studentInformation.lastName, studentInformation.standard, studentInformation.class, studentInformation.attendance);
                }
                else if (strcmp(studentInformation.standard, "5") == 0)
                {
                    class_ptr = fopen(school[4], "a+");
                    if (c5 == 'O')
                    {
                        c5 = '0';
                        fprintf(class_ptr, "Time : %s\nDate : %s\n\n", __TIME__, __DATE__);
                        fprintf(class_ptr, "%-10s%-15s%-15s%-4s/%-4s   %-15s\n", "Roll No.", "First_Name", "Last_Name", "Std.", "Cls", "Attendence");
                    }
                    fprintf(class_ptr, "%-10s%-15s%-15s%s/%s%13s\n", studentInformation.rollNo, studentInformation.firstName, studentInformation.lastName, studentInformation.standard, studentInformation.class, studentInformation.attendance);
                }
                else if (strcmp(studentInformation.standard, "6") == 0)
                {
                    class_ptr = fopen(school[5], "a+");
                    if (c6 == 'O')
                    {
                        c6 = '0';
                        fprintf(class_ptr, "Time : %s\nDate : %s\n\n", __TIME__, __DATE__);
                        fprintf(class_ptr, "%-10s%-15s%-15s%-4s/%-4s   %-15s\n", "Roll No.", "First_Name", "Last_Name", "Std.", "Cls", "Attendence");
                    }
                    fprintf(class_ptr, "%-10s%-15s%-15s%s/%s%13s\n", studentInformation.rollNo, studentInformation.firstName, studentInformation.lastName, studentInformation.standard, studentInformation.class, studentInformation.attendance);
                }
                else if (strcmp(studentInformation.standard, "7") == 0)
                {
                    class_ptr = fopen(school[6], "a+");
                    if (c7 == 'O')
                    {
                        c7 = '0';
                        fprintf(class_ptr, "Time : %s\nDate : %s\n\n", __TIME__, __DATE__);
                        fprintf(class_ptr, "%-10s%-15s%-15s%-4s/%-4s   %-15s\n", "Roll No.", "First_Name", "Last_Name", "Std.", "Cls", "Attendence");
                    }
                    fprintf(class_ptr, "%-10s%-15s%-15s%s/%s%13s\n", studentInformation.rollNo, studentInformation.firstName, studentInformation.lastName, studentInformation.standard, studentInformation.class, studentInformation.attendance);
                }
                else if (strcmp(studentInformation.standard, "8") == 0)
                {
                    class_ptr = fopen(school[7], "a+");
                    if (c8 == 'O')
                    {
                        c8 = '0';
                        fprintf(class_ptr, "Time : %s\nDate : %s\n\n", __TIME__, __DATE__);
                        fprintf(class_ptr, "%-10s%-15s%-15s%-4s/%-4s   %-15s\n", "Roll No.", "First_Name", "Last_Name", "Std.", "Cls", "Attendence");
                    }
                    fprintf(class_ptr, "%-10s%-15s%-15s%s/%s%13s\n", studentInformation.rollNo, studentInformation.firstName, studentInformation.lastName, studentInformation.standard, studentInformation.class, studentInformation.attendance);
                }
                else if (strcmp(studentInformation.standard, "9") == 0)
                {
                    class_ptr = fopen(school[8], "a+");
                    if (c9 == 'O')
                    {
                        c9 = '0';
                        fprintf(class_ptr, "Time : %s\nDate : %s\n\n", __TIME__, __DATE__);
                        fprintf(class_ptr, "%-10s%-15s%-15s%-4s/%-4s   %-15s\n", "Roll No.", "First_Name", "Last_Name", "Std.", "Cls", "Attendence");
                    }
                    fprintf(class_ptr, "%-10s%-15s%-15s%s/%s%13s\n", studentInformation.rollNo, studentInformation.firstName, studentInformation.lastName, studentInformation.standard, studentInformation.class, studentInformation.attendance);
                }
                else if (strcmp(studentInformation.standard, "10") == 0)
                {
                    class_ptr = fopen(school[9], "a+");
                    if (c10 == 'O')
                    {
                        c10 = '0';
                        fprintf(class_ptr, "Time : %s\nDate : %s\n\n", __TIME__, __DATE__);
                        fprintf(class_ptr, "%-10s%-15s%-15s%-4s/%-4s   %-15s\n", "Roll No.", "First_Name", "Last_Name", "Std.", "Cls", "Attendence");
                    }
                    fprintf(class_ptr, "%-10s%-15s%-15s%s/%s%13s\n", studentInformation.rollNo, studentInformation.firstName, studentInformation.lastName, studentInformation.standard, studentInformation.class, studentInformation.attendance);
                }
            }
        }
        option = 'N';
    }

    if (!flag)
    {
        printf("\n--------> ALL Standard Student's are Absent <--------\n");
        printf("\n\n Enter any key to Continue........\n");
        printf("\n\n\t\tEnter any keys to continue.......");
        getch();
    }

    fclose(fileOne);
    fclose(temp);
    fclose(class_ptr);
}

void create_file_present_students_in_school()
{
    system("cls");
    char school_fname[20];
    printf("\t\t\t\t>>>>>>>>>>>>>>>>> Create File Present Students in School <<<<<<<<<<<<<<<<\n");
    printf("\nEnter the file Name to store Present Students in School : ");
    scanf("%s", school_fname);
    strcat(school_fname, ".txt");
    FILE *fileOne = fopen("Master.txt", "rb");
    FILE *school_ptr = fopen(school_fname, "a+");
    if (fileOne == NULL || school_ptr == NULL)
    {
        printf("Error in File openinf\n");
        exit(0);
    }

    fprintf(school_ptr, "Time : %s\nDate : %s\n\n", __TIME__, __DATE__);
    fprintf(school_ptr, "%-10s%-15s%-15s%-4s/%-4s   %-15s\n", "Roll No.", "First_Name", "Last_Name", "Std.", "Cls", "Attendence");
    Student studentInformation;
    int flag = 0;
    while (fread(&studentInformation, sizeof(studentInformation), 1, fileOne) == 1)
    {
        if (strcmp(studentInformation.attendance, "P") == 0)
        {
            flag = 1;
            fprintf(school_ptr, "%-10s%-15s%-15s%s/%s%13s\n", studentInformation.rollNo, studentInformation.firstName, studentInformation.lastName, studentInformation.standard, studentInformation.class, studentInformation.attendance);
        }
    }
    if (!flag)
    {
        printf("\n--------> ALL STUDENT's are ABSENT <--------\n");
        printf("\n\n\t\tEnter any keys to continue.......");
        getch();
    }

    fclose(fileOne);
    fclose(school_ptr);
}