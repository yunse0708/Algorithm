


#include <stdio.h>
#include <stdlib.h>

typedef int element;

// 이중연결리스트 노드 구조체 정의
typedef struct DNode {
    element data;
    struct DNode* prev;
    struct DNode* next;
} DNode;




void init(DNode* phead) {
    phead->next = phead;
    phead->prev = phead;
}

void dinsert(DNode* before, element data) {
    DNode* newnode = (DNode*)malloc(sizeof(DNode));
    newnode->data = data;
    newnode->prev = before;
    newnode->next = before->next;
    before->next->prev = newnode;
    before->next = newnode;
}

void ddelete(DNode* head, DNode* removed) {
    if (removed == head) return;
    removed->prev->next = removed->next;
    removed->next->prev = removed->prev;
    free(removed);
}

void printDlist(DNode* phead) {
    DNode* p = phead->next;
    while (p != phead) {
        printf("<-| |%d| |->", p->data);
        p = p->next;
    }
    printf("\n");
}

int main() {
    DNode* head = (DNode*)malloc(sizeof(DNode));
    init(head);
    printf("추가단계\n");
    for (int i = 0; i < 5; i++) {
        dinsert(head, i);
        printDlist(head);
    }
    printf("삭제단계\n");
    for (int i = 0; i < 5; i++) {
        printDlist(head);
        ddelete(head, head->next);
    }
    free(head);
    return 0;
}
