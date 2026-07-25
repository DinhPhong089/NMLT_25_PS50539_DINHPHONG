#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_SV 50

//================ CHUC NANG 1 =================
void checkSoNguyen() {
    float so;

    printf("\n===== KIEM TRA SO NGUYEN =====\n");
    printf("Nhap vao mot so: ");
    scanf("%f", &so);

    if (so == (int)so)
        printf("%.0f la so nguyen.\n", so);
    else
        printf("%.2f khong phai la so nguyen.\n", so);
}

//================ CHUC NANG 2 =================
int timUCLN(int x, int y) {
    while (y != 0) {
        int du = x % y;
        x = y;
        y = du;
    }
    return abs(x);
}

void tinhUocBoi() {
    int so1, so2;

    printf("\n===== TIM UCLN VA BCNN =====\n");
    printf("Nhap so thu nhat: ");
    scanf("%d", &so1);

    printf("Nhap so thu hai: ");
    scanf("%d", &so2);

    if (so1 == 0 || so2 == 0) {
        printf("Khong tinh duoc BCNN.\n");
        return;
    }

    int ucln = timUCLN(so1, so2);
    long long bcnn = (long long)abs(so1 / ucln) * abs(so2);

    printf("UCLN = %d\n", ucln);
    printf("BCNN = %lld\n", bcnn);
}

//================ CHUC NANG 3 =================
void tinhTienKaraoke() {
    int batDau, ketThuc;
    float tongTien;

    printf("\n===== TINH TIEN KARAOKE =====\n");
    printf("Nhap gio bat dau (12-23): ");
    scanf("%d", &batDau);

    printf("Nhap gio ket thuc (12-23): ");
    scanf("%d", &ketThuc);

    if (batDau < 12 || ketThuc > 23 || ketThuc <= batDau) {
        printf("Thoi gian khong hop le!\n");
        return;
    }

    int soGio = ketThuc - batDau;
    tongTien = soGio * 150000;

    if (soGio > 3)
        tongTien -= (soGio - 3) * 150000 * 0.3;

    if (batDau >= 14 && batDau <= 17)
        tongTien *= 0.9;

    printf("Tong tien can thanh toan: %.0f VND\n", tongTien);
}

//================ CHUC NANG 4 =================
void tinhTienDien() {
    float kWh, tien = 0;

    printf("\n===== TINH TIEN DIEN =====\n");
    printf("Nhap so dien da su dung: ");
    scanf("%f", &kWh);

    if (kWh < 0) {
        printf("So dien khong hop le!\n");
        return;
    }

    if (kWh <= 50)
        tien = kWh * 1678;
    else if (kWh <= 100)
        tien = 50 * 1678 + (kWh - 50) * 1734;
    else if (kWh <= 200)
        tien = 50 * 1678 + 50 * 1734 + (kWh - 100) * 2014;
    else if (kWh <= 300)
        tien = 50 * 1678 + 50 * 1734 + 100 * 2014 + (kWh - 200) * 2536;
    else if (kWh <= 400)
        tien = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + (kWh - 300) * 2834;
    else
        tien = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + 100 * 2834 + (kWh - 400) * 2927;

    printf("Tien dien phai tra: %.0f VND\n", tien);
}

//================ CHUC NANG 6 =================
void bangTraGop() {
    float soTienConLai = 500000000;
    float laiSuat = 0.05 / 12;
    float tienGoc = soTienConLai / 288;

    printf("\n===== BANG TRA GOP 24 NAM =====\n");
    printf("%-5s %-15s %-15s %-15s %-15s\n",
           "Thang", "Goc", "Lai", "Tong", "Con lai");

    for (int i = 1; i <= 288; i++) {
        float tienLai = soTienConLai * laiSuat;
        float tongTra = tienGoc + tienLai;

        soTienConLai -= tienGoc;

        if (soTienConLai < 0)
            soTienConLai = 0;

        printf("%-5d %-15.0f %-15.0f %-15.0f %-15.0f\n",
               i, tienGoc, tienLai, tongTra, soTienConLai);
    }
}

//================ CHUC NANG 8 =================
typedef struct {
    char ten[30];
    float diem;
} SinhVien;

void sapXepDanhSach() {
    int n;

    printf("\n===== SAP XEP SINH VIEN =====\n");
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_SV) {
        printf("So luong khong hop le!\n");
        return;
    }

    SinhVien danhSach[MAX_SV];

    for (int i = 0; i < n; i++) {
        printf("\nSinh vien %d\n", i + 1);

        printf("Nhap ten: ");
        scanf(" %[^\n]", danhSach[i].ten);

        printf("Nhap diem: ");
        scanf("%f", &danhSach[i].diem);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (danhSach[j].diem < danhSach[j + 1].diem) {
                SinhVien temp = danhSach[j];
                danhSach[j] = danhSach[j + 1];
                danhSach[j + 1] = temp;
            }
        }
    }

    printf("\n%-5s %-25s %-10s %-15s\n",
           "STT", "Ho va ten", "Diem", "Xep loai");

    for (int i = 0; i < n; i++) {
        char xepLoai[20];

        if (danhSach[i].diem >= 9)
            strcpy(xepLoai, "Xuat sac");
        else if (danhSach[i].diem >= 8)
            strcpy(xepLoai, "Gioi");
        else if (danhSach[i].diem >= 6.5)
            strcpy(xepLoai, "Kha");
        else if (danhSach[i].diem >= 5)
            strcpy(xepLoai, "Trung binh");
        else
            strcpy(xepLoai, "Yeu");

        printf("%-5d %-25s %-10.1f %-15s\n",
               i + 1,
               danhSach[i].ten,
               danhSach[i].diem,
               xepLoai);
    }
}

//================ MAIN =================
int main() {
    int luaChon;

    do {
        printf("\n===================================\n");
        printf("         CHUONG TRINH LAB\n");
        printf("===================================\n");
        printf("1. Kiem tra so nguyen\n");
        printf("2. Tim UCLN va BCNN\n");
        printf("3. Tinh tien Karaoke\n");
        printf("4. Tinh tien dien\n");
        printf("6. Bang tra gop ngan hang\n");
        printf("8. Sap xep sinh vien\n");
        printf("0. Thoat\n");
        printf("===================================\n");
        printf("Nhap lua chon: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                checkSoNguyen();
                break;

            case 2:
                tinhUocBoi();
                break;

            case 3:
                tinhTienKaraoke();
                break;

            case 4:
                tinhTienDien();
                break;

            case 6:
                bangTraGop();
                break;

            case 8:
                sapXepDanhSach();
                break;

            case 0:
                printf("Cam on ban da su dung chuong trinh!\n");
                break;

            default:
                printf("Lua chon khong hop le!\n");
        }

    } while (luaChon != 0);

    return 0;
}