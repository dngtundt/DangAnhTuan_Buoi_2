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
// Hàm so sánh 2 hỗn số
int compare_mixed_numbers(MixedNumber a, MixedNumber b) {
    int left = a.integer * b.denominator * a.denominator + a.numerator * b.denominator;
    int right = b.integer * a.denominator * b.denominator + b.numerator * a.denominator;
    if (left > right) return 1;
    else if (left < right) return -1;
    else return 0;
}

// Hàm chuyển hỗn số sang phân số
void mixed_to_fraction(MixedNumber mn, int* numerator, int* denominator) {
    *numerator = mn.integer * mn.denominator + mn.numerator;
    *denominator = mn.denominator;
}

// Hàm chuyển phân số sang hỗn số
MixedNumber fraction_to_mixed(int numerator, int denominator) {
    MixedNumber mn;
    mn.integer = numerator / denominator;
    mn.numerator = numerator % denominator;
    mn.denominator = denominator;
    return mn;
}

// Hàm hiển thị menu
void display_menu() {
    printf("=== MENU ===\n");
    printf("1. Tao mang hon so ngau nhien\n");
    printf("2. Xuat danh sach hon so\n");
    printf("3. So sanh 2 hon so\n");
    printf("4. Chuyen hon so sang phan so\n");
    printf("5. Chuyen phan so sang hon so\n");
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

        case 3: {
            if (n < 2) {
                printf("Hay tao it nhat 2 hon so!\n");
            }
            else {
                int idx1, idx2;
                printf("Nhap vi tri cua hon so thu nhat (0-%d): ", n - 1);
                scanf("%d", &idx1);
                printf("Nhap vi tri cua hon so thu hai (0-%d): ", n - 1);
                scanf("%d", &idx2);
                int result = compare_mixed_numbers(b[idx1], b[idx2]);
                if (result > 0) {
                    printf("Hon so thu nhat lon hon hon so thu hai.\n");
                }
                else if (result < 0) {
                    printf("Hon so thu nhat nho hon hon so thu hai.\n");
                }
                else {
                    printf("Hai hon so bang nhau.\n");
                }
            }
            break;
        }

        case 4: {
            if (n == 0) {
                printf("Hay tao mang hon so truoc!\n");
            }
            else {
                int idx;
                printf("Nhap vi tri cua hon so can chuyen (0-%d): ", n - 1);
                scanf("%d", &idx);
                int numerator, denominator;
                mixed_to_fraction(b[idx], &numerator, &denominator);
                printf("Phan so tuong ung la: %d/%d\n", numerator, denominator);
            }
            break;
        }

        case 5: {
            int numerator, denominator;
            printf("Nhap tu so: ");
            scanf("%d", &numerator);
            printf("Nhap mau so (khac 0): ");
            scanf("%d", &denominator);
            MixedNumber mn = fraction_to_mixed(numerator, denominator);
            printf("Hon so tuong ung la: %d %d/%d\n", mn.integer, mn.numerator, mn.denominator);
            break;
        }

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
