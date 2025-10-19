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
