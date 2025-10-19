//EX 01:

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


//EX02:


#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

float average(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    return (float)sum / n;
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
        maxVal = max(maxVal, arr[i]);

    printf("Maximum value = %d\n", maxVal);
    printf("Average = %.2f\n", average(arr, n));

    return 0;
}
