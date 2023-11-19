// 동적으로 구조체 생성하기
#include<stdio.h>
#include<stdlib.h>
typedef int element;
//1)Node 구조체를 전역에 정의
typedef struct Node{
    element data;
    struct Node *next;//자기참조 구조체: 자기자신을 참조하는 포인터를 포함
}Node;

int main(){
	 Node *n1, *n2 ,*n3, *head;
    n1 = (Node *)malloc(sizeof(Node));
    n2 = (Node *)malloc(sizeof(Node));
		n3 = (Node *)malloc(sizeof(Node));
    n1 -> data = 10;
    n1 -> next = n2;
 		n2 -> data = 20;
		n2 -> next = n3;
  	n3 -> data = 30;
	  n3 -> next = NULL;
    head = n1;
    while( head ){
        printf("%d->", head->data);
       //9) head에 다음 노드 주소 저장
			  head = head -> next;
    }
}
