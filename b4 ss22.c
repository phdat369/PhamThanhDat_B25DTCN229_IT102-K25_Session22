#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
struct Date {
    int day, month, year;
};
struct Order {
    char maDH[20];
    char tenKH[50];
    struct Date ngayDat;
    float tongTien;
    char trangThai[20];
};
typedef struct Order Order;
void nhap1DonHang(Order *o) {
    printf("Nhap ma don hang: ");
    fgets(o->maDH, sizeof(o->maDH), stdin);
    o->maDH[strcspn(o->maDH, "\n")] = '\0';
    printf("Nhap ten khach hang: ");
    fgets(o->tenKH, sizeof(o->tenKH), stdin);
    o->tenKH[strcspn(o->tenKH, "\n")] = '\0';
    printf("Nhap ngay dat (dd mm yyyy): ");
    scanf("%d %d %d", &o->ngayDat.day, &o->ngayDat.month, &o->ngayDat.year);
    getchar();
    printf("Nhap tong tien: ");
    scanf("%f", &o->tongTien);
    getchar();
    printf("Nhap trang thai (Dang xu ly / Da giao / Huy): ");
    fgets(o->trangThai, sizeof(o->trangThai), stdin);
    o->trangThai[strcspn(o->trangThai, "\n")] = '\0';
}
void hien1DonHang(Order o) {
    printf("Ma DH: %s\n", o.maDH);
    printf("Ten KH: %s\n", o.tenKH);
    printf("Ngay dat: %02d/%02d/%04d\n", o.ngayDat.day, o.ngayDat.month, o.ngayDat.year);
    printf("Tong tien: %.2f\n", o.tongTien);
    printf("Trang thai: %s\n", o.trangThai);
}
int main() {
    Order list[100];
    int n = 0;
    int choice;
    do {
        printf("\n======= MENU =======\n");
        printf("1. Nhap thong tin don hang\n");
        printf("2. Hien thi tat ca don hang\n");
        printf("3. Cap nhat trang thai don hang\n");
        printf("4. Xoa don hang theo ma\n");
        printf("5. Sap xep don hang theo tong tien\n");
        printf("6. Tim kiem don hang theo ma\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
        case 1:
            printf("\n=== Nhap don hang moi ===\n");
            nhap1DonHang(&list[n]);
            n++;
            break;
        case 2:
            if (n == 0) printf("Danh sach rong!\n");
            else {
                printf("\n===== DANH SACH DON HANG =====\n");
                for (int i = 0; i < n; i++) {
                    printf("\nDon hang %d:\n", i + 1);
                    hien1DonHang(list[i]);
                }
            }
            break;
        case 3: {
            char ma[20];
            printf("Nhap ma don hang can cap nhat: ");
            fgets(ma, sizeof(ma), stdin);
            ma[strcspn(ma, "\n")] = '\0';
            int found = 0;
            for (int i = 0; i < n; i++) {
                if (strcmp(list[i].maDH, ma) == 0) {
                    printf("Nhap trang thai moi (Dang xu ly / Da giao / Huy): ");
                    fgets(list[i].trangThai, sizeof(list[i].trangThai), stdin);
                    list[i].trangThai[strcspn(list[i].trangThai, "\n")] = '\0';

                    printf("Cap nhat thanh cong!\n");
                    found = 1;
                    break;
                }
            }
            if (!found) printf("Khong tim thay don hang!\n");
            break;
    }
        case 4: {
            char ma[20];
            printf("Nhap ma don hang can xoa: ");
            fgets(ma, sizeof(ma), stdin);
            ma[strcspn(ma, "\n")] = '\0';

            int found = 0;
            for (int i = 0; i < n; i++) {
                if (strcmp(list[i].maDH, ma) == 0) {
                    for (int j = i; j < n - 1; j++)
                        list[j] = list[j + 1];
                    n--;
                    found = 1;
                    printf("Xoa thanh cong!\n");
                    break;
                }
            }
            if (!found) printf("Khong tim thay de xoa!\n");
            break;
        }
        case 5: {
            int opt;
            printf("1. Sap xep tang dan\n");
            printf("2. Sap xep giam dan\n");
            printf("Nhap lua chon: ");
            scanf("%d", &opt);
            getchar();
            for (int i = 0; i < n - 1; i++) {
                for (int j = i + 1; j < n; j++) {
                    if ((opt == 1 && list[i].tongTien > list[j].tongTien) ||
                        (opt == 2 && list[i].tongTien < list[j].tongTien)) {

                        Order tmp = list[i];
                        list[i] = list[j];
                        list[j] = tmp;
                    }
                }
            }
            printf("Sap xep thanh cong!\n");
            break;
        }
        case 6: {
            char ma[20];
            printf("Nhap ma don hang can tim: ");
            fgets(ma, sizeof(ma), stdin);
            ma[strcspn(ma, "\n")] = '\0';
            int found = 0;
            for (int i = 0; i < n; i++) {
                if (strcmp(list[i].maDH, ma) == 0) {
                    printf("\nThong tin don hang:\n");
                    hien1DonHang(list[i]);
                    found = 1;
                }
            }
            if (!found) printf("Khong tim thay don hang!\n");
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
