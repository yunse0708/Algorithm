#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX 30

// 그래프 구조체 정의
typedef struct graphType {
    int n; // 정점의 개수
    int adjMatrix[MAX_VERTEX][MAX_VERTEX]; // 인접 행렬
} graphType;

// 그래프 초기화 함수
void createGraph(graphType *g) {
    int i, j;
    g->n = 0; // 정점의 개수 초기화
    // 인접 행렬 30*30 초기화 (모든 원소를 0으로)
    for (i = 0; i < MAX_VERTEX; i++) {
        for (j = 0; j < MAX_VERTEX; j++) {
            g->adjMatrix[i][j] = 0;
        }
    }
}

// 정점 삽입 함수
void insertVertex(graphType *g) {
    if ((g->n) + 1 > MAX_VERTEX) {
        printf("\n 그래프 정점의 개수를 초과하였습니다!");
        return;
    }
    g->n++; // 정점 개수 증가
}

// 간선 삽입 함수
void insertEdge(graphType *g, int u, int v) {
    if (u >= g->n || v >= g->n) {
        printf("\n 그래프에 없는 정점입니다!");
        return;
    }
    // 무방향 그래프이므로 [u][v], [v][u] 모두 1로 설정
    g->adjMatrix[u][v] = 1;
    g->adjMatrix[v][u] = 1;
}

// 인접 행렬 출력 함수
void print_adjMatrix(graphType *g) {
    int i, j;
    for (i = 0; i < g->n; i++) {
        printf("\n\t\t");
        for (j = 0; j < g->n; j++)
            printf("%2d", g->adjMatrix[i][j]);
    }
}

int main() {
    int i;
    graphType *G;
    G = (graphType *)malloc(sizeof(graphType)); // 동적 메모리 할당

    createGraph(G); // 그래프 초기화

    for (i = 0; i < 8; i++) {
        insertVertex(G); // 정점 8번 추가
    }

    // 간선 삽입
    insertEdge(G, 0, 1);
    insertEdge(G, 0, 2);
    insertEdge(G, 1, 3);
    insertEdge(G, 1, 4);
    insertEdge(G, 2, 5);
    insertEdge(G, 2, 6);
    insertEdge(G, 3, 7);
    insertEdge(G, 4, 7);
    insertEdge(G, 5, 7);
    insertEdge(G, 6, 7);

    printf("\n G의 인접 행렬");
    print_adjMatrix(G); // 인접 행렬 출력

    free(G); // 할당된 메모리 해제

    return 0;
}
