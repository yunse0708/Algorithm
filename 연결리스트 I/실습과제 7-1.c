#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data[100];
    struct Node* next;
} Node;

Node* insertFirst(Node* head, char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->next = head;
    return newNode;
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%s->", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    char str[3][10] = {"melon", "kiwi", "apple"};
    char find[10];

    // Insert the elements into the linked list
    for (int i = 0; i < 3; i++) {
        head = insertFirst(head, str[i]);
        printList(head);
    }

    printf("찾을 데이터를 입력하세요\n");
    scanf("%s", find);

    Node* current = head;
    int found = 0;

    while (current != NULL) {
        if (strcmp(current->data, find) == 0) {
            printf("%s을 찾았습니다.", find);
            found = 1;
            break;
        }
        current = current->next;
    }

    if (!found) {
        printf("%s을 찾지 못했습니다.", find);
    }

    return 0;
}
