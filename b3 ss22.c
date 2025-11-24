#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
struct Date {
    int day, month, year;
};
struct SinhVien {
    char maSV[20];
    char hoTen[50];
    struct Date ngaySinh;
    char diaChi[100];
    char dienThoai[20];
};
typedef struct SinhVien SinhVien;
void nhap1SV(SinhVien *sv) {
    printf("Nhap ma sinh vien: ");
    fgets(sv->maSV, sizeof(sv->maSV), stdin);
    sv->maSV[strcspn(sv->maSV, "\n")] = '\0';
    printf("Nhap ho ten: ");
    fgets(sv->hoTen, sizeof(sv->hoTen), stdin);
    sv->hoTen[strcspn(sv->hoTen, "\n")] = '\0';
    printf("Nhap ngay sinh (dd mm yyyy): ");
    scanf("%d %d %d", &sv->ngaySinh.day, &sv->ngaySinh.month, &sv->ngaySinh.year);
    getchar();
    printf("Nhap dia chi: ");
    fgets(sv->diaChi, sizeof(sv->diaChi), stdin);
    sv->diaChi[strcspn(sv->diaChi, "\n")] = '\0';
    printf("Nhap dien thoai: ");
    fgets(sv->dienThoai, sizeof(sv->dienThoai), stdin);
    sv->dienThoai[strcspn(sv->dienThoai, "\n")] = '\0';
}
void hien1SV(SinhVien sv) {
    printf("Ma SV: %s\n", sv.maSV);
    printf("Ho ten: %s\n", sv.hoTen);
    printf("Ngay sinh: %02d/%02d/%04d\n", sv.ngaySinh.day, sv.ngaySinh.month, sv.ngaySinh.year);
    printf("Dia chi: %s\n", sv.diaChi);
    printf("Dien thoai: %s\n", sv.dienThoai);
}
int main() {
    SinhVien ds[100];
    int n = 0;
    int choice;
    do {
        printf("\n====== MENU ======\n");
        printf("1. Nhap danh sach sinh vien\n");
        printf("2. Hien thi danh sach sinh vien\n");
        printf("3. Them sinh vien vao cuoi danh sach\n");
        printf("4. Xoa sinh vien theo ma\n");
        printf("5. Cap nhat thong tin theo ma\n");
        printf("6. Sap xep theo ho ten (A-Z)\n");
        printf("7. Tim kiem sinh vien theo ma\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);
        getchar();
        switch(choice) {
        case 1: {
            printf("Nhap so luong sinh vien: ");
            scanf("%d", &n);
            getchar();
            for (int i = 0; i < n; i++) {
                printf("\n--- Sinh vien %d ---\n", i + 1);
                nhap1SV(&ds[i]);
            }
            break;
        }
        case 2:
            if (n == 0) printf("Danh sach rong!\n");
            else {
                printf("\n===== DANH SACH SINH VIEN =====\n");
                for (int i = 0; i < n; i++) {
                    printf("\nSinh vien %d:\n", i + 1);
                    hien1SV(ds[i]);
                }
            }
            break;
        case 3:
            printf("\n=== Them sinh vien ===\n");
            nhap1SV(&ds[n]);
            n++;
            break;
        case 4: {
            char ma[20];
            printf("Nhap ma sinh vien can xoa: ");
            fgets(ma, sizeof(ma), stdin);
            ma[strcspn(ma, "\n")] = '\0';
            int found = 0;
            for (int i = 0; i < n; i++) {
                if (strcmp(ds[i].maSV, ma) == 0) {
                    for (int j = i; j < n - 1; j++)
                        ds[j] = ds[j + 1];
                    n--;
                    found = 1;
                    printf("Xoa thanh cong!\n");
                    break;
                }
            }
            if (!found) printf("Khong tim thay sinh vien!\n");
            break;
        }
        case 5: {
            char ma[20];
            printf("Nhap ma sinh vien can cap nhat: ");
            fgets(ma, sizeof(ma), stdin);
            ma[strcspn(ma, "\n")] = '\0';
            int found = 0;
            for (int i = 0; i < n; i++) {
                if (strcmp(ds[i].maSV, ma) == 0) {
                    printf("\nNhap thong tin moi:\n");
                    nhap1SV(&ds[i]);
                    found = 1;
                    printf("Cap nhat thanh cong!\n");
                    break;
                }
            }
            if (!found) printf("Khong tim thay sinh vien!\n");
            break;
        }
        case 6: {
            for (int i = 0; i < n - 1; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (strcmp(ds[i].hoTen, ds[j].hoTen) > 0) {
                        SinhVien tmp = ds[i];
                        ds[i] = ds[j];
                        ds[j] = tmp;
                    }
                }
            }
            printf("Sap xep thanh cong!\n");
            break;
        }
        case 7: {
            char ma[20];
            printf("Nhap ma sinh vien can tim: ");
            fgets(ma, sizeof(ma), stdin);
            ma[strcspn(ma, "\n")] = '\0';

            int found = 0;
            for (int i = 0; i < n; i++) {
                if (strcmp(ds[i].maSV, ma) == 0) {
                    printf("\nThong tin sinh vien:\n");
                    hien1SV(ds[i]);
                    found = 1;
                }
            }
            if (!found) printf("Khong tim thay sinh vien!\n");
            break;
        }
        case 0:
            printf("Thoat chuong trinh...\n");
            break;
        default:
            printf("Lua chon khong hop le!\n");
        }
    } while (choice != 0);
    return 0;
}
