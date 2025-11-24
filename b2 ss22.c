#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
struct Contact {
    char name[50];
    char phoneNumber[15];
    char email[50];
};
typedef struct Contact Contact;

int main() {
    Contact list[100];
    int n = 0;
    int choice;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Them lien he moi\n");
        printf("2. Hien thi tat ca lien he\n");
        printf("3. Tim kiem lien he theo ten\n");
        printf("4. Xoa lien he theo ten\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);
        getchar(); 
        switch(choice) {
        case 1: {
            printf("\nNhap ten: ");
            fgets(list[n].name, sizeof(list[n].name), stdin);
            list[n].name[strcspn(list[n].name, "\n")] = '\0';
            printf("Nhap so dien thoai: ");
            fgets(list[n].phoneNumber, sizeof(list[n].phoneNumber), stdin);
            list[n].phoneNumber[strcspn(list[n].phoneNumber, "\n")] = '\0';
            printf("Nhap email: ");
            fgets(list[n].email, sizeof(list[n].email), stdin);
            list[n].email[strcspn(list[n].email, "\n")] = '\0';
            n++;
            printf("Da them lien he thanh cong!\n");
            break;
        }
        case 2:
            if (n == 0) {
                printf("Danh sach rong!\n");
            } else {
                printf("\n===== DANH SACH LIEN HE =====\n");
                for (int i = 0; i < n; i++) {
                    printf("\nLien he %d:\n", i + 1);
                    printf("Ten: %s\n", list[i].name);
                    printf("SDT: %s\n", list[i].phoneNumber);
                    printf("Email: %s\n", list[i].email);
                }
            }
            break;
        case 3: {
            if (n == 0) {
                printf("Danh sach rong!\n");
                break;
            }
            char key[50];
            printf("Nhap ten can tim: ");
            fgets(key, sizeof(key), stdin);
            key[strcspn(key, "\n")] = '\0';
            int found = 0;
            for (int i = 0; i < n; i++) {
                if (strcasecmp(list[i].name, key) == 0) {
                    printf("\nTim thay lien he:\n");
                    printf("Ten: %s\n", list[i].name);
                    printf("SDT: %s\n", list[i].phoneNumber);
                    printf("Email: %s\n", list[i].email);
                    found = 1;
                }
            }
            if (!found) printf("Khong tim thay!\n");
            break;
        }
        case 4: {
            if (n == 0) {
                printf("Danh sach rong!\n");
                break;
            }
            char key[50];
            printf("Nhap ten can xoa: ");
            fgets(key, sizeof(key), stdin);
            key[strcspn(key, "\n")] = '\0';
            int found = 0;
            for (int i = 0; i < n; i++) {
                if (strcasecmp(list[i].name, key) == 0) {
                    for (int j = i; j < n - 1; j++) {
                        list[j] = list[j + 1];
                    }
                    n--;
                    found = 1;
                    printf("Da xoa lien he thanh cong!\n");
                    break;
                }
            }
            if (!found) printf("Khong tim thay de xoa!\n");
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

