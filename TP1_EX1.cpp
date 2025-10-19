#include <stdio.h>

int main() {
    int n = 4;
    int a[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }

    printf("\tMatrix after symmetry:\n\n\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("\t%d", a[i][j]);
        printf("\n\n\n");
    }
    return 0;
}
