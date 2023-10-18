#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    int n, m;
    cout << "Введите кол-во вершин матрицы 1: ";
    cin >> n;
    cout << "Введите кол-во вершин матрицы 2: ";
    cin >> m;

    int** Matr1 = new int* [n];
    for (int i = 0; i < n; i++) {
        Matr1[i] = new int[n];
    }

    int** Matr2 = new int* [m];
    for (int i = 0; i < m; i++) {
        Matr2[i] = new int[m];
    }

    //Матрица 1
    cout << "Матрица смежности 1" << endl;

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

    //вывод матрицы 1
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << Matr1[i][j] << " ";
        }
        cout << endl;
    }

    //список смежности 1
    cout << "Список смежности 1" << endl;
    vector<vector<int>> AdjList1(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (Matr1[i][j] == 1) {
                AdjList1[i].push_back(j);
            }
        }
    }
    
    //вывод списка смежности 1
    for (int i = 0; i < n; i++) {
        cout << "Вершина " << i << ": ";
        for (int j = 0; j < AdjList1[i].size(); j++) {
            cout << AdjList1[i][j] << " ";
        }
        cout << endl;
    }

    //удаление динамического массива 1
    for (int i = 0; i < n; i++) {
        delete[] Matr1[i];
    }
    delete[] Matr1;

    //Матрица 2
    cout << "Матрица смежности 2" << endl;

    for (int i = 0; i < m; i++) {
        for (int j = i; j < m; j++) {
            if (i == j) {
                Matr2[i][j] = 0;
            }
            else {
                Matr2[i][j] = rand() % 2;
                Matr2[j][i] = Matr2[i][j];
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            Matr2[i][j] = Matr2[j][i];
        }
    }

    //вывод матрицы 2
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cout << Matr2[i][j] << " ";
        }
        cout << endl;
    }

    //список смежности 2
    cout << "Список смежности 2" << endl;
    vector<vector<int>> AdjList2(m);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (Matr2[i][j] == 1) {
                AdjList2[i].push_back(j);
            }
        }
    }

    //вывод списка смежности 2
    for (int i = 0; i < m; i++) {
        cout << "Вершина " << i << ": ";
        for (int j = 0; j < AdjList2[i].size(); j++) {
            cout << AdjList2[i][j] << " ";
        }
        cout << endl;
    }

    //удаление динамического массива 2
    for (int i = 0; i < m; i++) {
        delete[] Matr2[i];
    }
    delete[] Matr2;

    return 0;
}

