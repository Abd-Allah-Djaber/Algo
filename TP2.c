#include <stdio.h>
#include <stdlib.h>

char *LoadString(int N);
int StringLength(char *str);
void LoadArray(char *p, char arr[]);
void ReverseArray(char arr[], char rev[], int n);
void DisplayArray(char arr[], int n);
int SumStringASCII(char *p);
void ReverseString(char *start, char *end);

// 8️⃣ main program
int main() {
    char *str;
    int n;

    printf("Please enter the maximum size of the string:\n");
    scanf("%d", &n);
    getchar(); // لإزالة \n من buffer

    str = LoadString(n);
    int len = StringLength(str);

    char arr[len + 1], rev[len + 1];
    LoadArray(str, arr);

    printf("\nOriginal array: ");
    DisplayArray(arr, len);

    ReverseArray(arr, rev, len);
    printf("Reversed array: ");
    DisplayArray(rev, len);

    int sum = SumStringASCII(str);
    printf("\nSum of ASCII values (recursive): %d\n", sum);

    ReverseString(str, str + len - 1);
    printf("String reversed recursively: %s\n", str);

    free(str);
    return 0;
}

// 1️⃣ LoadString
char *LoadString(int N) {
    char *str = (char *)malloc((N + 1) * sizeof(char));
    if (str == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    printf("Enter your string (max %d characters): ", N);
    fgets(str, N + 1, stdin);
    // إزالة \n إذا وُجدت
    int i;
    for (i = 0; str[i]; i++) {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
    }
    return str;
}

// 2️⃣ StringLength (بدون strlen)
int StringLength(char *str) {
    int len = 0;
    while (*str != '\0') {
        len++;
        str++;
    }
    return len;
}

// 3️⃣ LoadArray
void LoadArray(char *p, char arr[]) {
    int i = 0;
    while (p[i] != '\0') {
        arr[i] = p[i];
        i++;
    }
    arr[i] = '\0';
}

// 4️⃣ ReverseArray
void ReverseArray(char arr[], char rev[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        rev[i] = arr[n - i - 1];
    }
    rev[n] = '\0';
}

// 5️⃣ DisplayArray
void DisplayArray(char arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%c", arr[i]);
    }
    printf("\n");
}

// 6️⃣ SumStringASCII (recursive)
int SumStringASCII(char *p) {
    if (*p == '\0')
        return 0;
    return *p + SumStringASCII(p + 1);
}

// 7️⃣ ReverseString (recursive)
void ReverseString(char *start, char *end) {
    if (start >= end)
        return;

    char temp = *start;
    *start = *end;
    *end = temp;

    ReverseString(start + 1, end - 1);
}
