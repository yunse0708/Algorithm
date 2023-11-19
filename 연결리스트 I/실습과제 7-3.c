#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef int element;

typedef struct {
    element array[MAX];
    int size;
} ArrayList;

void init(ArrayList* L) {
    L->size = 0;
}

int isEmpty(ArrayList* L) {
    return L->size == 0;
}

int isFull(ArrayList* L) {
    return L->size == MAX;
}

element getEntry(ArrayList* L, int pos) {
    if (pos < 0 || pos >= L->size) {
        exit(1);
    }
    return L->array[pos];
}

void printList(ArrayList* L) {
    for (int i = 0; i < L->size; i++) {
        printf("%d", L->array[i]);
        if (i < L->size - 1) {
            printf("->");
        }
    }
    printf("->\n");
}

void insertLast(ArrayList* L, element item) {
    if (isFull(L)) {
        return;
    }
    L->array[L->size++] = item;
}

void insert(ArrayList* L, int pos, element item) {
    if (isFull(L)) {
        return;
    }
    if (pos < 0 || pos > L->size) {
        return;
    }

    for (int i = L->size; i > pos; i--) {
        L->array[i] = L->array[i - 1];
    }

    L->array[pos] = item;
    L->size++;
}

element delete(ArrayList* L, int pos) {
    if (isEmpty(L) || pos < 0 || pos >= L->size) {
        exit(1);
    }

    element deletedItem = L->array[pos];

    for (int i = pos; i < L->size - 1; i++) {
        L->array[i] = L->array[i + 1];
    }

    L->size--;
    return deletedItem;
}

int main() {
    ArrayList list;
    init(&list);

    insertLast(&list, 10);
    printList(&list);

    insertLast(&list, 20);
    printList(&list);

    insertLast(&list, 30);
    printList(&list);

    insertLast(&list, 40);
    printList(&list);

    insert(&list, 2, 100);
    printList(&list);

    delete(&list, 1);
    printList(&list);

    return 0;
}
