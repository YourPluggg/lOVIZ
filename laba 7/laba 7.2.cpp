#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

// Обход в глубину для матрицы смежности
void Matr(vector<vector<int>>& matrica, int v, vector<bool>& visited) {
    visited[v] = true;
    cout << v + 1 << " ";

    for (int i = 0; i < matrica.size(); ++i) {
        if (matrica[v][i] == 1 && !visited[i]) {
            Matr(matrica, i, visited);
        }
    }
}

// Обход в глубину для списка смежности
void Spsk(int v, vector<vector<int>>& zxc, vector<bool>& visited) {
    visited[v] = true;
    cout << v + 1 << " ";

    for (int i = 0; i < zxc[v].size(); ++i) {
        int next = zxc[v][i];
        if (!visited[next]) {
            Spsk(next, zxc, visited);
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    int n;
    cout << "Введите кол-во вершин матрицы: ";
    cin >> n;

    vector<vector<int>> matrica(n, vector<int>(n));

    // Матрица 1
    cout << "Матрица смежности " << endl;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (i == j) {
                matrica[i][j] = 0;
            }
            else {
                matrica[i][j] = rand() % 2;
                matrica[j][i] = matrica[i][j];
            }
        }
    }

    // Вывод матрицы 1
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrica[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n";

    vector<bool> visited(n, false);

    // Обход матрицы в глубину
    cout << "Обход матрицы в глубину\n";

    for (int i = 0; i < n; ++i) {
        int v = i;
        if (!visited[v]) {
            Matr(matrica, v, visited);
        }
    }

    fill(visited.begin(), visited.end(), false); // сброс посещенных

    vector<vector<int>> zxc(n);

    // Заполнение списка смежности на основе матрицы
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrica[i][j] == 1) {
                zxc[i].push_back(j);
                //zxc[j].push_back(i); // добавляем обратное ребро
            }
        }
    }

    // Вывод списка смежности
    cout << "\n";
    cout << "\nСписок смежности:\n";

    for (int i = 0; i < n; ++i) {
        cout << "Вершина " << i + 1 << ": ";

        for (int j = 0; j < zxc[i].size(); ++j) {
            cout << zxc[i][j] + 1 << " ";
        }

        cout << "\n";
    }

    // Обход в глубину для списка
    cout << "\n";
    cout << "Обход списка в глубину\n";
    for (int i = 0; i < n; ++i) {
        int v = i;
        if (!visited[v]) {
            Spsk(v, zxc, visited);
        }
    }

    return 0;
}

//Преобразование рекурсивной реализации обхода графа к не рекурсивной.
// Обход в глубину для матрицы смежности
/*void Matr1(vector<vector<int>>& matrica, int v, vector<bool>& visited) {
    stack<int> stk; // Стек для хранения вершин
    stk.push(v); // добавляем начальную вершину в стек

    while (!stk.empty()) {
        int current = stk.top(); // берем вершину на вершине стека
        stk.pop(); // удаляем вершину из стека

        if (!visited[current]) {
            visited[current] = true; // помечаем вершину как посещенную
            cout << current + 1 << " ";

            for (int i = matrica.size() - 1; i >= 0; --i) {
                if (matrica[current][i] == 1 && !visited[i]) {
                    stk.push(i); // добавляем смежные вершины в стек
                }
            }
        }
    }
}

// Обход в глубину для списка смежности
void sp(int v, vector<vector<int>>& zxc, vector<bool>& visited) {
    stack<int> stk; // Стек для хранения вершин
    stk.push(v); // добавляем начальную вершину в стек

    while (!stk.empty()) {
        int current = stk.top(); // берем вершину на вершине стека
        stk.pop(); // удаляем вершину из стека

        if (!visited[current]) {
            visited[current] = true; // помечаем вершину как посещенную
            cout << current + 1 << " ";

            for (int i = zxc[current].size() - 1; i >= 0; --i) {
                int next = zxc[current][i];
                if (!visited[next]) {
                    stk.push(next); // добавляем смежные вершины в стек
                }
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

    vector<vector<int>> matrica(n, vector<int>(n));

    // Матрица 1
    cout << "Матрица смежности " << endl;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (i == j) {
                matrica[i][j] = 0;
            }
            else {
                matrica[i][j] = rand() % 2;
                matrica[j][i] = matrica[i][j];
            }
        }
    }

    // Вывод матрицы 1
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrica[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n";

    vector<bool> visited(n, false);

    // Обход матрицы в глубину
    cout << "Обход матрицы в глубину\n";

    for (int i = 0; i < n; ++i) {
        int v = i;
        if (!visited[v]) {
            Matr1(matrica, v, visited);
        }
    }

    fill(visited.begin(), visited.end(), false); // сброс посещенных

    vector<vector<int>> zxc(n);

    // Заполнение списка смежности на основе матрицы
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrica[i][j] == 1) {
                zxc[i].push_back(j);
                //zxc[j].push_back(i); // добавляем обратное ребро
            }
        }
    }

    // Вывод списка смежности
    cout << "\n";
    cout << "\nСписок смежности:\n";

    for (int i = 0; i < n; ++i) {
        cout << "Вершина " << i + 1 << ": ";

        for (int j = 0; j < zxc[i].size(); ++j) {
            cout << zxc[i][j] + 1 << " ";
        }

        cout << "\n";
    }

    // Обход в глубину для списка
    cout << "\n";
    cout << "Обход списка в глубину\n";
    for (int i = 0; i < n; ++i) {
        int v = i;
        if (!visited[v]) {
            sp(v, zxc, visited);
        }
    }

    return 0;
}*/