#ifndef MAIN_H
#define MAIN_H

typedef struct Student
{
    char rollNo[4];
    char firstName[50];
    char lastName[50];
    char standard[3];
    char class[2];
    char email[40];
    char attendance[3];
} Student;

void add_database();
void display_info();
void update_info();
void delete_info();
void search_info();
void create_Standard_wise_file();
void save();
void fill_the_presence_or_absence();
void create_file_present_students_in_school();

#endif