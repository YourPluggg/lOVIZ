﻿#include <iostream>
#include <cstdlib>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <iomanip> // Для использования std::setw

using namespace std;

struct GraphSettings {
    bool weighted;
    bool directed;
};

//Задаём параметры
GraphSettings arguments(int argc, char* argv[]) {
    GraphSettings settings{ false, false };

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-w") == 0) {
            settings.weighted = true;
        }
        else if (strcmp(argv[i], "-d") == 0) {
            settings.directed = true;
        }
    }

    return settings;
}

//Фунция для нахождения расстояния при обходе в ширину для матрицы смежности
void RGM(const vector<vector<int>>& graph, int nachalo1, int konec1, vector<int>& distances) {
    queue<int> q;
    q.push(nachalo1);
    distances[nachalo1] = 0;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        if (v == konec1) {
            break;
        }

        for (int i = 0; i < graph[v].size(); i++) {
            int to = graph[v][i];
            if (distances[to] == -1) {
                q.push(to);
                distances[to] = distances[v] + 1;
            }
        }
    }
}

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    GraphSettings graphSettings = arguments(argc, argv);
    int n;
    cout << "Введите кол-во вершин матрицы: ";
    cin >> n;

    vector<vector<int>> Matr(n, vector<int>(n));
    vector<vector<int>> graph(n, vector<int>(n));
    vector<vector<int>> list(n);

    int** adjMatrix = new int* [n];
    for (int i = 0; i < n; i++) {
        adjMatrix[i] = new int[n];

        for (int j = 0; j < n; j++) {
            if (i == j) adjMatrix[i][j] = 0;
            else adjMatrix[i][j] = rand() % 10;
        }
    }

    //Генерация рёбер для различных параметров
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (i == j) {
                adjMatrix[i][j] = 0;
            }
            else {
                if (graphSettings.weighted == 1 && graphSettings.directed == 1) {
                    adjMatrix[i][j] = (-10) + rand() % 21;
                    adjMatrix[j][i] = adjMatrix[i][j];
                }
                if (graphSettings.weighted == 0 && graphSettings.directed == 1) {
                    adjMatrix[i][j] = (-1) + rand() % 3;
                    adjMatrix[j][i] = adjMatrix[i][j];
                }
                if (graphSettings.weighted == 1 && graphSettings.directed == 0) {
                    adjMatrix[i][j] = rand() % 10;
                    adjMatrix[j][i] = adjMatrix[i][j];
                }
                if (graphSettings.weighted == 0 && graphSettings.directed == 0) {
                    adjMatrix[i][j] = rand() % 2;
                    adjMatrix[j][i] = adjMatrix[i][j];
                }
            }
        }
    }

    // вывод матрицы 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << std::setw(3) << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }

    // Заполнение графа на основе матрицы смежности
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (adjMatrix[i][j] > 0) {
                graph[i].push_back(j);
            }
        }
    }

    //Нахождения расстояния при обходе в ширину для матрицы смежности 
    cout << "\nРасстояние при обходе в ширину для матрицы смежности\n";

    int nachalo1;
    cout << "Исходная вершина: ";
    for (;;)
    {
        cin >> nachalo1;
        if (nachalo1 > n) {
            cout << "Такой вершины нет\n";
            cout << "Введите ещё раз исходную вершину: ";
        }
        else
        {
            break;
        }
    }
    nachalo1--;

    int konec1;
    cout << "Конечная вершина: ";
    for (;;)
    {
        cin >> konec1;
        if (konec1 > n) {
            cout << "Такой вершины нет\n";
            cout << "Введите ещё раз конечную вершину: ";
        }
        else
        {
            break;
        }
    }
    konec1--;
    vector<int> distances(n, -1);

    RGM(graph, nachalo1, konec1, distances);

    if (distances[konec1] != -1) {
        cout << "\nРасстояние от вершины " << nachalo1 + 1 << " до " << konec1 + 1 << ": " << distances[konec1] << endl;
        cout << "\n";
    }
    else {
        cout << "\nПути не существует\n";
    }

    // Заполнение списка смежности на основе матрицы
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (adjMatrix[i][j] > 0) {
                list[i].push_back(j);
                //list[j].push_back(i); // добавляем обратное ребро
            }
        }
    }

    // Вывод списка смежности

    cout << "\nСписок смежности:\n";

    for (int i = 0; i < n; ++i) {
        cout << "Вершина " << i + 1 << ": ";

        for (int j = 0; j < list[i].size(); ++j) {
            cout << list[i][j] + 1 << " ";
        }

        cout << "\n";
    }

    cout << "\n";

    //Радиус, диаметр и вершины
    vector<int> eccentricities(n);
    vector<int> visited(n, -1);

    for (int start = 0; start < n; start++) {
        fill(visited.begin(), visited.end(), -1);

        RGM(graph, start, -1, visited);

        int max_distance = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i] > max_distance) {
                max_distance = visited[i];
            }
        }

        eccentricities[start] = max_distance;
    }

    int diameter = 0;
    for (int i = 0; i < n; i++) {
        if (eccentricities[i] > diameter) {
            diameter = eccentricities[i];
        }
    }

    int radius = diameter;
    for (int i = 0; i < n; i++) {
        if (eccentricities[i] < radius) {
            radius = eccentricities[i];
        }
    }

    cout << "Радиус графа: " << radius << "\n";
    cout << "Диаметр графа: " << diameter << "\n";

    cout << "Центральные вершины: ";
    for (int i = 0; i < n; i++) {
        if (eccentricities[i] == radius) {
            cout << i + 1 << " ";
        }
    }
    cout << "\n";

    cout << "Периферийные вершины: ";
    for (int i = 0; i < n; i++) {
        if (eccentricities[i] == diameter) {
            cout << i + 1 << " ";
        }
    }
    cout << "\n";


    // освобождение памяти
    for (int i = 0; i < n; i++) {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;

    return 0;
}
