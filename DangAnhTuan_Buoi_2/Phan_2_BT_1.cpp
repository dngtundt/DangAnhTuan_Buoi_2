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
// Hàm tìm kiếm tuyến tính
int linear_search(int* a, int n, int x) {
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            return i;
        }
    }
    return -1;
}

// Hàm sắp xếp Interchange Sort
void interchange_sort(int* a, int n, int ascending) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ascending ? a[i] > a[j] : a[i] < a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}