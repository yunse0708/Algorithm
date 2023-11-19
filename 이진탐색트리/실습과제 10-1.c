#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 단어와 의미를 담는 element 구조체 정의
typedef struct {
    char word[100];
    char meaning[200];
} element;

// 이진 트리 노드를 나타내는 TNode 구조체 정의
typedef struct TNode {
    element key;             // 노드의 키 값
    struct TNode *left, *right; // 왼쪽, 오른쪽 서브트리 포인터
} TNode;

// 두 element를 비교하여 두 단어의 사전 순서를 반환하는 함수
int compare(element e1, element e2) {
    return strcmp(e1.word, e2.word);
}

// 이진 트리를 중위 순회하여 출력하는 함수
void display(TNode *p) {
    if (!p)
        return;

    display(p->left);
    printf("(%s:%s)", p->key.word, p->key.meaning);
    display(p->right);
}

// 주어진 키 값으로 노드를 검색하는 함수
TNode *search(TNode *root, element key) {
    if (root == NULL || compare(root->key, key) == 0)
        return root;

    if (compare(root->key, key) < 0)
        return search(root->right, key);

    return search(root->left, key);
}

// 새로운 노드를 생성하는 함수
TNode *new_node(element item) {
    TNode *temp = (TNode *)malloc(sizeof(TNode));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// 주어진 노드에 새로운 키를 가진 노드를 삽입하는 함수
TNode *insert_node(TNode *root, element key) {
    if (root == NULL)
        return new_node(key);

    if (compare(key, root->key) < 0)
        root->left = insert_node(root->left, key);
    else if (compare(key, root->key) > 0)
        root->right = insert_node(root->right, key);

    return root;
}

// 주어진 노드의 가장 작은 값을 가진 노드를 찾아 반환하는 함수
TNode *minNode(TNode *node) {
    TNode *current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}

// 주어진 노드에서 주어진 키를 가진 노드를 삭제하는 함수
TNode *deleteNode(TNode *root, element key) {
    if (root == NULL)
        return root;

    if (compare(key, root->key) < 0)
        root->left = deleteNode(root->left, key);
    else if (compare(key, root->key) > 0)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            TNode *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            TNode *temp = root->left;
            free(root);
            return temp;
        }

        TNode *temp = minNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

int main() {
    char command;
    element e;
    TNode *root = NULL;
    TNode *tmp;

    do {
        printf("\n****i:입력, d:삭제, s:탐색, p:출력, q:종료****:\n");
        command = getchar();
        getchar(); // 새 줄 문자 소비

        switch (command) {
            case 'i':
                printf("단어:\n");
                fgets(e.word, sizeof(e.word), stdin);
                e.word[strcspn(e.word, "\n")] = '\0';

                printf("의미:\n");
                fgets(e.meaning, sizeof(e.meaning), stdin);
                e.meaning[strcspn(e.meaning, "\n")] = '\0';

                root = insert_node(root, e);
                break;
            case 'd':
                printf("단어:\n");
                fgets(e.word, sizeof(e.word), stdin);
                e.word[strcspn(e.word, "\n")] = '\0';

                root = deleteNode(root, e);
                break;
            case 's':
                printf("단어:\n");
                fgets(e.word, sizeof(e.word), stdin);
                e.word[strcspn(e.word, "\n")] = '\0';

                tmp = search(root, e);
                if (tmp != NULL) {
                    printf("의미: %s\n", tmp->key.meaning);
                } else {
                    printf("\n");
                }
                break;
            case 'p':
                display(root);
                printf("\n");
                break;
        }
    } while (command != 'q');

    return 0;
}
