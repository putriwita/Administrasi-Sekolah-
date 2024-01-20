#include "AdministrasiSekolahHeader.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

Student *add_student(Student **nodeRef, char *_nis, char *_name, int _grade, char *_major, char *_teacher, char *_activity)
{
    Student *s = (Student *)malloc(sizeof(Student) * 1);
    if (check_empty(*nodeRef))
    {
        strcpy(s->nis, _nis);
        strcpy(s->name, _name);
        s->grade = _grade;
        strcpy(s->major, _major);
        strcpy(s->teacher, _teacher);
        strcpy(s->activity, _activity);
        s->next = NULL;
        (*nodeRef) = s;
    }
    else
    {
        Student *temp;
        strcpy(s->nis, _nis);
        strcpy(s->name, _name);
        s->grade = _grade;
        strcpy(s->major, _major);
        strcpy(s->teacher, _teacher);
        strcpy(s->activity, _activity);
        s->next = NULL;
        temp = (*nodeRef);
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = s;
        return temp;
    }
}

void search_student(Student *nodeRef, char *_nis)
{
    Student *temp;
    int idx = -99;
    temp = nodeRef;
    if (!check_empty(nodeRef))
    {
        while (temp != NULL)
        {
            if (strcmp(temp->nis, _nis) == 0)
            {
                printf("\n");
                printf("NIS \t\t\t: %s\n", temp->nis);
                printf("Nama \t\t\t: %s\n", temp->name);
                printf("Tingkat \t\t: %d\n", temp->grade);
                printf("Jurusan \t\t: %s\n", temp->major);
                printf("Wali Kelas \t\t: %s\n", temp->teacher);
                printf("Ekstrakulikuler \t: %s\n", temp->activity);
                printf("\n");
                idx = 0;
                break;
            }
            else
            {
                temp = temp->next;
            }
        }
    }

    if (idx == -99)
    {
        printf("Siswa dengan nis %s tidak ditemukan\n", _nis);
    }
}

int check_digit(char *str)
{
    int status = 1;

    for (int i = 0; i < strlen(str); i++)
    {
        if (!isdigit(str[i]))
        {
            status = 0;
            break;
        }
    }
    return status;
}

int check_alpha(char *str)
{
    int status = 1;
    for (int i = 0; i < strlen(str); i++)
    {
        if (isalpha(str[i]) || str[i] == ' ' || str[0] != ' ')
        {
            status = 1;
            continue;
        } else {
            status = 0;
            break;
        }
    }
    return status;
}

int check_empty(Student *s)
{
    return (s == NULL) ? 1 : 0;
}

void print_condition(Student *s, char *keyword)
{
    Student *temp;
    if (strcmp(keyword, "Tingkat") == 0)
    {
        for (int i = 10; i <= 12; i++)
        {
            temp = s;
            printf("Tingkat \t\t: %d\n", i);
            printf("\n");
            while (temp != NULL)
            {
                if (temp->grade == i)
                {
                    printf("NIS \t\t\t: %s\n", temp->nis);
                    printf("Nama \t\t\t: %s\n", temp->name);
                    printf("Tingkat \t\t: %d\n", temp->grade);
                    printf("Jurusan \t\t: %s\n", temp->major);
                    printf("Wali Kelas \t\t: %s\n", temp->teacher);
                    printf("Ekstrakulikuler \t: %s\n", temp->activity);
                    printf("\n");
                }
                temp = temp->next;
            }
            printf("\n");
        }
    }
    else if (strcmp(keyword, "Jurusan") == 0)
    {
        temp = s;
        printf("Jurusan \t\t: IPA\n");
        printf("\n");
        while (temp != NULL)
        {
            if (strcmp(temp->major, "IPA") == 0)
            {
                printf("NIS \t\t\t: %s\n", temp->nis);
                printf("Nama \t\t\t: %s\n", temp->name);
                printf("Tingkat \t\t: %d\n", temp->grade);
                printf("Jurusan \t\t: %s\n", temp->major);
                printf("Wali Kelas \t\t: %s\n", temp->teacher);
                printf("Ekstrakulikuler \t: %s\n", temp->activity);
                printf("\n");
            }
            temp = temp->next;
        }
        printf("\n");
        temp = s;
        printf("Jurusan \t\t: IPS\n");
        printf("\n");
        while (temp != NULL)
        {
            if (strcmp(temp->major, "IPS") == 0)
            {
                printf("NIS \t\t\t: %s\n", temp->nis);
                printf("Nama \t\t\t: %s\n", temp->name);
                printf("Tingkat \t\t: %d\n", temp->grade);
                printf("Jurusan \t\t: %s\n", temp->major);
                printf("Wali Kelas \t\t: %s\n", temp->teacher);
                printf("Ekstrakulikuler \t: %s\n", temp->activity);
                printf("\n");
            }
            temp = temp->next;
        }
    }
    else if (strcmp(keyword, "Ekstrakulikuler") == 0)
    {
        temp = s;
        printf("Ekstrakulikuler \t: OSIS\n");
        printf("\n");
        while (temp != NULL)
        {
            if (strcmp(temp->activity, "OSIS") == 0)
            {
                printf("NIS \t\t\t: %s\n", temp->nis);
                printf("Nama \t\t\t: %s\n", temp->name);
                printf("Tingkat \t\t: %d\n", temp->grade);
                printf("Jurusan \t\t: %s\n", temp->major);
                printf("Wali Kelas \t\t: %s\n", temp->teacher);
                printf("Ekstrakulikuler \t: %s\n", temp->activity);
                printf("\n");
            }
            temp = temp->next;
        }
        printf("\n");
        temp = s;
        printf("Ekstrakulikuler \t: Voli\n");
        printf("\n");
        while (temp != NULL)
        {
            if (strcmp(temp->activity, "Voli") == 0)
            {
                printf("NIS \t\t\t: %s\n", temp->nis);
                printf("Nama \t\t\t: %s\n", temp->name);
                printf("Tingkat \t\t: %d\n", temp->grade);
                printf("Jurusan \t\t: %s\n", temp->major);
                printf("Wali Kelas \t\t: %s\n", temp->teacher);
                printf("Ekstrakulikuler \t: %s\n", temp->activity);
                printf("\n");
            }
            temp = temp->next;
        }
        printf("\n");
        temp = s;
        printf("Ekstrakulikuler \t: Basket\n");
        printf("\n");
        while (temp != NULL)
        {
            if (strcmp(temp->activity, "Basket") == 0)
            {
                printf("NIS \t\t\t: %s\n", temp->nis);
                printf("Nama \t\t\t: %s\n", temp->name);
                printf("Tingkat \t\t: %d\n", temp->grade);
                printf("Jurusan \t\t: %s\n", temp->major);
                printf("Wali Kelas \t\t: %s\n", temp->teacher);
                printf("Ekstrakulikuler \t: %s\n", temp->activity);
                printf("\n");
            }
            temp = temp->next;
        }
        printf("\n");
        temp = s;
        printf("Ekstrakulikuler \t: Badminton\n");
        printf("\n");
        while (temp != NULL)
        {
            if (strcmp(temp->activity, "Badminton") == 0)
            {
                printf("NIS \t\t\t: %s\n", temp->nis);
                printf("Nama \t\t\t: %s\n", temp->name);
                printf("Tingkat \t\t: %d\n", temp->grade);
                printf("Jurusan \t\t: %s\n", temp->major);
                printf("Wali Kelas \t\t: %s\n", temp->teacher);
                printf("Ekstrakulikuler \t: %s\n", temp->activity);
                printf("\n");
            }
            temp = temp->next;
        }
        printf("\n");
        temp = s;
        printf("Ekstrakulikuler \t: Renang\n");
        printf("\n");
        while (temp != NULL)
        {
            if (strcmp(temp->activity, "Renang") == 0)
            {
                printf("NIS \t\t\t: %s\n", temp->nis);
                printf("Nama \t\t\t: %s\n", temp->name);
                printf("Tingkat \t\t: %d\n", temp->grade);
                printf("Jurusan \t\t: %s\n", temp->major);
                printf("Wali Kelas \t\t: %s\n", temp->teacher);
                printf("Ekstrakulikuler \t: %s\n", temp->activity);
                printf("\n");
            }
            temp = temp->next;
        }
        printf("\n");
        temp = s;
        printf("Ekstrakulikuler \t: Seni Tari\n");
        printf("\n");
        while (temp != NULL)
        {
            if (strcmp(temp->activity, "Seni Tari") == 0)
            {
                printf("NIS \t\t\t: %s\n", temp->nis);
                printf("Nama \t\t\t: %s\n", temp->name);
                printf("Tingkat \t\t: %d\n", temp->grade);
                printf("Jurusan \t\t: %s\n", temp->major);
                printf("Wali Kelas \t\t: %s\n", temp->teacher);
                printf("Ekstrakulikuler \t: %s\n", temp->activity);
                printf("\n");
            }
            temp = temp->next;
        }
        printf("\n");
        temp = s;
        printf("Ekstrakulikuler \t: Seni Musik\n");
        printf("\n");
        while (temp != NULL)
        {
            if (strcmp(temp->activity, "Seni Musik") == 0)
            {
                printf("NIS \t\t\t: %s\n", temp->nis);
                printf("Nama \t\t\t: %s\n", temp->name);
                printf("Tingkat \t\t: %d\n", temp->grade);
                printf("Jurusan \t\t: %s\n", temp->major);
                printf("Wali Kelas \t\t: %s\n", temp->teacher);
                printf("Ekstrakulikuler \t: %s\n", temp->activity);
                printf("\n");
            }
            temp = temp->next;
        }
        printf("\n");
        temp = s;
        printf("Ekstrakulikuler \t: Science\n");
        printf("\n");
        while (temp != NULL)
        {
            if (strcmp(temp->activity, "Science") == 0)
            {
                printf("NIS \t\t\t: %s\n", temp->nis);
                printf("Nama \t\t\t: %s\n", temp->name);
                printf("Tingkat \t\t: %d\n", temp->grade);
                printf("Jurusan \t\t: %s\n", temp->major);
                printf("Wali Kelas \t\t: %s\n", temp->teacher);
                printf("Ekstrakulikuler \t: %s\n", temp->activity);
                printf("\n");
            }
            temp = temp->next;
        }
        printf("\n");
        temp = s;
        printf("Ekstrakulikuler \t: Social Club\n");
        printf("\n");
        while (temp != NULL)
        {
            if (strcmp(temp->activity, "Social Club") == 0)
            {
                printf("NIS \t\t\t: %s\n", temp->nis);
                printf("Nama \t\t\t: %s\n", temp->name);
                printf("Tingkat \t\t: %d\n", temp->grade);
                printf("Jurusan \t\t: %s\n", temp->major);
                printf("Wali Kelas \t\t: %s\n", temp->teacher);
                printf("Ekstrakulikuler \t: %s\n", temp->activity);
                printf("\n");
            }
            temp = temp->next;
        }
    }
}

void print_all(Student *s)
{
    Student *temp;
    temp = s;
    printf("\n");
    while (temp != NULL)
    {
        printf("NIS \t\t\t: %s\n", temp->nis);
        printf("Nama \t\t\t: %s\n", temp->name);
        printf("Tingkat \t\t: %d\n", temp->grade);
        printf("Jurusan \t\t: %s\n", temp->major);
        printf("Wali Kelas \t\t: %s\n", temp->teacher);
        printf("Ekstrakulikuler \t: %s\n", temp->activity);
        printf("\n");
        temp = temp->next;
    }
}