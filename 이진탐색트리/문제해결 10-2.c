#include<stdio.h> 
#include<stdlib.h> 

typedef char element;
typedef struct TNode {
    element key;
    struct TNode* left;
    struct TNode* right;
} TNode;

// 이진 탐색 트리에서 주어진 키를 갖는 노드를 찾는 함수
TNode* search(TNode* node, element key) {
    // 기저 조건: 노드가 NULL이면 키를 찾지 못한 것이므로 NULL 반환
    if (node == NULL) 
        return NULL;
    // 현재 노드의 키와 찾고자 하는 키가 일치하면 현재 노드 반환
    if (key == node->key) 
        return node;
    // 찾고자 하는 키가 현재 노드의 키보다 작으면 왼쪽 서브트리에서 재귀적으로 탐색
    else if (key < node->key) 
        return search(node->left, key);
    // 찾고자 하는 키가 현재 노드의 키보다 크면 오른쪽 서브트리에서 재귀적으로 탐색
    else
        return search(node->right, key);
}


// 노드를 동적으로 생성하고 초기화하는 함수
TNode* newNode(element key){
    TNode* temp = (TNode*)malloc(sizeof(TNode)); // 새로운 노드 메모리 할당
    temp->key = key; // 키 값 초기화
    temp->left = temp->right = NULL; // 왼쪽과 오른쪽 자식 포인터 초기화
    return temp;
}

// 이진 탐색 트리에 새로운 노드를 삽입하는 함수
TNode* insertNode(TNode* node, element key){
    if (node == NULL) return newNode(key); // 노드가 비어있으면 새로운 노드 생성
    else if (key < node->key){
        node->left = insertNode(node->left, key); // 왼쪽 서브트리에 재귀적으로 삽입
    }
    else if (key > node->key) {
        node->right = insertNode(node->right, key); // 오른쪽 서브트리에 재귀적으로 삽입
    }
    return node;
}

// 주어진 노드에서 가장 작은 키를 찾아 반환하는 함수
TNode* minNode(TNode* node){
    TNode* cur = node;
    while(cur->left != NULL){
        cur = cur->left; // 가장 작은 키를 가진 노드까지 왼쪽으로 이동
    }
    return cur;
}


// 주어진 노드를 삭제하고 적절한 노드로 대체하는 함수
TNode* deleteNode(TNode* root, element key){
    if (root == NULL) return root; // 루트가 비어있으면 반환

    if (key < root->key) {
        root->left = deleteNode(root->left, key); // 왼쪽 서브트리에서 삭제 수행
    }
    else if(key > root->key){
        root->right = deleteNode(root->right, key); // 오른쪽 서브트리에서 삭제 수행
    } 
    else {
        if (root->left == NULL){
            TNode* temp = root->right;
            free(root); // 노드 삭제
            return temp;
        }
        else if (root->right == NULL){
            TNode* temp = root->left;
            free(root); // 노드 삭제
            return temp;
        }

        TNode* temp = minNode(root->right); // 오른쪽 서브트리에서 가장 작은 키를 찾음
        root->key = temp->key; // 찾은 키로 현재 노드의 값을 갱신
        root->right = deleteNode(root->right, temp->key); // 중복된 노드 삭제
    }
    return root;
}

// 주어진 이진 탐색 트리를 중위 순회하여 출력하는 함수
void inorder(TNode* root){
    if (root != NULL){
        inorder(root->left); // 왼쪽 서브트리 순회
        printf("[%c] ", root->key); // 현재 노드 방문 출력
        inorder(root->right); // 오른쪽 서브트리 순회
    }
}

void menu(){
    printf("\n*-----------------------*\n");
    printf("\n\t1 : 트리 출력\n");
    printf("\n\t2 : 문자 삽입\n");
    printf("\n\t3 : 문자 삭제\n");
    printf("\n\t4 : 문자 검색\n");
    printf("\n\t5 : 종료\n");
    printf("\n*-----------------------*\n");
    printf("\n메뉴 입력 >> ");
}

int main() {
    TNode* root = NULL;
    TNode* foundedNode = NULL;
    char choice, key;

    root = insertNode(root,'G');
    insertNode(root,'I');
    insertNode(root,'H');
    insertNode(root,'D');
    insertNode(root,'B');
    insertNode(root,'M');
    insertNode(root,'N');
    insertNode(root,'A');
    insertNode(root,'J');
    insertNode(root,'E');
    insertNode(root,'Q');

    while (1) {
    menu();                 // 사용자에게 메뉴를 보여주는 함수 호출
    scanf(" %c", &choice);  // 사용자의 선택을 입력받음

    switch (choice - '0') {
        case 1: 
            printf("\n[이진 트리 출력] ");
            inorder(root);      // 중위 순회 함수 호출하여 이진 트리 출력
            printf("\n");
            break;

        case 2: 
            printf("삽입할 문자를 입력하세요 : ");
            scanf(" %c", &key);
            foundedNode = search(root, key);   // 삽입할 문자가 이미 트리에 있는지 검색
            if (foundedNode != NULL)
                printf("\n이미 같은 키가 있습니다!\n");
            else
                root = insertNode(root, key);  // 새로운 노드를 삽입하는 함수 호출
            break;

        case 3: 
            printf("삭제할 문자를 입력하세요 : ");
            scanf(" %c", &key);
            foundedNode = search(root, key);   // 삭제할 문자가 트리에 있는지 검색
            if (foundedNode == NULL)
                printf("\n찾는 키가 이진 트리에 없습니다!!\n");
            else
                root = deleteNode(root, key);  // 노드를 삭제하는 함수 호출
            break;

        case 4: 
            printf("찾을 문자를 입력하세요 : ");
            scanf(" %c", &key);
            foundedNode = search(root, key);   // 찾을 문자가 트리에 있는지 검색
            if (foundedNode != NULL)
                printf("\n%c를 찾았습니다!\n", foundedNode->key);
            else
                printf("\n문자를 찾지 못했습니다.\n");
            break;

        case 5: 
            return 0;  // 프로그램 종료

        default: 
            printf("없는 메뉴입니다. 메뉴를 다시 선택하세요!\n");
            break;
    }


    }
}
