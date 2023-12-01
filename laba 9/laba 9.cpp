#include <iostream>
#include <cstdlib>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>
#include <chrono>

using namespace std;

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

// Функция для нахождения расстояния при обходе в глубину для матрицы смежности
void GGM(const vector<vector<int>>& graph, int nachalo2, int konec2, vector<int>& distances2) {
    stack<int> s;
    s.push(nachalo2);

    distances2[nachalo2] = 0;

    while (!s.empty()) {
        int v = s.top();
        s.pop();

        if (v == konec2) break;

        for (int i = 0; i < graph[v].size(); ++i) {
            int to = graph[v][i];
            if (distances2[to] == -1) {
                distances2[to] = distances2[v] + 1;
                s.push(to);
            }
        }
    }
}

//Фунция для нахождения расстояния при обходе в ширину для списка смежности
void GGM_list(const vector<vector<int>>& list, int nachalo3, int konec3, vector<int>& distances3) {

    queue<int> q;
    q.push(nachalo3);
    distances3[nachalo3] = 0;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        if (v == konec3) break;

        for (int i = 0; i < list[v].size(); ++i) {
            int to = list[v][i];
            if (distances3[to] == -1) {
                distances3[to] = distances3[v] + 1;
                q.push(to);
            }
        }
    }
}

// Функция для поиска расстояния в глубину для списка смежности
void DFS_list(const vector<vector<int>>& list1, int nachalo4, int finish1, vector<int>& distances4) {

    stack<int> s;
    s.push(nachalo4);

    distances4[nachalo4] = 0;

    while (!s.empty()) {
        int v = s.top();
        s.pop();

        if (v == finish1) break;

        for (int i = 0; i < list1[v].size(); ++i) {
            int to = list1[v][i];
            if (distances4[to] == -1) {
                distances4[to] = distances4[v] + 1;
                s.push(to);
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    int n;
    cout << "Введите кол-во вершин матрицы: ";
    cin >> n;

    vector<vector<int>> Matr(n, vector<int>(n));
    vector<vector<int>> list(n);
    vector<vector<int>> graph(n, vector<int>(n));

    // Матрица 1
    cout << "Матрица смежности " << endl;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (i == j) {
                Matr[i][j] = 0;
            }
            else {
                Matr[i][j] = rand() % 2;
                Matr[j][i] = Matr[i][j];
            }
        }
    }

    // Вывод матрицы 1
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << Matr[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n";

    // Заполнение графа на основе матрицы смежности
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (Matr[i][j] == 1) {
                graph[i].push_back(j);
            }
        }
    }
    
    //Нахождения расстояния при обходе в ширину для матрицы смежности 
    cout << "Расстояние при обходе в ширину для матрицы смежности\n";

    int nachalo1;
    cout << "Исходная вершина: ";
    cin >> nachalo1;
    nachalo1--;

    int konec1;
    cout << "Конечная вершина: ";
    cin >> konec1;
    konec1--;

    vector<int> distances(n, -1);

    RGM(graph, nachalo1, konec1, distances);

    if (distances[konec1] != -1) {
        cout << "Расстояние от вершины " << nachalo1 + 1 << " до " << konec1 + 1 << ": " << distances[konec1] << endl;
    }
    else {
        cout << "Пути не существует";
    }

    cout << "\n";
    //Обход в глубину
    cout << "Расстояние при обходе в глубину для матрицы смежности\n";

    int nachalo2;
    cout << "Начальная вершина: ";
    cin >> nachalo2;
    nachalo2--;

    int konec2;
    cout << "Конечная вершина: ";
    cin >> konec2;
    konec2--;

    // Нахождение расстояния при обходе в глубину
    vector<int> distances2(n, -1);

    GGM(graph, nachalo2, konec2, distances2);

    if (distances2[konec2] != -1) {
        cout << "Расстояние от вершины " << nachalo2 + 1 << " до " << konec2 + 1 << ": " << distances2[konec2] << endl;
    }
    else {
        cout << "Пути нет" << endl;
    }

   



    // Заполнение списка смежности на основе матрицы
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (Matr[i][j] == 1) {
                list[i].push_back(j);
                //list[j].push_back(i); // добавляем обратное ребро
            }
        }
    }

    // Вывод списка смежности
    cout << "\n";
    cout << "\nСписок смежности:\n";

    for (int i = 0; i < n; ++i) {
        cout << "Вершина " << i + 1 << ": ";

        for (int j = 0; j < list[i].size(); ++j) {
            cout << list[i][j] + 1 << " ";
        }

        cout << "\n";
    }

    cout << "\n";

    //Нахождения расстояния при обходе в ширину для списка смежности
    cout << "Расстояние при обходе в ширину для списка смежности\n";

    int nachalo3;
    cout << "Исходная вершина: ";
    cin >> nachalo3;
    nachalo3--;

    int konec3;
    cout << "Конечная вершина: ";
    cin >> konec3;
    konec3--; 

    vector<int> distances3(n, -1);

    GGM_list(list, nachalo3, konec3, distances3);

    if (distances3[konec3] != -1) {
        cout << "Расстояние от вершины " << nachalo3 + 1 << " до " << konec3 + 1 << ": " << distances3[konec3] << endl;
    }
    else {
        cout << "Пути не существует";
    }

    // Нахождения расстояния при обходе в глубину для списка смежности
    cout << "\n";
    cout << "Расстояние при обходе в глубину для списка смежности\n";

    int nachalo4;
    cout << "Начальная вершина: ";
    cin >> nachalo4;
    nachalo4--;

    int konec4;
    cout << "Конечная вершина: ";
    cin >> konec4;
    konec4--;

    // Поиск расстояния
    vector<int> distances4(n, -1);

    DFS_list(list, nachalo4, konec4, distances4);

    if (distances4[konec4] != -1) {
        cout << "Расстояние от вершины " << nachalo4 + 1 << " до " << konec4 + 1 << ": " << distances4[konec4] << endl;
    }
    else {
        cout << "Пути нет" << endl;
    }

    cout << "\n";
    cout << "\n";
    auto start = chrono::high_resolution_clock::now();
    RGM(graph, nachalo1, konec1, distances);
    auto end = chrono::high_resolution_clock::now();

    auto duration = end - start;
    chrono::duration<double, micro> microsec = chrono::duration_cast<chrono::duration<double, micro>>(duration);

    cout << "Время обхода в ширину: " << microsec.count() << " мкс" << endl;


    start = chrono::high_resolution_clock::now();
    GGM(graph, nachalo2, konec2, distances2);
    end = chrono::high_resolution_clock::now();

    duration = end - start;
    microsec = chrono::duration_cast<chrono::duration<double, micro>>(duration);

    cout << "Время обхода в глубину: " << microsec.count() << " мкс" << endl;

    return 0;
}