#include "AdministrasiSekolahHeader.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
int main()
{
    Student *s = NULL;
    int input, grade, opt;
    char nis[12], name[40], major[5], teacher[40], activity[40];
    do
    {
        system("cls");
        printf("\n");
        printf("\t\t\t   Administrasi Sekolah       \n");
        printf("\n");
        printf("\n1. Tambah Siswa\n2. Cetak Siswa\n3. Cari Siswa\n4. Exit\nPChoose [1 - 4] >");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            system("cls");
            printf("Masukkan NIS Siswa [LENGTH : MAX 12] | Harus Digit\n>");
            do
            {
                fflush(stdin);
                gets(nis);
                if (strlen(nis) == 0)
                {
                    printf("NIS tidak boleh kosong\n>");
                }
                else if (strlen(nis) > 12)
                {
                    printf("NIS tidak boleh lebih dari 12 karakter\n>");
                }
                else if (check_digit(nis) == 0)
                {
                    printf("NIS harus berupa digit\n>");
                }
                else
                {
                    break;
                }
            } while (1);

            printf("Masukkan Nama Siswa [LENGTH : MAX 40]\n>");
            do
            {
                fflush(stdin);
                gets(name);
                if (strlen(name) == 0)
                {
                    printf("Nama tidak boleh kosong\n>");
                }
                else if (strlen(name) > 40)
                {
                    printf("Nama tidak boleh lebih dari 40 karakter\n>");
                }
                else if (check_alpha(name) == 0)
                {
                    printf("Nama harus berupa huruf\n>");
                }
                else
                {
                    break;
                }
            } while (1);

            printf("Masukkan Tingkat : 10-12\n>");
            do
            {
                fflush(stdin);
                scanf("%d", &grade);
                if (grade >= 10 && grade <= 12)
                {
                    break;
                }
                else
                {
                    printf("Tingkatan Tidak Ada!\n");
                    printf("Silahkan masukkan ulang Tingkat\n>");
                }
            } while (1);

            printf("Masukkan Jurusan [IPA / IPS]\n>");
            do
            {
                fflush(stdin);
                gets(major);
                strupr(major);
                if (strcmp(major, "IPA") == 0 || strcmp(major, "IPS") == 0)
                {
                    break;
                }
                else
                {
                    printf("Jurusan Tidak Ada!\n");
                    printf("Silahkan masukkan ulang jurusan\n>");
                }
            } while (1);

            printf("Masukkan Nama Wali Kelas [LENGTH : MAX 40]\n>");
            do
            {
                fflush(stdin);
                gets(teacher);
                if (strlen(teacher) == 0)
                {
                    printf("Nama Wali Kelas tidak boleh kosong\n>");
                }
                else if (strlen(teacher) > 40)
                {
                    printf("Nama Wali Kelas tidak boleh lebih dari 40 karakter\n>");
                }
                else if(check_alpha(teacher) == 0)
                {
                    printf("Nama Wali Kelas harus berupa huruf\n>");
                }
                else
                {
                    break;
                }
            } while (1);

            printf("Masukkan Aktivitas Ekstrakulikuler [OSIS / Voli / Basket / Badminton / Renang / Seni Tari / Seni Musik / Science / Social Club]\n>");
            do
            {
                fflush(stdin);
                gets(activity);
                if (strcmp(activity, "OSIS") == 0 || strcmp(activity, "Voli") == 0 || strcmp(activity, "Basket") == 0 || strcmp(activity, "Badminton") == 0 || strcmp(activity, "Renang") == 0 || strcmp(activity, "Seni Tari") == 0 || strcmp(activity, "Seni Musik") == 0 || strcmp(activity, "Science") == 0 || strcmp(activity, "Social Club") == 0)
                {
                    break;
                }
                else
                {
                    printf("Ekstrakulikuler Tidak Ada!\n");
                    printf("Silahkan masukkan ulang Ekstrakulikuler\n>");
                }
            } while (1);
            add_student(&s, nis, name, grade, major, teacher, activity);
            printf("Tekan Enter untuk melanjutkan...");
            getch();
            break;
        case 2:
            system("cls");
            if (!check_empty(s))
            {
                printf("\n");
                printf("\t\t\t       Cetak Siswa       \n");
                printf("\n");
                printf("\n1. Berdasarkan Tingkat Kelas\n2. Berdasarkan Jurusan\n3. Ekstrakulikuler\n4. Seluruh Siswa\n5. Exit\nChoose [1 - 5] >");
                scanf("%d", &opt);
                switch (opt)
                {
                case 1:
                    system("cls");
                    print_condition(s, "Tingkat");
                    break;
                case 2:
                    system("cls");
                    print_condition(s, "Jurusan");
                    break;
                case 3:
                    system("cls");
                    print_condition(s, "Ekstrakulikuler");
                    break;
                case 4:
                    system("cls");
                    print_all(s);

                    break;
                }
            }
            else
            {
                printf("Data Siswa Masih Kosong\n");
                printf("Silahkan Tambahkan Data Terlebih Dahulu\n");
            }
            printf("Tekan Enter untuk melanjutkan...");
            getch();
            break;
        case 3:
            system("cls");
            if (!check_empty(s))
            {
                printf("\n");
                printf("\t\t\t       Cari Siswa       \n");
                printf("\n");
                printf("Masukkan NIS Siswa [LENGTH : MAX 12]\n>");
                do
                {
                    fflush(stdin);
                    gets(nis);
                    if (check_digit(nis))
                    {
                        break;
                    }
                } while (1);
                system("cls");
                search_student(s, nis);
            }
            else
            {
                printf("Data Siswa Masih Kosong\n");
                printf("Silahkan Tambahkan Data Terlebih Dahulu\n");
            }
            printf("Tekan Enter untuk melanjutkan...");
            getch();
            break;
        case 4:
            printf("Tekan Enter untuk melanjutkan...");
            getch();
            free(s);
            exit(0);
        }
    } while (1);

    return 0;
}