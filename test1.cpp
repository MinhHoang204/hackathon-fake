#include <stdio.h>
#include <stdbool.h>
#define MAX 100

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void addElement(int arr[], int *size, int value) {
    if (*size < MAX) {
        arr[*size] = value;
        (*size)++;
    } else {
        printf("Mang da day.\n");
    }
}

void deleteElement(int arr[], int *size, int index) {
    if (index >= 0 && index < *size) {
        for (int i = index; i < *size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        (*size)--;
    } else {
        printf("Vi tri khong hop le.\n");
    }
}

void sortArray(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int arr[MAX], size = 0, choice;

    do {
        printf("\nMENU\n");
        printf("1. Nhap so phan tu can nhap va gia tri cac phan tu\n");
        printf("2. In ra gia tri cac phan tu dang quan ly\n");
        printf("3. In ra gia tri lon nhat cua mang\n");
        printf("4. In ra cac phan tu la so nguyen to trong mang\n");
        printf("5. Them mot phan tu vao trong mang\n");
        printf("6. Xoa mot phan tu trong mang\n");
        printf("7. Sap xep mang theo thu tu tang dan\n");
        printf("8. Tim kiem phan tu va in ra vi tri cua phan tu do\n");
        printf("9. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: { 
                printf("Nhap so phan tu: ");
                scanf("%d", &size);
                for (int i = 0; i < size; i++) {
                    printf("Nhap phan tu thu %d: ", i);
                    scanf("%d", &arr[i]);
                }
                break;
            }
            case 2: { 
                printf("Cac phan tu trong mang: ");
                for (int i = 0; i < size; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            }
            case 3: { 
                if (size == 0) {
                    printf("Mang rong.\n");
                } else {
                    int max = arr[0];
                    for (int i = 1; i < size; i++) {
                        if (arr[i] > max) {
                            max = arr[i];
                        }
                    }
                    printf("Gia tri lon nhat: %d\n", max);
                }
                break;
            }
            case 4: { 
                printf("Cac so nguyen tu trong mang: ");
                for (int i = 0; i < size; i++) {
                    if (isPrime(arr[i])) {
                        printf("%d ", arr[i]);
                    }
                }
                printf("\n");
                break;
            }
            case 5: { 
                int value;
                printf("Nhap gia tri phan tu can them: ");
                scanf("%d", &value);
                addElement(arr, &size, value);
                break;
            }
            case 6: { 
                int index;
                printf("Nhap vi tri phan tu can xoa: ");
                scanf("%d", &index);
                deleteElement(arr, &size, index);
                break;
            }
            case 7: { 
                sortArray(arr, size);
                printf("Mang da duoc sap xep tang dan.\n");
                break;
            }
            case 8: { 
                int value, found = 0;
                printf("Nhap gia tri can tim: ");
                scanf("%d", &value);
                for (int i = 0; i < size; i++) {
                    if (arr[i] == value) {
                        printf("Phan tu %d nam tai vi tri index: %d\n", value, i);
                        found = 1;
                    }
                }
                if (!found) {
                    printf("Khong tim thay phan tu trong mang.\n");
                }
                break;
            }
            case 9: {
                printf("Thoat chuong trinh.\n");
                break;
            }
            default: {
                printf("Lua chon khong hop le. Vui long thu lai.\n");
                break;
            }
        }
    } while (choice != 9);

    return 0;
}

