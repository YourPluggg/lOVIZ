void qs(int* chasti, int left, int right)
{
    // Создаем стек 
    int stack[100];
    int top = -1;
    int x, y;
    int j, i;

    // Добавляем начальные значения в стек
    stack[++top] = left;
    stack[++top] = right;

    // Пока стек не пуст
    while (top >= 0) {
        // Извлекаем пару индексов из стека
        right = stack[top--];
        left = stack[top--];

        i = left; j = right;
        x = chasti[(left + right) / 2];
        do {
            while ((chasti[i] < x) && (i < right)) i++;
            while ((x < chasti[j]) && (j > left)) j--;

            if (i <= j) {
                y = chasti[i];
                chasti[i] = chasti[j];
                chasti[j] = y;
                i++; j--;
            }
        } while (i <= j);

        // Добавляем новые пары индексов в стек
        if (left < j) {
            stack[++top] = left;
            stack[++top] = j;
        }
        if (i < right) {
            stack[++top] = i;
            stack[++top] = right;
        }
    }
}




