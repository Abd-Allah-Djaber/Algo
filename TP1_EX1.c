#include <stdio.h>
void ScanMat2d(int n, int A[][n]);
void SwapTrngl2d(int n, int A[][n]);
void PrtMat2d(int n, int A[][n]);
int main() {
    int n;
    printf("Enter size of matrix: ");
    scanf("%d", &n);
    int A[n][n];
    printf("Enter A[%d][%d]:\n",n,n);
    ScanMat2d(n, A);
    printf("\nMatrix before swapping:\n");
    PrtMat2d(n, A);
    SwapTrngl2d(n, A);
    printf("\nMatrix after swapping:\n");
    PrtMat2d(n, A);
    return 0;
}
//
 void SwapTrngl2d(int n, int A[][n]) {
    int i, j, temp;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            temp = A[i][j];
            A[i][j] = A[j][i];
            A[j][i] = temp;
        }
    }
}
//
void PrtMat2d(int n, int A[][n]){
    int i, j;
    for (i = 0; i < n; i++){
        printf("\n\n");
        for (j = 0; j < n; j++)
            printf("\t%d", A[i][j]);
        printf("\n");
    }
}
//
void ScanMat2d(int n, int A[][n]){
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &A[i][j]);
}
