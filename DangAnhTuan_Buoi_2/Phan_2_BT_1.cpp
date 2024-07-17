//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//#define MAX_SIZE 100
//
//// Hàm tạo mảng ngẫu nhiên
//void generate_random_array(int* a, int n, int min, int max) {
//    for (int i = 0; i < n; i++) {
//        a[i] = min + rand() % (max - min + 1);
//    }
//}
//
//// Hàm tạo mảng chứa toàn số chẵn
//void generate_even_array(int* a, int* b, int n, int* m) {
//    *m = 0;
//    for (int i = 0; i < n; i++) {
//        if (a[i] % 2 == 0) {
//            b[*m] = a[i];
//            (*m)++;
//        }
//    }
//}
//// Hàm tìm kiếm tuyến tính
//int linear_search(int* a, int n, int x) {
//    for (int i = 0; i < n; i++) {
//        if (a[i] == x) {
//            return i;
//        }
//    }
//    return -1;
//}
//
//// Hàm sắp xếp Interchange Sort
//void interchange_sort(int* a, int n, int ascending) {
//    for (int i = 0; i < n - 1; i++) {
//        for (int j = i + 1; j < n; j++) {
//            if (ascending ? a[i] > a[j] : a[i] < a[j]) {
//                int temp = a[i];
//                a[i] = a[j];
//                a[j] = temp;
//            }
//        }
//    }
//}
//// Hàm tìm kiếm nhị phân
//int binary_search(int* a, int n, int x) {
//    int left = 0, right = n - 1;
//    while (left <= right) {
//        int mid = left + (right - left) / 2;
//        if (a[mid] == x) {
//            return mid;
//        }
//        else if (a[mid] < x) {
//            left = mid + 1;
//        }
//        else {
//            right = mid - 1;
//        }
//    }
//    return -1;
//}
//
//// Hàm sắp xếp Selection Sort
//void selection_sort(int* a, int n) {
//    for (int i = 0; i < n - 1; i++) {
//        int min_idx = i;
//        for (int j = i + 1; j < n; j++) {
//            if (a[j] < a[min_idx]) {
//                min_idx = j;
//            }
//        }
//        int temp = a[i];
//        a[i] = a[min_idx];
//        a[min_idx] = temp;
//    }
//}
//// Hàm sắp xếp Quick Sort
//void quick_sort(int* a, int left, int right) {
//    if (left >= right) {
//        return;
//    }
//    int pivot = a[(left + right) / 2];
//    int i = left, j = right;
//    while (i <= j) {
//        while (a[i] < pivot) i++;
//        while (a[j] > pivot) j--;
//        if (i <= j) {
//            int temp = a[i];
//            a[i] = a[j];
//            a[j] = temp;
//            i++;
//            j--;
//        }
//    }
//    quick_sort(a, left, j);
//    quick_sort(a, i, right);
//}
//// Hàm in mảng
//void print_array(int* a, int n) {
//    for (int i = 0; i < n; i++) {
//        printf("%d ", a[i]);
//    }
//    printf("\n");
//}
//
//// Hàm hiển thị menu
//void display_menu() {
//    printf("=== MENU ===\n");
//    printf("1. Generate random array\n");
//    printf("2. Generate even array\n");
//    printf("3. Tim kiem tuyen tinh\n");
//    printf("4. Sap xep tang dan Interchange Sort\n");
//    printf("5. Sap xep giam dan Interchange Sort\n");
//    printf("6. Tim kiem nhi phan\n");
//    printf("7. Sap xep tang dan Selection Sort\n");
//    printf("8. Sap xep tang dan Quick Sort\n");
//    printf("9. Exit\n");
//    printf("==============\n");
//}
//
//int main() {
//    srand(time(NULL));
//
//    int n = 0;
//    int a[MAX_SIZE];
//    int b[MAX_SIZE];
//    int m = 0;
//    int choice;
//    int x;
//
//    while (1) {
//        display_menu();
//        printf("Chon chuc nang: ");
//        scanf("%d", &choice);
//
//        switch (choice) {
//        case 1:
//            printf("Nhap so luong cua mang (>= 15): ");
//            scanf("%d", &n);
//            if (n < 15) {
//                printf("So luong phan tu phai lon hon hoac bang 15!\n");
//            }
//            else {
//                generate_random_array(a, n, 0, 100);
//                printf("mang ngau nhien: ");
//                print_array(a, n);
//            }
//            break;
//
//        case 2:
//            if (n == 0) {
//                printf("Hay tao mang ngau nhien truoc!\n");
//            }
//            else {
//                generate_even_array(a, b, n, &m);
//                printf("Mang chua toan so chan: ");
//                print_array(b, m);
//            }
//            break;
//
//        case 3:
//            if (n == 0) {
//                printf("Hay tao mang ngau nhien truoc!\n");
//            }
//            else {
//                printf("Nhap gia tri can tim: ");
//                scanf("%d", &x);
//                int index = linear_search(a, n, x);
//                if (index != -1) {
//                    printf("Tim thay %d o vi tri %d bang Linear Search.\n", x, index);
//                }
//                else {
//                    printf("Khong tim thay %d bang Linear Search.\n", x);
//                }
//            }
//            break;
//
//        case 4:
//            if (n == 0) {
//                printf("Hay tao mang ngau nhien truoc!\n");
//            }
//            else {
//                interchange_sort(a, n, 1);
//                printf("Mang sau khi sap xep tang dan bang Interchange Sort: ");
//                print_array(a, n);
//            }
//            break;
//
//        case 5:
//            if (n == 0) {
//                printf("Hay tao mang ngau nhien truoc!\n");
//            }
//            else {
//                interchange_sort(a, n, 0);
//                printf("Mang sau khi sap xep giam dan bang Interchange Sort: ");
//                print_array(a, n);
//            }
//            break;
//
//        case 6:
//            if (n == 0) {
//                printf("Hay tao mang ngau nhien truoc!\n");
//            }
//            else {
//                interchange_sort(a, n, 1);
//                printf("Nhap gia tri can tim: ");
//                scanf("%d", &x);
//                int index = binary_search(a, n, x);
//                if (index != -1) {
//                    printf("Tim thay %d o vi tri %d bang Binary Search.\n", x, index);
//                }
//                else {
//                    printf("Khong tim thay %d bang Binary Search.\n", x);
//                }
//            }
//            break;
//
//        case 7:
//            if (n == 0) {
//                printf("Hay tao mang ngau nhien truoc!\n");
//            }
//            else {
//                selection_sort(a, n);
//                printf("Mang sau khi sap xep tang dan bang Selection Sort: ");
//                print_array(a, n);
//            }
//            break;
//
//        case 8:
//            if (n == 0) {
//                printf("Hay tao mang ngau nhien truoc!\n");
//            }
//            else {
//                quick_sort(a, 0, n - 1);
//                printf("Mang sau khi sap xep tang dan bang Quick Sort: ");
//                print_array(a, n);
//            }
//            break;
//
//        case 9:
//            printf("Thoat chuong trinh.\n");
//            exit(0);
//
//        default:
//            printf("Lua chon khong hop le!\n");
//            break;
//        }
//    }
//
//    return 0;
//}
