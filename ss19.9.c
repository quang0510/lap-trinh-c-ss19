#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct SinhVien {
    int id;
    char name[50];
    int age;
    char phoneNumber[20];
};
void printSV(struct SinhVien *sv, int size);
void addSV(struct SinhVien *sv, int *size, int x);
void editSV(struct SinhVien *sv, int *size, int x);
void deleteSV(struct SinhVien *sv, int *size, int x);
void sapXep(struct SinhVien *sv, int size, int choice);
void searchSV(struct SinhVien *sv, int size, char name[]);
int main() {
    int choice;
    int size = 5;
    int x;
    char name[50];
    struct SinhVien sv[20] = {
        {1, "Nguyen Dang Quang", 18, "092734675"},
        {2, "Nguyen Dang Xuan", 21, "094626744"},
        {3, "Vu Thi Dung", 22, "094726443"},
        {4, "Nguyen Dang Vinh", 18, "093274234"},
        {5, "Nguyen Dang Cuong", 24, "094327525"}
    };
    do {
        printf("\n********MENU*******\n");
        printf("1.  In ra gia tri sinh vien\n");
        printf("2. Them mot sinh vien vao vi tri chi dinh\n");
        printf("3. Sua mot sinh vien o vi tri chi dinh\n");
        printf("4. Xoa mot sinh vien o vi tri chi dinh\n");
        printf("5. Sap xep cac sinh vien\n");
        printf("6. Tim kiem sinh vien theo ten\n");
        printf("7. Thoat\n");
        printf("Hay chon chuc nang (1-7): ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printSV(sv, size);
                break;
            case 2:
                addSV(sv, &size, x);
                break;
            case 3:
                editSV(sv, &size, x);
                break;
            case 4:
                deleteSV(sv, &size, x);
                break;
            case 5:
                sapXep(sv, size, choice);
                break;
            case 6:
                searchSV(sv, size, name);
                break;
            case 7:
                printf("Da thoat chuong trinh\n");
                return 0;
            default:
                printf("Loi: Chuc nang khong hop le\n");
        }
    } while(choice != 7);

    return 0;
}

void printSV(struct SinhVien *sv, int size) {
    for(int i = 0; i < size; i++) {
        printf("ID: %d, Ten: %s, Tuoi: %d, So dien thoai: %s\n", sv[i].id, sv[i].name, sv[i].age, sv[i].phoneNumber);
    }
}

void addSV(struct SinhVien *sv, int *size, int x) {
    printf("Moi ban nhap vi tri them (1-%d): ", *size + 1);
    scanf("%d", &x);
    if (x < 1 || x > *size + 1) {
        printf("Vi tri khong hop le.\n");
        return;
    }
    for (int i = *size; i >= x; i--) {
        sv[i] = sv[i - 1];
    }
    printf("Nhap ten sinh vien: ");
    getchar();  // to consume the newline character
    fgets(sv[x - 1].name, sizeof(sv[x - 1].name), stdin);
    sv[x - 1].name[strcspn(sv[x - 1].name, "\n")] = 0; 

    printf("Nhap so dien thoai sinh vien: ");  
    fgets(sv[x - 1].phoneNumber, sizeof(sv[x - 1].phoneNumber), stdin);
    printf("Nhap tuoi: ");
    scanf("%d", &sv[x - 1].age);

    (*size)++;
    printf("Sinh vien da duoc them vao vi tri %d.\n", x);
}

void editSV(struct SinhVien *sv, int *size, int x) {
    printf("Moi ban nhap vi tri sua (1-%d): ", *size);
    scanf("%d", &x);
    if (x < 1 || x > *size) {
        printf("Vi tri khong hop le.\n");
        return;
    }
    printf("Nhap ten sinh vien can sua: ");
    getchar();  
    fgets(sv[x - 1].name, sizeof(sv[x - 1].name), stdin);
    sv[x - 1].name[strcspn(sv[x - 1].name, "\n")] = 0; 

    printf("Nhap so dien thoai sinh vien can sua: ");
    fgets(sv[x - 1].phoneNumber, sizeof(sv[x - 1].phoneNumber), stdin);
    printf("Nhap tuoi: ");
    scanf("%d", &sv[x - 1].age);

    printf("Sinh vien da duoc sua o vi tri %d.\n", x);
}

void deleteSV(struct SinhVien *sv, int *size, int x) {
    printf("Moi ban nhap vi tri xoa (1-%d): ", *size);
    scanf("%d", &x);
    if (x < 1 || x > *size) {
        printf("Vi tri khong hop le.\n");
        return;
    }
    for (int i = x - 1; i < *size - 1; i++) {
        sv[i] = sv[i + 1];
    }
    (*size)--;  // reduce size
    printf("Sinh vien da duoc xoa khoi vi tri %d.\n", x);
}

void sapXep(struct SinhVien *sv, int size, int choice) {
    int sortChoice;
    printf("1. Sap xep tang dan\n");
    printf("2. Sap xep giam dan\n");
    printf("Hay chon chuc nang (1-2): ");
    scanf("%d", &sortChoice);

    switch (sortChoice) {
        case 1:
            for (int i = 0; i < size - 1; i++) {
                for (int j = i + 1; j < size; j++) {
                    if (sv[i].id > sv[j].id) {
                        struct SinhVien temp = sv[i];
                        sv[i] = sv[j];
                        sv[j] = temp;
                    }
                }
            }
            printSV(sv, size);
            break;
        case 2:
            for (int i = 0; i < size - 1; i++) {
                for (int j = i + 1; j < size; j++) {
                    if (sv[i].id < sv[j].id) {
                        struct SinhVien temp = sv[i];
                        sv[i] = sv[j];
                        sv[j] = temp;
                    }
                }
            }
            printSV(sv, size);
            break;
        default:
            printf("Du lieu sai, vui long nhap lai.\n");
    }
}

void searchSV(struct SinhVien *sv, int size, char name[]) {
    printf("Nhap ten sinh vien can tim: ");
    getchar();  
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0; 

    int found = 0;
    for (int i = 0; i < size; i++) {
        if (strstr(sv[i].name, name)) {
            printf("ID: %d, Ten: %s, Tuoi: %d, So dien thoai: %s\n", sv[i].id, sv[i].name, sv[i].age, sv[i].phoneNumber);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay sinh vien theo ten '%s'.\n", name);
    }
}

