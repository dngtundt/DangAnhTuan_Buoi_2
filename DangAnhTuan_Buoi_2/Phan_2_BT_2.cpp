#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define MAX_SIZE 100

typedef struct {
    int integer;
    int numerator;
    int denominator;
} MixedNumber;

// Hàm tạo hỗn số ngẫu nhiên
MixedNumber generate_random_mixed_number() {
    MixedNumber mn;
    mn.integer = rand() % 100; // Phần nguyên từ 0 đến 99
    mn.numerator = rand() % 100; // Tử số từ 0 đến 99
    mn.denominator = (rand() % 99) + 1; // Mẫu số từ 1 đến 99
    return mn;
}

// Hàm tạo Mang hỗn số ngẫu nhiên
void generate_random_mixed_array(MixedNumber* b, int n) {
    for (int i = 0; i < n; i++) {
        b[i] = generate_random_mixed_number();
    }
}

// Hàm xuất danh sách hỗn số
void print_mixed_array(MixedNumber* b, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d %d/%d\n", b[i].integer, b[i].numerator, b[i].denominator);
    }
}

// Hàm hiển thị menu
void display_menu() {
    printf("=== MENU ===\n");
    printf("1. Tao mang hon so ngau nhien\n");
    printf("2. Xuat danh sach hon so\n");
    printf("0. Thoat\n");
    printf("==============\n");
}

int main() {
    srand(time(NULL));

    int n = 0;
    MixedNumber b[MAX_SIZE];
    int choice;

    while (1) {
        display_menu();
        printf("Chon chuc nang: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Nhap so luong phan tu cua Mang: ");
            scanf("%d", &n);
            generate_random_mixed_array(b, n);
            printf("Mang hon so ngau nhien da duoc tao.\n");
            break;

        case 2:
            if (n == 0) {
                printf("Hay tao mang hon so truoc!\n");
            }
            else {
                printf("Danh sach hon so:\n");
                print_mixed_array(b, n);
            }
            break;

        case 0:
            printf("Thoat chuong trinh.\n");
            exit(0);

        default:
            printf("Lua chon khong hop le!\n");
            break;
        }
    }

    return 0;
}
