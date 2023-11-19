#include <stdio.h>

// 이진 트리 노드를 나타내는 구조체 정의
typedef struct Node {
    char data;           // 노드의 데이터 (문자로 가정)
    struct Node* left;   // 왼쪽 자식을 가리키는 포인터
    struct Node* right;  // 오른쪽 자식을 가리키는 포인터
} Node;

// 전위 순회를 수행하는 함수
void preorderTraversal(Node* root) {
    if (root != NULL) {
        printf("%c", root->data);       // 현재 노드의 데이터 출력
        preorderTraversal(root->left);  // 왼쪽 서브트리를 재귀적으로 순회
        preorderTraversal(root->right); // 오른쪽 서브트리를 재귀적으로 순회
    }
}

// 중위 순회를 수행하는 함수
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);   // 왼쪽 서브트리를 재귀적으로 순회
        printf("%c", root->data);       // 현재 노드의 데이터 출력
        inorderTraversal(root->right);  // 오른쪽 서브트리를 재귀적으로 순회
    }
}

// 후위 순회를 수행하는 함수
void postorderTraversal(Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);  // 왼쪽 서브트리를 재귀적으로 순회
        postorderTraversal(root->right); // 오른쪽 서브트리를 재귀적으로 순회
        printf("%c", root->data);        // 현재 노드의 데이터 출력
    }
}

int main() {
    int N;
    scanf("%d", &N);  // 이진 트리의 노드 수 입력

    // 이진 트리를 나타내는 Node 구조체 배열 생성
    Node nodes[N];

    // 배열의 각 노드를 데이터로 초기화하고 왼쪽 및 오른쪽 포인터를 NULL로 설정
    for (int i = 0; i < N; i++) {
        nodes[i].data = 'A' + i;  // 노드에 데이터 할당 ('A', 'B', 'C', ...)
        nodes[i].left = NULL;     // 왼쪽 자식 포인터를 NULL로 초기화
        nodes[i].right = NULL;    // 오른쪽 자식 포인터를 NULL로 초기화
    }

    // 이진 트리의 노드 간의 관계 입력
    for (int i = 0; i < N; i++) {
        char parent, leftChild, rightChild;
        scanf(" %c %c %c", &parent, &leftChild, &rightChild);

        // 왼쪽 자식 포인터 업데이트 (만약 존재한다면)
        if (leftChild != '.') {
            nodes[parent - 'A'].left = &nodes[leftChild - 'A'];
        }

        // 오른쪽 자식 포인터 업데이트 (만약 존재한다면)
        if (rightChild != '.') {
            nodes[parent - 'A'].right = &nodes[rightChild - 'A'];
        }
    }

    // 전위 순회를 수행하고 결과 출력
    preorderTraversal(&nodes[0]);
    printf("\n");

    // 중위 순회를 수행하고 결과 출력
    inorderTraversal(&nodes[0]);
    printf("\n");

    // 후위 순회를 수행하고 결과 출력
    postorderTraversal(&nodes[0]);
    printf("\n");

    return 0;
}
