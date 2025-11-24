#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
struct Student {
    char name[50];
    int age;
    float grade;
};
typedef struct Student Student;

int main() {
    Student students[100];
    int n = 0;
    int choice;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Nhap thong tin hoc sinh\n");
        printf("2. Hien thi thong tin hoc sinh\n");
        printf("3. Tinh diem trung binh\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);
        getchar(); 
        switch(choice) {
        case 1:
            printf("Nhap so luong hoc sinh: ");
            scanf("%d", &n);
            getchar();
            for (int i = 0; i < n; i++) {
                printf("\n--- Hoc sinh %d ---\n", i + 1);
                printf("Nhap ten: ");
                fgets(students[i].name, sizeof(students[i].name), stdin);
                students[i].name[strcspn(students[i].name, "\n")] = '\0';
                printf("Nhap tuoi: ");
                scanf("%d", &students[i].age);
                printf("Nhap diem: ");
                scanf("%f", &students[i].grade);
                getchar();
            }
            break;
        case 2:
            if (n == 0) {
                printf("Chua co du lieu hoc sinh!\n");
            } else {
                printf("\n===== DANH SACH HOC SINH =====\n");
                for (int i = 0; i < n; i++) {
                    printf("\nHoc sinh %d:\n", i + 1);
                    printf("Ten: %s\n", students[i].name);
                    printf("Tuoi: %d\n", students[i].age);
                    printf("Diem: %.2f\n", students[i].grade);
                }
            }
            break;
        case 3:
            if (n == 0) {
                printf("Chua co du lieu de tinh diem trung binh!\n");
            } else {
                float sum = 0;
                for (int i = 0; i < n; i++) {
                    sum += students[i].grade;
                }
                printf("Diem trung binh = %.2f\n", sum / n);
            }
            break;
        case 0:
            printf("Thoat chuong trinh...\n");
            break;
        default:
            printf("Lua chon khong hop le!\n");
        }
    } while (choice != 0);
    return 0;
}
