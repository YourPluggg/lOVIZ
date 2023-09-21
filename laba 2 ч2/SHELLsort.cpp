void shell(int* items, int count) {

    int i, j, gap, k;
    int x, a[5];
    a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;

    for (k = 0; k < 5; k++) {
        gap = a[k];
        for (i = gap; i < count; ++i) {
            x = items[i];
            for (j = i - gap; (x < items[j]) && (j >= 0); j = j - gap) {
                items[j + gap] = items[j];
            }
            items[j + gap] = x;
        }
    }
}

