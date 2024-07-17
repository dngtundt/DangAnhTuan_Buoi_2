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
// Hàm tìm kiếm nhị phân
int binary_search(int* a, int n, int x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] == x) {
            return mid;
        }
        else if (a[mid] < x) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

// Hàm sắp xếp Selection Sort
void selection_sort(int* a, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min_idx]) {
                min_idx = j;
            }
        }
        int temp = a[i];
        a[i] = a[min_idx];
        a[min_idx] = temp;
    }
}
// Hàm sắp xếp Quick Sort
void quick_sort(int* a, int left, int right) {
    if (left >= right) {
        return;
    }
    int pivot = a[(left + right) / 2];
    int i = left, j = right;
    while (i <= j) {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;
        if (i <= j) {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }
    quick_sort(a, left, j);
    quick_sort(a, i, right);
}