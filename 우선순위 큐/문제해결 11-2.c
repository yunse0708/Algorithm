#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENT 200

// 요소 구조체 정의
typedef struct {
    int key;
} element;

// 최대힙 구조체 정의
typedef struct {
    element heap[MAX_ELEMENT];
    int heap_size;
} HeapType;

// 최대힙 생성 함수
HeapType* create() {
    HeapType* h = (HeapType*)malloc(sizeof(HeapType)); // 힙 구조체 동적 할당
    return h;
}

// 최대힙 초기화 함수
void init(HeapType* h) {
    h->heap_size = 0; // 힙 크기 초기화
}

// 최대힙에 요소 삽입 함수
void insert_max_heap(HeapType* h, element item) {
    int i;
    i = ++(h->heap_size);

    // 부모와 비교하면서 힙 속성 유지
    while (i != 1 && item.key > h->heap[i / 2].key) {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }

    h->heap[i] = item; // 새로운 노드 삽입
}

// 최대힙에서 요소 삭제 함수
element delete_max_heap(HeapType* h) {
    int parent, child;
    element item, temp;
    item = h->heap[1]; // 삭제할 노드(최대값) 저장
    temp = h->heap[(h->heap_size)--]; // 마지막 노드를 가져와서 힙 크기 감소
    parent = 1;
    child = 2;

    // 루트부터 마지막 레벨까지 힙 속성 유지하며 내려가기
    while (child <= h->heap_size) {
        // 현재 노드의 자식 중 더 큰 자식을 선택
        if ((child < h->heap_size) && (h->heap[child].key < h->heap[child + 1].key))
            child++;

        // 마지막 노드보다 크면 종료
        if (temp.key >= h->heap[child].key) break;

        // 한 단계 아래로 이동
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }

    h->heap[parent] = temp; // 삭제한 노드의 위치에 새로운 노드 삽입
    return item;
}

// 최대힙을 이용한 정렬 함수
void heap_sort(element a[], int n) {
    int i;
    HeapType* h = create(); // 힙 생성
    init(h); // 힙 초기화

    // 최대힙에 요소 삽입
    for (i = 0; i < n; i++) {
        insert_max_heap(h, a[i]);
    }

    // 최대힙에서 삭제하여 배열에 역순으로 저장 (정렬)
    for (i = n - 1; i >= 0; i--) {
        a[i] = delete_max_heap(h);
    }

    free(h); // 동적 할당 해제
}

#define SIZE 8

int main() {
    element list[SIZE] = {23, 56, 11, 9, 56, 99, 27, 34};
    heap_sort(list, SIZE);

    // 정렬된 결과 출력
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", list[i].key);
    }

    printf("\n");

    return 0;
}
