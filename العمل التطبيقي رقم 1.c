#include <stdio.h>

int main() {
printf("Exercice 01:\n");
    // تعريف المصفوفة
    char matrice[5][5] = {
        {'1', '2', '3', '4', '5'},
        {'7', 'a', 'c', '8', 'd'},
        {'c', '9', '4', 'z', '8'},
        {'5', '6', 'p', 'm', '-'},
        {'2', '9', 't', 'm', 'k'}
    };

    // عرض المصفوفة الكاملة
    printf("المصفوفة الكاملة:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%c ", matrice[i][j]);
        }
        printf("\n");
    }
// عرض السطور ذات المؤشرات الزوجية
printf("\nالسطور ذات المؤشرات الزوجية:\n");
for (int i = 0; i < 5; i++) {
    if (i % 2 == 0) { // تحقق إذا كان المؤشر زوجيًا
        for (int j = 0; j < 5; j++) {
            printf("%c ", matrice[i][j]);
        }
        printf("\n");
    }
}// عرض العناصر ذات المؤشرات الفردية في كل سطر
printf("\nالعناصر ذات المؤشرات الفردية:\n");
for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
        if (j % 2 != 0) { // تحقق إذا كان المؤشر فرديًا
            printf("%c ", matrice[i][j]);
        }
    }
    printf("\n");
}// عرض القطر الرئيسي
printf("\nالقطر الرئيسي:\n");
for (int i = 0; i < 5; i++) {
    printf("%c ", matrice[i][i]);
}
printf("\n");

// عرض القطر الثانوي
printf("\nالقطر الثانوي:\n");
for (int i = 0; i < 5; i++) {
    printf("%c ", matrice[i][4 - i]);
}
printf("\nExercice02:\n");
    // تعريف المصفوفة
    int matric[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    int n = 4;

    // تبديل المثلث العلوي بالسفلي
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) { // فقط العناصر العلوية
            int temp = matric[i][j];
            matric[i][j] = matric[j][i];
            matric[j][i] = temp;
        }
    }

    // عرض المصفوفة بعد التبديل
    printf("المصفوفة بعد تبديل المثلث العلوي بالسفلي:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matric[i][j]);
        }
        printf("\n");
    }
    return 0;
}
