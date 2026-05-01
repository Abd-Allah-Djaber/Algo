#include <stdio.h>

// زوايا الجدول
void topLeft() { printf("┌"); }
void topRight() { printf("┐"); }
void bottomLeft() { printf("└"); }
void bottomRight() { printf("┘"); }

// خطوط أفقية
void horizontal() { printf("─"); }

// خطوط عمودية
void vertical() { printf("│"); }

// تقاطعات الجدول
void leftIntersection() { printf("├"); }
void rightIntersection() { printf("┤"); }
void topIntersection() { printf("┬"); }
void bottomIntersection() { printf("┴"); }
void middleIntersection() { printf("┼"); }

// زوايا ثقيلة
void topLeftHeavy() { printf("┏"); }
void topRightHeavy() { printf("┓"); }
void bottomLeftHeavy() { printf("┗"); }
void bottomRightHeavy() { printf("┛"); }
// خطوط ثقيلة
void horizontalHeavy() { printf("━"); }

// خطوط ثقيلة
void verticalHeavy() { printf("┃"); }
// تقاطعات ثقيلة
void topIntersectionHeavy() { printf("┳"); }
void bottomIntersectionHeavy() { printf("┻"); }
void leftIntersectionHeavy() { printf("┣"); }
void rightIntersectionHeavy() { printf("┫"); }
void middleIntersectionHeavy() { printf("╋"); }

int main() {
    topLeft();
    horizontal();
    horizontal();
    topRight();
    printf("\n");
    vertical();
    printf(" Hello ");
    vertical();
    printf("\n");
    bottomLeft();
    horizontal();
    horizontal();
    bottomRight();
    printf("\n");
    return 0;
}
