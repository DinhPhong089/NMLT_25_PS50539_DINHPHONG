#include <stdio.h>

int main() {
    // Khai báo các biến để lưu trữ thông tin
    char mssv[20];
    char ho_ten[50];
    int nam_sinh;
    int tuoi;
    float diem_tb;

    // 1. Nhập dữ liệu từ bàn phím
    printf("Nhập Mã số sinh viên: ");
    scanf("%19s", mssv); 
    
    // Xóa bộ nhớ đệm để tránh lỗi khi nhập chuỗi có khoảng trắng tiếp theo
    while (getchar() != '\n'); 

    printf("Nhập Họ và Tên: ");
    fgets(ho_ten, sizeof(ho_ten), stdin);
    
    // Loại bỏ ký tự xuống dòng '\n' do fgets tự động thêm vào cuối chuỗi
    for (int i = 0; ho_ten[i] != '\0'; i++) {
        if (ho_ten[i] == '\n') {
            ho_ten[i] = '\0';
            break;
        }
    }

    printf("Nhập Năm sinh: ");
    scanf("%d", &nam_sinh);

    printf("Nhập Điểm trung bình: ");
    scanf("%f", &diem_tb);

    // 2. Tự động tính toán số tuổi (Cố định năm 2026)
    tuoi = 2026 - nam_sinh;

    // 3. Xuất kết quả theo định dạng yêu cầu
    printf("\n--- THÔNG TIN SINH VIÊN ---\n");
    printf("Ma so sinh vien: %s\n", mssv);
    printf("Ho Va Ten: %s\n", ho_ten);
    printf("Nam sinh: %d\n", nam_sinh);
    printf("Tuoi: %d\n", tuoi);
    printf("Diem Trung Binh: %.2f\n", diem_tb); // %.2f để lấy 2 chữ số thập phân

    return 0;
}