#include<stdio.h>
#include<stdlib.h>

typedef struct TNode {
	int data;
	struct TNode *left, *right;
} TNode;

TNode n1 = { 1, NULL, NULL };
TNode n2 = { 4, NULL, NULL };
TNode n3 = { '*', &n1, &n2 };
TNode n4 = { 16, NULL, NULL };
TNode n5 = { 25, NULL, NULL };
TNode n6 = { '+', &n4, &n5 };
TNode n7 = { '+', &n3, &n6 };
TNode *exp = &n7;

// 수식 계산 함수
int evaluate(TNode *root) {
	// root가 NULL일 경우 0 리턴
	if (root == NULL)
		return 0;
	// 자식 노드가 없을 경우 자신의 데이터 반환
	if (root->left == NULL && root->right == NULL)
		return root->data;
	// 자식 노드가 있을 경우 왼쪽의 노드와 오른쪽의 노드를 연산.
	else {
		// 첫 번째 피연산자에 왼쪽 자식 노드 결과값.
		int op1 = evaluate(root->left);
		// 두 번째 피연산자에 오른쪽 자식 노드 결과값.
		int op2 = evaluate(root->right);
		printf("%d %c %d을 계산합니다.\n", op1, root->data, op2);
		// root 노드 자신의 데이터(연산자)에 따라 연산 결과값 반환.
		if (root->data == '+')
			return op1 + op2;
		else if (root->data == '*')
			return op1 * op2;
	}
	return 0;
}

int main(void) {
	printf("수식의 값은 %d입니다. \n", evaluate(exp));
	return 0;
}
