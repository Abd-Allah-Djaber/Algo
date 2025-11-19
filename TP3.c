#include <stdio.h>
#include <stdlib.h>

typedef struct Product {
    int ID;
    char Name[20];
    int Price;
} Product;

typedef struct Node {
    Product Prod;
    struct Node *next;
} Node;

// إنشاء قائمة فارغة (تُرجع NULL)
Node* createEmptyList() {
    return NULL;
}

// التحقق مما إذا كانت القائمة فارغة
int isEmpty(Node *head) {
    return (head == NULL);
}
Node* insertAtBeginning(Node *head, Product p) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->Prod = p;

    if (isEmpty(head)) {
        newNode->next = newNode; // تشير إلى نفسها
        head = newNode;
    } else {
        Node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }
    return head;
}
Node* insertAtEnd(Node *head, Product p) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->Prod = p;

    if (isEmpty(head)) {
        newNode->next = newNode;
        head = newNode;
    } else {
        Node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
    return head;
}
void displayList(Node *head) {
    if (isEmpty(head)) {
        printf("The list is empty.\n");
        return;
    }

    Node *current = head;
    printf("Products in the list:\n");
    do {
        printf("ID: %d, Name: %s, Price: %d\n", 
               current->Prod.ID, 
               current->Prod.Name, 
               current->Prod.Price);
        current = current->next;
    } while (current != head);
}

int main()
{
    printf("Hello world!");
    
    return 0;
}