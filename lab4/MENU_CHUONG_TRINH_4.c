#include <stdio.h>
#include <math.h>

int main() {
    int chon;

    printf("+----------------------------------+\n");
    printf("|       MENU CHUONG TRINH LAB4    |\n");
    printf("+----------------------------------+\n");
    printf("| 1. Tinh trung binh so chan      |\n");
    printf("| 2. Kiem tra so nguyen to        |\n");
    printf("| 3. Kiem tra so chinh phuong     |\n");
    printf("| 4. Thoat                        |\n");
    printf("+----------------------------------+\n");

    printf("Nhap lua chon: ");
    scanf("%d", &chon);

    switch (chon) {
        case 1:
            printf("Ban da chon tinh trung binh cac so chia het cho 2\n");
            break;

        case 2:
            printf("Ban da chon kiem tra so nguyen to\n");
            break;

        case 3:
            printf("Ban da chon kiem tra so chinh phuong\n");
            break;

        case 4:
            printf("Da thoat chuong trinh\n");
            break;

        default:
            printf("Lua chon khong hop le\n");
            break;
    }

    int min, max;

    if (chon == 1) {
        printf("Nhap vao min va max: ");
        scanf("%d %d", &min, &max);

        if (min > max) {
            printf("Nhap sai! Min phai nho hon Max");
        }
        else {
            int tong = 0;
            int dem = 0;

            for (int i = min; i <= max; i++) {
                if (i % 2 == 0) {
                    tong = tong + i;
                    dem++;
                }
            }

            if (dem != 0) {
                printf("Trung binh cac so chia het cho 2 la: %.2f",
                       (float)tong / dem);
            }
            else {
                printf("Khong co so nao chia het cho 2");
            }
        }
    }

    int x;

    if (chon == 2) {
        printf("Nhap vao so can kiem tra: ");
        scanf("%d", &x);

        if (x < 2) {
            printf("Khong phai la so nguyen to");
        }
        else {
            int nguyento = 1;

            for (int i = 2; i <= sqrt(x); i++) {
                if (x % i == 0) {
                    nguyento = 0;
                    break;
                }
            }

            if (nguyento == 1) {
                printf("La so nguyen to");
            }
            else {
                printf("Khong phai la so nguyen to");
            }
        }
    }

    if (chon == 3) {
        int x;
        int can;

        printf("Nhap vao so can kiem tra: ");
        scanf("%d", &x);

        if (x < 0) {
            printf("Khong phai la so chinh phuong");
        }
        else {
            can = sqrt(x);

            if (can * can == x) {
                printf("La so chinh phuong");
            }
            else {
                printf("Khong la so chinh phuong");
            }
        }
    }

    return 0;
}