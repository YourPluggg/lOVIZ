#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

int main() {
	SetConsoleCP(1251);//Установка языка
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	int n;
	int raz;
	printf("Введите кол-во вершин: ");
	scanf_s("%d", &n);
	

	int** Matr1 = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		Matr1[i] = (int*)malloc(n * sizeof(int));
	}

	raz = 0;
	printf("Матрица смежности\n");

	
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (i == j) {
				Matr1[i][j] = 0;
			}
			else {
				Matr1[i][j] = rand() % 2;
				Matr1[j][i] = Matr1[i][j];
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			Matr1[i][j] = Matr1[j][i];
		}
	}
	//вывод матрицы
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", Matr1[i][j]);
		}
		printf("\n");
	}

	for (int j = 0; j < n; j++) {
		for (int i = j + 1; i < n; i++) {
			if (Matr1[i][j] == 1)
			{
				raz++;
			}
		}
	}
	

	int** Matr2 = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		Matr2[i] = (int*)malloc(raz * sizeof(int));
	}

	printf("Размер графа %d\n", raz);

	int* Str = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		Str[i] = 0;
		for (int j = 0; j < n; j++) {
			if (Matr1[i][j] == 1) {
				Str[i]++;
			}
		}

		if (Str[i] == 0) {
			printf("Строка %d: Изолированная вершина\n", i);
		}
		if (Str[i] == 1) {
			printf("Строка %d: Концевая вершина\n", i);
		}
		if (Str[i] == n - 1) {
			printf("Строка %d: Доминирующая вершина\n", i);
		}

	}

	free(Str);
	

	printf("Задание 2\n");

	printf("Матрица инцидентности\n");

	raz = 0;
	
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (Matr1[i][j] == 1) {
				for (int k = 0; k < n; k++) {
					if (k == j || k == i) {
						Matr2[k][raz] = 1;
					}
					else {
						Matr2[k][raz] = 0;
					}
				}
				raz++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < raz; j++) {
			printf("%d ", Matr2[i][j]);
		}
		printf("\n");
	}

	printf("Размер графа %d\n", raz);
	
	int* Str1 = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		Str1[i] = 0;
		for (int j = 0; j < n; j++) {
			if (Matr2[i][j] == 1) {
				Str1[i]++;
			}
		}

		if (Str1[i] == 0) {
			printf("Строка %d: Изолированная вершина\n", i);
		}
		else if (Str1[i] == 1) {
			printf("Строка %d: Концевая вершина\n", i);
		}
		else if (Str1[i] == n - 1) {
			printf("Строка %d: Доминирующая вершина\n", i);
		}
	}
	free(Str1);

	for (int i = 0; i < n; i++) {
		Matr1[i] = (int*)malloc(n * sizeof(int));
		Matr2[i] = (int*)malloc(raz * sizeof(int));
	}
	free(Matr1);
	free(Matr2);

	getchar();
	getchar();
	 //return 0;
}

	

