#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// ألوان ANSI
#define COLOR_GREEN   "\033[32m"
#define COLOR_RED     "\033[31m"
#define COLOR_YELLOW  "\033[33m"
#define COLOR_CYAN    "\033[36m"
#define COLOR_BOLD    "\033[1m"
#define COLOR_RESET   "\033[0m"

// عقدة القائمة المرتبطة
typedef struct Node {
    char date[50];
    char operation;   // '+' أو '-'
    double amount;
    char source[100];
    struct Node *next;
} Node;

// إنشاء عقدة جديدة
Node *create_node(const char *date, char operation, double amount, const char *source) {
    Node *node = (Node *)malloc(sizeof(Node));
    if (!node) {
        fprintf(stderr, "خطأ في تخصيص الذاكرة\n");
        exit(1);
    }
    strncpy(node->date, date, sizeof(node->date) - 1);
    node->date[sizeof(node->date) - 1] = '\0';
    node->operation = operation;
    node->amount = amount;
    strncpy(node->source, source, sizeof(node->source) - 1);
    node->source[sizeof(node->source) - 1] = '\0';
    node->next = NULL;
    return node;
}

// إضافة عقدة في نهاية القائمة
void append(Node **head, Node *new_node) {
    if (*head == NULL) {
        *head = new_node;
    } else {
        Node *curr = *head;
        while (curr->next) curr = curr->next;
        curr->next = new_node;
    }
}

// تنظيف المسافات من أطراف النص
void trim(char *str) {
    if (!str) return;
    int start = 0;
    while (str[start] && isspace((unsigned char)str[start])) start++;
    int len = strlen(str + start);
    memmove(str, str + start, len + 1);
    while (len > 0 && isspace((unsigned char)str[len - 1])) {
        str[--len] = '\0';
    }
}

// تحليل سطر واحد وإضافته للقائمة
void parse_line(const char *line, char *current_date, Node **head) {
    char buf[256];
    strncpy(buf, line, sizeof(buf) - 1);
    buf[sizeof(buf) - 1] = '\0';
    trim(buf);

    if (strlen(buf) == 0) return;

    if (buf[0] == '+' || buf[0] == '-') {
        char operation = buf[0];
        char rest[256];
        strncpy(rest, buf + 1, sizeof(rest) - 1);
        rest[sizeof(rest) - 1] = '\0';
        trim(rest);

        // استخراج المبلغ والمصدر (مفصولان بمسافة أو فاصلة)
        double amount = 0.0;
        char source[100] = "غير محدد";

        char *sep = strchr(rest, ' ');
        if (!sep) sep = strchr(rest, ',');

        if (sep) {
            char amount_str[50];
            strncpy(amount_str, rest, sep - rest);
            amount_str[sep - rest] = '\0';
            amount = atof(amount_str);
            strncpy(source, sep + 1, sizeof(source) - 1);
            source[sizeof(source) - 1] = '\0';
            trim(source);
        } else {
            amount = atof(rest);
        }

        Node *node = create_node(current_date, operation, amount, source);
        append(head, node);
    } else {
        // سطر تاريخ
        strncpy(current_date, buf, 49);
        current_date[49] = '\0';
    }
}

// تحليل البيانات من نص مدمج في البرنامج
void parse_from_string(const char *data, Node **head) {
    char current_date[50] = "غير محدد";
    char line[256];
    const char *ptr = data;

    while (*ptr) {
        int i = 0;
        while (*ptr && *ptr != '\n' && i < 255) {
            line[i++] = *ptr++;
        }
        line[i] = '\0';
        if (*ptr == '\n') ptr++;
        parse_line(line, current_date, head);
    }
}

// تحليل البيانات من ملف خارجي
int parse_from_file(const char *filename, Node **head) {
    FILE *fp = fopen(filename, "r");
    if (!fp) return 0;

    char current_date[50] = "غير محدد";
    char line[256];

    while (fgets(line, sizeof(line), fp)) {
        // إزالة newline
        line[strcspn(line, "\n")] = '\0';
        parse_line(line, current_date, head);
    }
    fclose(fp);
    return 1;
}

// حساب عرض الأعمدة ديناميكيًا
void compute_widths(Node *head, int *w_date, int *w_source, int *w_amount) {
    *w_date   = (int)strlen("التاريخ");
    *w_source = (int)strlen("المصدر / النوع");
    *w_amount = (int)strlen("المبلغ");

    Node *curr = head;
    while (curr) {
        int d = (int)strlen(curr->date);
        int s = (int)strlen(curr->source);
        char amt_buf[30];
        snprintf(amt_buf, sizeof(amt_buf), "%.2f", curr->amount);
        int a = (int)strlen(amt_buf);

        if (d > *w_date)   *w_date   = d;
        if (s > *w_source) *w_source = s;
        if (a > *w_amount) *w_amount = a;
        curr = curr->next;
    }
    // هامش
    *w_date   += 2;
    *w_source += 2;
    *w_amount += 2;
}

// طباعة خط أفقي
void print_separator(int w_date, int w_source, int w_amount) {
    printf("+");
    for (int i = 0; i < w_date   + 2; i++) printf("-");
    printf("+");
    for (int i = 0; i < w_source + 2; i++) printf("-");
    printf("+");
    for (int i = 0; i < w_amount + 2; i++) printf("-");
    printf("+\n");
}

// طباعة صف
void print_row(const char *date, const char *source, const char *amount,
               int w_date, int w_source, int w_amount, const char *color) {
    printf("| %s%-*s%s | %s%-*s%s | %s%*s%s |\n",
           color, w_date,   date,   COLOR_RESET,
           color, w_source, source, COLOR_RESET,
           color, w_amount, amount, COLOR_RESET);
}

// رسم الجدول وحساب الرصيد
void print_table(Node *head) {
    int w_date, w_source, w_amount;
    compute_widths(head, &w_date, &w_source, &w_amount);

    printf("\n%s%s=== سجل المداخيل والمصاريف ===%s\n\n", COLOR_BOLD, COLOR_CYAN, COLOR_RESET);

    print_separator(w_date, w_source, w_amount);

    // رأس الجدول
    printf("| %s%-*s%s | %s%-*s%s | %s%*s%s |\n",
           COLOR_BOLD, w_date,   "التاريخ",       COLOR_RESET,
           COLOR_BOLD, w_source, "المصدر / النوع", COLOR_RESET,
           COLOR_BOLD, w_amount, "المبلغ",         COLOR_RESET);

    print_separator(w_date, w_source, w_amount);

    double total = 0.0;
    Node *curr = head;

    while (curr) {
        const char *color = (curr->operation == '+') ? COLOR_GREEN : COLOR_RED;
        char amt_buf[30];
        char sign = (curr->operation == '+') ? '+' : '-';
        snprintf(amt_buf, sizeof(amt_buf), "%c%.2f", sign, curr->amount);

        print_row(curr->date, curr->source, amt_buf,
                  w_date, w_source, w_amount, color);

        if (curr->operation == '+') total += curr->amount;
        else                        total -= curr->amount;

        curr = curr->next;
    }

    print_separator(w_date, w_source, w_amount);

    // صف الرصيد الإجمالي
    char total_buf[30];
    snprintf(total_buf, sizeof(total_buf), "%.2f", total);
    const char *total_color = (total >= 0) ? COLOR_GREEN : COLOR_RED;

    printf("| %s%-*s%s | %s%-*s%s | %s%*s%s |\n",
           COLOR_BOLD, w_date,   "",            COLOR_RESET,
           COLOR_BOLD, w_source, "الرصيد الإجمالي", COLOR_RESET,
           total_color, w_amount, total_buf,    COLOR_RESET);

    print_separator(w_date, w_source, w_amount);
    printf("\n");
}

// تحرير الذاكرة
void free_list(Node *head) {
    while (head) {
        Node *tmp = head;
        head = head->next;
        free(tmp);
    }
}

// ======== البيانات المدمجة (مثال) ========
static const char *SAMPLE_DATA =
    "2025-01-10\n"
    "+5000 راتب شهري\n"
    "-800 إيجار\n"
    "-150 فاتورة كهرباء\n"
    "+200 عمل إضافي\n"
    "2025-01-15\n"
    "-300 مشتريات\n"
    "+1000 مكافأة\n"
    "-50 نقل\n"
    "2025-01-20\n"
    "+750 مشروع مستقل\n"
    "-120 مطعم\n"
    "-200 ملابس\n";

int main(int argc, char *argv[]) {
    Node *head = NULL;

    if (argc >= 2) {
        // قراءة من ملف خارجي
        printf("جاري القراءة من الملف: %s\n", argv[1]);
        if (!parse_from_file(argv[1], &head)) {
            fprintf(stderr, "خطأ: لا يمكن فتح الملف '%s'\n", argv[1]);
            return 1;
        }
    } else {
        // استخدام البيانات المدمجة
        printf("استخدام البيانات المدمجة (يمكنك تمرير اسم ملف كـ argument)\n");
        parse_from_string(SAMPLE_DATA, &head);
    }

    if (!head) {
        printf("لا توجد بيانات للعرض.\n");
        return 0;
    }

    print_table(head);
    free_list(head);
    return 0;
}
