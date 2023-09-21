#define _CRT_SECURE_NO_WARNINGS

#define ROWS 4
#define COLS 4

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <Windows.h>

struct student {
    char surname[30];
    char name[30];
    char patronymic[30];
};

void punkt1_2()
{
    int a[10];
    int razn;
    srand(time(NULL));
    printf("Задание 1 и 2\n");
    for (int i = 0; i < 10; i++) 
    {
        a[i] = rand() % 100 - 50;
        printf("%d ", a[i]);
    }
    printf("\n");

    int max = a[0];
    int min = a[0];

    for (int i = 0; i <10; i++) 
    {
        if (a[i] > max) 
        {
            max = a[i];
        }
        if (a[i] < min) 
        {
            min = a[i];
        }
    }
    razn = max - min;
    printf("Разница между max и min элементами: %d\n", razn);
}

void pybkt3() 
{
    int size;
    printf("\n");
    printf("Задание 3\n");
    printf("Введите размер массива: ");
    std::cin >> size;
    int *g = (int*)malloc(size * sizeof(int));

    if (g == NULL) 
    {
        printf("Не удалось выделить память для массива\n");
        return;
    }
    printf("Введите эл-ты массива: ");
    for (int i = 0; i < size; i++) 
    {
        scanf("%d", &g[i]);
    }
    printf("Введённы массив: \n");
    for (int i = 0; i < size; i++) 
    {
        printf("%d ", g[i]);
    }
    free(g);
    printf("\n");
}

void punckt4()
{
    int zxc[ROWS][COLS];
    int stolb[COLS] = {0};
    
    srand(time(NULL));
    printf("\n");
    printf("Задание 4\n");
    //Заполнение массива случайным числами
    for (int i = 0; i < ROWS; i++) 
    {
        for (int j = 0; j < COLS; j++) 
        {
            zxc[i][j] = rand() % 100;
            printf("%d \t", zxc[i][j]);
        }
        printf("\n");
    }
    //Вычисление суммы по столбам
    for (int i = 0; i < ROWS; i++) 
    {
        for (int j = 0; j < COLS; j++) 
        {
            stolb[j] += zxc[i][j];
        }
    }
    printf("\n");
    //Вывод результата
    for (int i = 0; i < COLS; i++) 
    {
        printf("Сумма %d столбца: %d\n", i + 1, stolb[i]);
    }
}

void punct5()
{
    printf("\n");
    printf("Задание 5\n");
    struct student arr[5];
    char SrchFAM[30], SrchNAM[30], SrchOTC[30];
    int found = 0;
    //int c;
    int choice;

    // Ввод данных
    for (int i = 0; i < 3; i++) {
        printf("Введите ФИО студента %d: ", i + 1);
        scanf("%s %s %s", arr[i].surname, arr[i].name, arr[i].patronymic);
    }

    while (1) {
        printf("Выберите критерий поиска:\n");
        printf("1) Фамилия\n");
        printf("2) Имя\n");
        printf("3) Отчество\n");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Введите фамилию: ");
            scanf("%s", SrchFAM);

            for (int i = 0; i < 3; i++) {
                if (strcmp(arr[i].surname, SrchFAM) == 0) {
                    printf("Найден студент: \n");
                    printf("Фамилия: %s\n", arr[i].surname);
                    printf("Имя: %s\n", arr[i].name);
                    printf("Отчество: %s\n", arr[i].patronymic);
                    found = 1;
                    break;
                }
            }

        }
        else if (choice == 2) {
            printf("Введите Имя: ");
            scanf("%s", SrchNAM);

            for (int i = 0; i < 3; i++) {
                if (strcmp(arr[i].name, SrchNAM) == 0) {
                    printf("Найден студент: \n");
                    printf("Фамилия: %s\n", arr[i].surname);
                    printf("Имя: %s\n", arr[i].name);
                    printf("Отчество: %s\n", arr[i].patronymic);
                    found = 1;
                    break;
                }
            }
        }
        else if (choice == 3) {
            printf("Введите Отчество: ");
            scanf("%s", SrchOTC);

            for (int i = 0; i < 3; i++) {
                if (strcmp(arr[i].patronymic, SrchOTC) == 0) {
                    printf("Найден студент: \n");
                    printf("Фамилия: %s\n", arr[i].surname);
                    printf("Имя: %s\n", arr[i].name);
                    printf("Отчество: %s\n", arr[i].patronymic);
                    found = 1;
                    break;
                }
                if (!found) {
                    printf("Студент не найден!\n");
                }
                found = 0;
            }
        }
    }
}


int main() 
{
    SetConsoleCP(1251);//Установка языка
    SetConsoleOutputCP(1251);
    punkt1_2();
    pybkt3();
    punckt4();
    punct5();

    getchar();
}
