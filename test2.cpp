#include <stdio.h>
#define MAX 100

int main() {
    int arr[MAX][MAX]; 
    int row = 0, col = 0, choice;

    do {
        printf("\nMENU\n");
        printf("1. Nhap kich co va gia tri cac phan tu cua mang\n");
        printf("2. In gia tri cac phan tu cua mang theo ma tran\n");
        printf("3. In ra cac phan tu nam tren duong bien và tinh tich\n");
        printf("4. In ra cac phan tu nam tren duong cheo chinh\n");
        printf("5. In ra cac phan tu nam tren duong cheo phu\n");
        printf("6. Sap xep duong cheo chinh theo thu tu tang dan\n");
        printf("7. Tim kiem mot phan tu va in ra vi tri cua phan tu do trong mang\n");
        printf("8. Thoat\n");
        printf("Moi ban nhap lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: { 
                printf("Moi nhap so hang: ");
                scanf("%d", &row);
                printf("Moi nhap so cot: ");
                scanf("%d", &col);
                
                for (int i = 0; i < row; i++) {
                    for (int j = 0; j < col; j++) {
                        printf("Nhap phan tu [%d][%d]: ", i, j);
                        scanf("%d", &arr[i][j]);
                    }
                }
                break;
            }
            case 2: { 
                printf("Ma tran:\n");
                for (int i = 0; i < row; i++) {
                    for (int j = 0; j < col; j++) {
                        printf("%d ", arr[i][j]);
                    }
                    printf("\n");
                }
                break;
            }
            case 3: { 
                int result = 1;
                printf("Cac phan tu nam tren duong biên: ");
                for (int i = 0; i < row; i++) {
                    for (int j = 0; j < col; j++) {
                        if (i == 0 || i == row - 1 || j == 0 || j == col - 1) {
                            printf("%d ", arr[i][j]);
                            result *= arr[i][j];
                        }
                    }
                }
                printf("\nTich cua cac phan tu tren duong bien: %d\n", result);
                break;
            }
            case 4: { 
                if (row == col) {
                    printf("Cac phan tu tren duong cheo chinh: ");
                    for (int i = 0; i < row; i++) {
                        printf("%d ", arr[i][i]);
                    }
                    printf("\n");
                } else {
                    printf("Ma tran khong phai hinh vuong.\n");
                }
                break;
            }
            case 5: { 
                if (row == col) {
                    printf("Cac phan tu tren duong cheo phu: ");
                    for (int i = 0; i < row; i++) {
                        printf("%d ", arr[i][col - i - 1]);
                    }
                    printf("\n");
                } else {
                    printf("Ma tran khong phai hinh vuong.\n");
                }
                break;
            }
            case 6: { 
                if (row == col) {
                    int temp[MAX], size = row;
                    for (int i = 0; i < size; i++) {
                        temp[i] = arr[i][i];
                    }
                    // Sap xep mang temp tang dan
                    for (int i = 0; i < size - 1; i++) {
                        for (int j = i + 1; j < size; j++) {
                            if (temp[i] > temp[j]) {
                                int t = temp[i];
                                temp[i] = temp[j];
                                temp[j] = t;
                            }
                        }
                    }
                    // Gan lai vao duong cheo chinh
                    for (int i = 0; i < size; i++) {
                        arr[i][i] = temp[i];
                    }
                    printf("Duong cheo chinh da duoc sap xep tang dan.\n");
                } else {
                    printf("Ma tran khong phai hinh vuong.\n");
                }
                break;
            }
            case 7: { 
                int x, found = 0;
                printf("Moi ban nhap gia tri can tim: ");
                scanf("%d", &x);
                for (int i = 0; i < row; i++) {
                    for (int j = 0; j < col; j++) {
                        if (arr[i][j] == x) {
                            printf("Phan tu %d nam tai vi tri [%d][%d]\n", x, i, j);
                            found = 1;
                        }
                    }
                }
                if (!found) {
                    printf("Khong tim thay phan tu %d trong mang.\n", x);
                }
                break;
            }
            case 8: {
                printf("Thoat chuong trinh.\n");
                break;
            }
            default: {
                printf("Lua chon khong hop le. Vui long thu lai.\n");
                break;
            }
        }
    } while (choice != 8);

    return 0;
}

