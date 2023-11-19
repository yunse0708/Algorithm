#include <stdio.h>
#include <stdlib.h>

const int MAX = 5000;

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    Node* head = createNode(1);
    Node* current = head;
    
    
    for (int i = 2; i <= n; i++) {
        current->next = createNode(i);
        current = current->next;
    }
    current->next = head; 

    printf("<");
    current = head;
    Node* prev = NULL;

    while (n > 0) {
        
        for (int i = 0; i < k - 1; i++) {
            prev = current;
            current = current->next;
        }

        // Print the k-th node's data
        printf("%d", current->data);

        // Remove the k-th node from the list
        if (prev != NULL) {
            prev->next = current->next;
        }
        Node* toFree = current;
        current = current->next;
        free(toFree);

        n--;

        if (n > 0) {
            printf(", ");
        }
    }

    printf(">\n");

    return 0;
}
