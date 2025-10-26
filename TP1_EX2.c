#include <stdio.h>
int add(int a, int b);
int max(int a, int b);
float average(int arr[], int n);
int main() {
    int n, i, j;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d numbers:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    int largest = arr[0];
    for (i = 1; i < n; i++)
        largest = max(largest, arr[i]);
    printf("Largest number = %d\n", largest);
    printf("Average = %.2f\n", average(arr, n));
    return 0;
}
//
int add(int a, int b) {
    return a + b;
}
//
int max(int a, int b) {
    return (a > b) ? a : b;
}
//
float average(int arr[], int n) {
    int i, sum = 0;
    for (i = 0; i < n; i++)
        sum = add(sum, arr[i]);
    return (float)sum / n;
}
