#include <stdio.h>
#include <math.h>

int main() {
    int chon;
    float diem;
    float a, b, c;
    float delta, x1, x2;
    float kwh;
    double tienDien;

    // Menu
    printf("========== MENU ==========\n");
    printf("1. Tinh hoc luc\n");
    printf("2. Giai phuong trinh bac hai\n");
    printf("3. Tinh tien dien\n");
    printf("4. Thoat\n");
    printf("==========================\n");
    printf("Nhap lua chon: ");
    scanf("%d", &chon);

    switch (chon) {

    case 1:
        printf("\n=== TINH HOC LUC ===\n");
        printf("Nhap diem: ");
        scanf("%f", &diem);

        if (diem < 0 || diem > 10) {
            printf("Diem khong hop le!\n");
        }
        else if (diem >= 9) {
            printf("Hoc luc: Xuat sac\n");
        }
        else if (diem >= 8) {
            printf("Hoc luc: Gioi\n");
        }
        else if (diem >= 6.5) {
            printf("Hoc luc: Kha\n");
        }
        else if (diem >= 5) {
            printf("Hoc luc: Trung binh\n");
        }
        else if (diem >= 3.5) {
            printf("Hoc luc: Yeu\n");
        }
        else {
            printf("Hoc luc: Kem\n");
        }
        break;

    case 2:
        printf("\n=== GIAI PHUONG TRINH BAC HAI ===\n");

        printf("Nhap a: ");
        scanf("%f", &a);

        printf("Nhap b: ");
        scanf("%f", &b);

        printf("Nhap c: ");
        scanf("%f", &c);

        if (a == 0) {
            if (b == 0) {
                if (c == 0)
                    printf("Phuong trinh vo so nghiem\n");
                else
                    printf("Phuong trinh vo nghiem\n");
            }
            else {
                printf("x = %.2f\n", -c / b);
            }
        }
        else {
            delta = b * b - 4 * a * c;

            if (delta < 0) {
                printf("Phuong trinh vo nghiem\n");
            }
            else if (delta == 0) {
                printf("Nghiem kep x = %.2f\n", -b / (2 * a));
            }
            else {
                x1 = (-b + sqrt(delta)) / (2 * a);
                x2 = (-b - sqrt(delta)) / (2 * a);

                printf("x1 = %.2f\n", x1);
                printf("x2 = %.2f\n", x2);
            }
        }
        break;

    case 3:
        printf("\n=== TINH TIEN DIEN ===\n");

        printf("Nhap so kWh: ");
        scanf("%f", &kwh);

        tienDien = 0;

        if (kwh < 0) {
            printf("Du lieu khong hop le!\n");
        }
        else if (kwh <= 50) {
            tienDien = kwh * 1678;
        }
        else if (kwh <= 100) {
            tienDien = 50 * 1678 + (kwh - 50) * 1734;
        }
        else if (kwh <= 200) {
            tienDien = 50 * 1678 + 50 * 1734 + (kwh - 100) * 2014;
        }
        else if (kwh <= 300) {
            tienDien = 50 * 1678 + 50 * 1734 + 100 * 2014 + (kwh - 200) * 2536;
        }
        else if (kwh <= 400) {
            tienDien = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + (kwh - 300) * 2834;
        }
        else {
            tienDien = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + 100 * 2834 + (kwh - 400) * 2927;
        }

        if (kwh >= 0) {
            printf("Tien dien: %.0lf dong\n", tienDien);
        }

        break;

    case 4:
        printf("Tam biet!\n");
        break;

    default:
        printf("Lua chon khong hop le!\n");
    }

    return 0;
}
