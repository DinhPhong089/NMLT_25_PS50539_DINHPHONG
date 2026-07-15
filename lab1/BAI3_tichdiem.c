#include <stdio.h>
#include <string.h>

int main() {
    // Khai báo các biến lưu trữ
    char mssv[50];
    char hoTen[100];
    float diemToan, diemLy, diemHoa, diemTrungBinh;

    // Nhập dữ liệu từ bàn phím
    printf("Nhap ma so sinh vien: ");
    fgets(mssv, sizeof(mssv), stdin);
    mssv[strcspn(mssv, "\n")] = '\0'; // Xóa ký tự xuống dòng do fgets nhận vào

    printf("Nhap ho va ten: ");
    fgets(hoTen, sizeof(hoTen), stdin);
    hoTen[strcspn(hoTen, "\n")] = '\0'; // Xóa ký tự xuống dòng

    printf("Nhap diem Toan: ");
    scanf("%f", &diemToan);

    printf("Nhap diem Ly: ");
    scanf("%f", &diemLy);

    printf("Nhap diem Hoa: ");
    scanf("%f", &diemHoa);

    // Tính điểm trung bình (Toán hệ số 2)
    diemTrungBinh = (diemToan * 2 + diemLy + diemHoa) / 4;

    printf("\n--- KET QUA ---\n");
    // Xuất dữ liệu ra màn hình theo đúng định dạng mẫu
    printf("Ma so sinh vien: %s\n", mssv);
    printf("Ho Va Ten: %s\n", hoTen);
    
    // %.2f giúp làm tròn và hiển thị đúng 2 chữ số thập phân (ví dụ: 8.50)
    // Nếu muốn 1 chữ số thập phân, bạn sửa thành %.1f
    printf("Diem Trung Binh: %.2f\n", diemTrungBinh);

    return 0;
}