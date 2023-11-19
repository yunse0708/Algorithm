#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data[4];
    struct Node* next;
} Node;

void deleteAll(Node* head) {
    Node* removed;
    while (head != NULL) {
        removed = head;
        head = head->next;
        free(removed);
        removed = NULL;
    }
}

void printList(Node* head) {
    Node* p = head;
    printf("L = (");
    while (p != NULL) {
        printf("%s", p->data);
        p = p->next;
        if (p != NULL) {
            printf("->");
        }
    }
    printf(")\n");
}

Node* insertFirst(Node* head, char* x) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, x);
    newNode->next = head;
    return newNode;
}

Node* insertMiddle(Node* head, Node* pre, char* x) {
    if (head == NULL || pre == NULL) {
        return NULL;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, x);
    newNode->next = pre->next;
    pre->next = newNode;
    return head;
}

Node* insertLast(Node* head, char* x) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, x);
    newNode->next = NULL;
    if (head == NULL) {
        return newNode;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

Node* searchNode(Node* head, char* x) {
    Node* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->data, x) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

int main() {
    Node* head = NULL;
    Node* p;

    printf("(1) 공백리스트 생성하기!\n");
    printList(head);

    printf("(2) 리스트 처음에 [수]노드 삽입하기!\n");
    head = insertFirst(head, "수");
    printList(head);

    printf("(3) 리스트 마지막에 [금]노드 삽입하기!\n");
    head = insertLast(head, "금");
    printList(head);

    printf("(4) 리스트 첫 번째에 [월]노드 삽입하기!\n");
    head = insertFirst(head, "월");
    printList(head);

    printf("(5) 리스트에서 [수] 노드를 찾아 그 뒤에 [목] 삽입하기!\n");
    p = searchNode(head, "수");
    if (p == NULL) {
        printf("찾는 데이터가 없습니다.\n");
    } else {
        head = insertMiddle(head, p, "목");
    }
    printList(head);

    printf("(6) 리스트 공간을 해제하여 공백 리스트로 만들기!\n");
    deleteAll(head);
    head = NULL;
    printList(head);

    return 0;
}