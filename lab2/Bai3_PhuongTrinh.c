#include <stdio.h>

int main() {
    float a, b, x;

    printf("Nhap a: ");
    scanf("%f", &a);

    printf("Nhap b: ");
    scanf("%f", &b);

    x = -b / a;

    printf("Nghiem x = %.2f", x);

    return 0;
}