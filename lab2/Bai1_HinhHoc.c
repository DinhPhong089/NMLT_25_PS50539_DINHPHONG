#include <stdio.h>

#define PI 3.14

int main() {
    float dai, rong, r;

    // Hình chữ nhật
    printf("Nhap chieu dai: ");
    scanf("%f", &dai);

    printf("Nhap chieu rong: ");
    scanf("%f", &rong);

    printf("Chu vi HCN = %.2f\n", (dai + rong) * 2);
    printf("Dien tich HCN = %.2f\n", dai * rong);

    // Hình tròn
    printf("\nNhap ban kinh: ");
    scanf("%f", &r);

    printf("Chu vi hinh tron = %.2f\n", 2 * PI * r);
    printf("Dien tich hinh tron = %.2f\n", PI * r * r);

    return 0;
}