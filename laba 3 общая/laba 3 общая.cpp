#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

// Структуры данных
typedef struct {
    char lastName[100];
    int priority;
} Student;

typedef struct {
    Student* data;
    int front, rear, size, capacity;
} Queue;

typedef struct {
    Student* data;
    int top, capacity;
} Stack;

int compareStudents(const void* a, const void* b) {
    const Student* studentA = (const Student*)a;
    const Student* studentB = (const Student*)b;

    if (studentA->priority > studentB->priority)
        return -1;
    else if (studentA->priority < studentB->priority)
        return 1;
    else
        return 0;
}

// Функции для работы с очередью
//Создание очереди
Queue* createQueue(int capacity) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->data = (Student*)malloc(capacity * sizeof(Student));
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    q->capacity = capacity;
    return q;
}

//Добавление эл-та в очередь
void enqueue(Queue* q, Student s) {
    if (q->size == q->capacity) {
        printf("Очередь заполнена!");
        return;
    }

    q->rear = (q->rear + 1) % q->capacity;
    q->data[q->rear] = s;
    q->size++;
}

//Извлечение эл-та в очередь
Student dequeue(Queue* q) {
    Student s;
    if (q->size == 0) {
        printf("Очередь пуста!");
    }
    else {
        s = q->data[q->front];
        q->front = (q->front + 1) % q->capacity;
        q->size--;
    }

    return s;
}

// Функции для работы со стеком
// Создание стека
Stack* createStack(int capacity) {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->data = (Student*)malloc(capacity * sizeof(Student));
    s->top = -1;
    s->capacity = capacity;
    return s;
}

// Добавление эл-та в стек
void push(Stack* s, Student student) {
    if (s->top == s->capacity - 1) {
        printf("Стек переполнен!\n");
        return;
    }

    s->top++;
    s->data[s->top] = student;
}

// Извлечение эл-та из стека
Student pop(Stack* s) {
    if (s->top == -1) {
        printf("Стек пуст!\n");
        Student temp = { "", 0 }; // инициализируем пустым студентом
        return temp;
    }

    Student temp = s->data[s->top];
    s->top--;
    return temp;
}

int main() {
    SetConsoleCP(1251);//Установка языка
    SetConsoleOutputCP(1251);
    int choice;

    printf("Выберите структуру данных:\n");
    printf("1 - Приоритетная очередь\n");
    printf("2 - Обычная очередь\n");
    printf("3 - Стек\n");

    scanf("%d", &choice);

    if (choice == 1) {
        int numStudents;
        printf("Введите количество студентов: ");
        scanf("%d", &numStudents);

        Student* students = (Student*)malloc(numStudents * sizeof(Student));

        for (int i = 0; i < numStudents; i++) {
            printf("Введите фамилию и приоритет для студента %d: ", i + 1);
            scanf("%s %d", students[i].lastName, &students[i].priority);
        }

        qsort(students, numStudents, sizeof(Student), compareStudents);

        for (int i = 0; i < numStudents; i++) {
            printf("%s %d\n", students[i].lastName, students[i].priority);
        }

        free(students);

        return 0;
    }
    else if (choice == 2) {
        Queue* q = createQueue(100);

        int n;
        printf("Введите количество студентов: ");
        scanf("%d", &n);

        for (int i = 0; i < n; i++) {
            Student s;
            printf("Введите фамилию и приоритет для студента %d: ", i + 1);
            scanf("%s %d", s.lastName, &s.priority);

            enqueue(q, s);
        }

        while (q->size > 0) {
            Student s = dequeue(q);
            printf("%s %d\n", s.lastName, s.priority);
        }

        return 0;

    }
    else if (choice == 3) {
        Stack* s = createStack(100);

        int n;
        printf("Введите количество студентов: ");
        scanf("%d", &n);

        for (int i = 0; i < n; i++) {
            Student student;
            printf("Введите фамилию и приоритет для студента %d: ", i + 1);
            scanf("%s %d", &student.lastName, &student.priority);

            push(s, student);
        }

        while (s->top != -1) {
            Student temp = pop(s);
            printf("%s %d\n", temp.lastName, temp.priority);
        }

        return 0;

    }
    else {
        printf("Неверный выбор!");
    }

    return 0;
}