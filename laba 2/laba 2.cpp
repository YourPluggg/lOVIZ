#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

void test_matrix_mult_time(int size) {
    setlocale(LC_ALL, "Russian");
    int i, j, r;
    int** a, ** b, ** c;
    int elem_c;

    a = (int**)malloc(size * sizeof(int*));
    b = (int**)malloc(size * sizeof(int*));
    c = (int**)malloc(size * sizeof(int*));

    for (i = 0; i < size; i++) {
        a[i] = (int*)malloc(size * sizeof(int));
        b[i] = (int*)malloc(size * sizeof(int));
        c[i] = (int*)malloc(size * sizeof(int));
    }

    i = 0; j = 0;
    srand(time(NULL));
    while (i < size) {
        while (j < size) {
            a[i][j] = rand() % 100 + 1;
            j++;
        }
        i++;
    }

    i = 0; j = 0;
    srand(time(NULL));
    while (i < size) {
        while (j < size) {
            b[i][j] = rand() % 100 + 1;
            j++;
        }
        i++;
    }

    clock_t start = clock();
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            elem_c = 0;
            for (r = 0; r < size; r++) {
                elem_c = elem_c + a[i][r] * b[r][j];
                c[i][j] = elem_c;
            }
        }
    }
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Размер массива: %d x %d\n", size, size);
    printf("Затраченное время: %f seconds\n", time_taken);

    free(a);
    free(b);
    free(c);
}

int main() {
    test_matrix_mult_time(100);
    test_matrix_mult_time(200);
    test_matrix_mult_time(400);
    test_matrix_mult_time(1000);
    test_matrix_mult_time(2000);
    test_matrix_mult_time(4000);
    test_matrix_mult_time(10000);

    return 0;
}
