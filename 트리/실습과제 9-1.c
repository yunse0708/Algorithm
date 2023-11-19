#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TNode {
    int data;
    struct TNode* left;
    struct TNode* right;
} TNode;

// ======================== 원형 큐 코드 시작 ========================

// 원형 큐 구현을 위한 매크로 상수와 구조체 정의
#define MAX_QUEUE_SIZE 100
typedef TNode* element;
typedef struct {
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} Queue;

// 오류 메시지 출력 후 프로그램 종료
void error(char* message) {
    fprintf(stderr, "%s", message);
    exit(1);
}

// 큐 초기화
void init_queue(Queue* q) {
    q->front = q->rear = 0;
}

// 큐가 비어있는지 여부를 반환
int is_empty(Queue* q) {
    return q->front == q->rear;
}

// 큐가 가득 차 있는지 여부를 반환
int is_full(Queue* q) {
    return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

// 큐에 원소를 삽입
void enqueue(Queue* q, element item) {
    if (is_full(q)) {
        error("Queue is full");
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

// 큐에서 원소를 제거하고 반환
element dequeue(Queue* q) {
    if (is_empty(q)) {
        error("Queue is empty");
    }
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

// ======================== 원형 큐 코드 끝 ========================

// 레벨 순회 함수
void level_order(TNode* ptr) {
    // 큐 생성 후 초기화
    Queue q;
    init_queue(&q);
    if (ptr == NULL) return;

    // 큐에 ptr 삽입
    enqueue(&q, ptr);

    // 큐가 비어있지 않을 때 반복
    while (!is_empty(&q)) {
        // 큐에서 꺼낸 노드를 ptr에 대입하여 데이터 출력
        TNode* node = dequeue(&q);
        printf("[%d] ", node->data);

        // 노드 ptr의 왼쪽 노드와 오른쪽 노드가 있으면 각각을 큐에 삽입
        if (node->left != NULL) {
            enqueue(&q, node->left);
        }
        if (node->right != NULL) {
            enqueue(&q, node->right);
        }
    }
}

// 이진 트리의 노드들을 생성
TNode n1 = { 1, NULL, NULL };
TNode n2 = { 4, NULL, NULL };
TNode n3 = { 16, NULL, NULL };
TNode n4 = { 25, NULL, NULL };
TNode n5 = { 20, NULL, NULL };
TNode n6 = { 15, NULL, NULL };
TNode* root = &n6;

int main() {
    // 이진 트리 구성
    n6.left = &n2;
    n6.right = &n5;
    n2.left = &n1;
    n2.right = &n3;
    n5.right = &n4;

    printf("레벨 순회 = ");
    level_order(root);
    printf("\n");

    return 0;
}
