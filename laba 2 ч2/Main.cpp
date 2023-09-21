#include "Header.h"

int main() {
	//SHELL
	setlocale(LC_ALL, "Russian");
	int count;
	std::cout << "Vvedite razmer massiva ";
	std::cin >> count;

	// 1. Рандомные числа
	int* items1 = new int[count];
	srand(time(NULL));
	for (int i = 0; i < count; i++) {
		items1[i] = rand() % 100;
	}

	out.open("СОРТИРОВКА.txt");
	out << "SHELL сортировка:\n";
	out << "Массив из рандомных чисел:\n";
	out << "До сортировки:\n";
	for (int i = 0; i < count; i++) {
		out << items1[i] << " ";
	}
	out << "\n\n";
	out.close();

	clock_t start = clock();
	shell(items1, count);
	clock_t end = clock();
	double t1 = (double)(end - start) / CLOCKS_PER_SEC;

	out.open("СОРТИРОВКА.txt", std::ios_base::app);
	out << "После сортировки:\n";
	for (int i = 0; i < count; i++) {
		out << items1[i] << " ";
	}
	out << "\n\n";

	// 2. Возрастающая
	int* items2 = new int[count];
	for (int i = 0; i < count; i++) {
		items2[i] = i;
	}
	out << "Массив, состоящий из возрастающей последовательности:\n";
	out << "До сортировки:\n";
	for (int i = 0; i < count; i++) {
		out << items2[i] << " ";
	}
	out << "\n\n";

	start = clock();
	shell(items2, count);
	end = clock();
	double t2 = (double)(end - start) / CLOCKS_PER_SEC;

	out << "После сортировки:\n";
	for (int i = 0; i < count; i++) {
		out << items2[i] << " ";
	}
	out << "\n\n";

	// 3. Убывающая
	int* items3 = new int[count];
	for (int i = 0; i < count; i++) {
		items3[i] = count - i;
	}

	out << "Массив, состоящий из убывающей последовательности:\n";
	out << "До сортировки:\n";
	for (int i = 0; i < count; i++) {
		out << items3[i] << " ";
	}
	out << "\n\n";

	start = clock();
	shell(items3, count);
	end = clock();
	double t3 = (double)(end - start) / CLOCKS_PER_SEC;

	out << "После сортировки:\n";
	for (int i = 0; i < count; i++) {
		out << items3[i] << " ";
	}
	out << "\n\n";

	// 4. Смешанная
	int* items4 = new int[count];
	for (int i = 0; i < count / 2; i++) {
		items4[i] = i;
	}
	for (int i = count / 2; i < count; i++) {
		items4[i] = count - i;
	}

	out << "Массив, состоящий из смешанной последовательности:\n";
	out << "До сортировки:\n";
	for (int i = 0; i < count; i++) {
		out << items4[i] << " ";
	}
	out << "\n\n";

	start = clock();
	shell(items4, count);
	end = clock();
	double t4 = (double)(end - start) / CLOCKS_PER_SEC;

	out << "После сортировки:\n";
	for (int i = 0; i < count; i++) {
		out << items4[i] << " ";
	}
	out << "\n\n";


	//QSsort
	// 1. Рандомные числа
	int* arr1 = new int[count];
	srand(time(0));
	for (int i = 0; i < count; i++) {
		arr1[i] = rand() % 100;
	}
	out << "QS сортировка:\n";
	out << "Массив из рандомных чисел:\n";
	out << "До сортировки:\n";
	for (int i = 0; i < count; i++) {
		out << arr1[i] << " ";
	}
	out << "\n\n";

	start = clock();
	qs(arr1, 0, count - 1);
	end = clock();
	double time1 = (double)(end - start) / CLOCKS_PER_SEC;

	out << "После сортировки:\n";
	for (int i = 0; i < count; i++) {
		out << arr1[i] << " ";
	}
	out << "\n\n";

	// 2. Возрастающая последовательность
	int* arr2 = new int[count];
	for (int i = 0; i < count; i++) {
		arr2[i] = i;
	}

	out << "Массив, состоящий из возрастающей последовательности:\n";
	out << "До сортировки:\n";
	for (int i = 0; i < count; i++) {
		out << arr2[i] << " ";
	}
	out << "\n\n";

	start = clock();
	qs(arr2, 0, count - 1);
	end = clock();
	double time2 = (double)(end - start) / CLOCKS_PER_SEC;

	out << "После сортировки:\n";
	for (int i = 0; i < count; i++) {
		out << arr2[i] << " ";
	}
	out << "\n\n";

	// 3. Убывающая последовательность
	int* arr3 = new int[count];
	for (int i = 0; i < count; i++) {
		arr3[i] = count - i;
	}

	out << "Массив, состоящий из убывающей последовательности:\n";
	out << "До сортировки:\n";
	for (int i = 0; i < count; i++) {
		out << arr3[i] << " ";
	}
	out << "\n\n";

	start = clock();
	qs(arr3, 0, count - 1);
	end = clock();
	double time3 = (double)(end - start) / CLOCKS_PER_SEC;

	out << "После сортировки:\n";
	for (int i = 0; i < count; i++) {
		out << arr3[i] << " ";
	}
	out << "\n\n";

	// 4. Смешанная последовательность
	int* arr4 = new int[count];
	for (int i = 0; i < count /
		2; i++) {
		arr4[i] = i;
	}
	for (int i = count / 2; i < count; i++) {
		arr4[i] = count - i;
	}

	out << "Массив, состоящий из смешанной последовательности:\n";
	out << "До сортировки:\n";
	for (int i = 0; i < count; i++) {
		out << arr4[i] << " ";
	}
	out << "\n\n";

	start = clock();
	qs(arr4, 0, count - 1);
	end = clock();
	double time4 = (double)(end - start) / CLOCKS_PER_SEC;

	out << "После сортировки:\n";
	for (int i = 0; i < count; i++) {
		out << arr4[i] << " ";
	}
	out << "\n\n";

	//BAZsort
	// 1. Рандомные числа
	int* add1 = new int[count];
	srand(time(0));
	for (int i = 0; i < count; i++) {
		add1[i] = rand() % 100;
	}
	out << "BAZ сортировка:\n";
	out << "Массив из рандомных чисел:\n";
	out << "До сортировки:\n";
	for (int i = 0; i < count; i++) {
		out << add1[i] << " ";
	}
	out << "\n\n";

	start = clock();
	qsort(add1, count, sizeof(int), qsortRecursive);
	end = clock();
	double tm1 = (double)(end - start) / CLOCKS_PER_SEC;

	/*clock_t tm1 = clock();
	qsortRecursive(add1, count);
	tm1 = clock() - tm1;*/

	out << "После сортировки:\n";
	for (int i = 0; i < count; i++) {
		out << add1[i] << " ";
	}
	out << "\n\n";

	// 2. Возрастающая
	int* add2 = new int[count];
	for (int i = 0; i < count; i++) {
		add2[i] = i;
	}
	out << "Массив, состоящий из возрастающей последовательности:\n";
	out << "До сортировки:\n";
	for (int i = 0; i < count; i++) {
		out << add2[i] << " ";
	}
	out << "\n\n";

	start = clock();
	//qsortRecursive(add2, count);
	qsort(add2, count, sizeof(int), qsortRecursive);
	end = clock();
	double tm2 = (double)(end - start) / CLOCKS_PER_SEC;

	out << "После сортировки:\n";
	for (int i = 0; i < count; i++) {
		out << add2[i] << " ";
	}
	out << "\n\n";

	// 3. Убывающая
	int* add3 = new int[count];
	for (int i = 0; i < count; i++) {
		add3[i] = count - i;
	}

	out << "Массив, состоящий из убывающей последовательности:\n";
	out << "До сортировки:\n";
	for (int i = 0; i < count; i++) {
		out << add3[i] << " ";
	}
	out << "\n\n";

	start = clock();
	//qsortRecursive(add3, count);
	qsort(add3, count, sizeof(int), qsortRecursive);
	end = clock();
	double tm3 = (double)(end - start) / CLOCKS_PER_SEC;

	out << "После сортировки:\n";
	for (int i = 0; i < count; i++) {
		out << add3[i] << " ";
	}
	out << "\n\n";

	// 4. Смешанная
	int* add4 = new int[count];
	for (int i = 0; i < count / 2; i++) {
		add4[i] = i;
	}
	for (int i = count / 2; i < count; i++) {
		add4[i] = count - i;
	}

	out << "Массив, состоящий из смешанной последовательности:\n";
	out << "До сортировки:\n";
	for (int i = 0; i < count; i++) {
		out << add4[i] << " ";
	}
	out << "\n\n";

	start = clock();
	qsort(add4, count, sizeof(int), qsortRecursive);
	end = clock();
	double tm4 = (double)(end - start) / CLOCKS_PER_SEC;

	out << "После сортировки:\n";
	for (int i = 0; i < count; i++) {
		out << add4[i] << " ";
	}
	out << "\n\n";


	// Вывод времени
	
	printf("| Вид сортировки\t| Рандомные числа\t| Возрастающая\t| Убывающая\t| Смешанная\t|\n");
	printf("|-----------------------|-----------------------|---------------|---------------|---------------|\n");
	printf("| SHELL \t\t| %15f \t| %10f \t| %10f \t| %10f \t|\n", t1, t2, t3, t4);
	printf("|-----------------------|-----------------------|---------------|---------------|---------------|\n");
	printf("| QS      \t\t| %15f \t| %10f \t| %10f \t| %10f \t|\n", time1, time2, time3, time4);
	printf("|-----------------------|-----------------------|---------------|---------------|---------------|\n");
	printf("| Базовая \t\t| %15f \t| %10f \t| %10f \t| %10f \t|\n", tm1, tm2, tm3, tm4);
	printf("|-----------------------|-----------------------|---------------|---------------|---------------|\n");

	getchar();
	getchar();
}