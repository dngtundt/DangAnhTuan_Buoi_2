#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Hàm tạo mảng ngẫu nhiên
void generate_random_array(int* a, int n, int min, int max) {
    for (int i = 0; i < n; i++) {
        a[i] = min + rand() % (max - min + 1);
    }
}

// Hàm tạo mảng chứa toàn số chẵn
void generate_even_array(int* a, int* b, int n, int* m) {
    *m = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            b[*m] = a[i];
            (*m)++;
        }
    }
}