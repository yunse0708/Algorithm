#include <stdio.h> 
#include <stdlib.h>
typedef int element;
typedef struct Node{
   element data;
   struct Node* next;
}Node;
//0)노드 구조체 작성

void printList(Node* head){
   Node *p = head->next;//리스트의 첫위치 저장
   int count = 0;
   if (head == NULL) return;
   do {
      if(p == NULL) break;
      printf("%d->",p->data);
      p = p->next;//다음 노드값 저장
    }while(p != head->next);//p의 값이 첫위치가 아니면
   printf("\n");
 //}while(cnt <10);
}
Node* insertFirst(Node* head, element data){
   Node* p = head;
   Node* node = (Node*)malloc(sizeof(Node));//Node 동적할당
   node->data = data;//
   if (head == NULL){
      head = node;
      node->next = head;
   }
   else{
      node->next = head->next;//새로운노드의 다음 주소로 head 저장
      head->next = node;
   }
   return head;
}
Node* insertLast(Node* head, element data){
   Node* node = (Node*)malloc(sizeof(Node));//노드 동적할당
   node->data =data;
   if (head == NULL){
      head=node;// head의 주소로 새로운노드의 주소 저장
      head->next = node;
   }
   else{
      node->next = head->next;
      head->next = node;
      head = node;
   }
   return head;
}

Node* chageCard(Node* head){
   Node* removed = head->next; //노드삭제위치 저장
  head->next = removed->next;//삭제된 다음 위치와 연결
   free(removed);
   return head->next;// 새로운 헤드값으로 리턴
}
int main() {
   Node *head = NULL, *p;
   int n  ;
   printf("카드개수 입력\n");
    scanf("%d",&n);
//   printf("마지막위치에 연결\n");
   for(int i = 1;i <= n;i++){
      head = insertLast(head,i);//노드 삽입함수 호출
   }
//   printf("head노드 = %d\n",head->data);
   for(int i = 1;i < n;i++) {
      head = chageCard(head);//카드 제거함수 호출
      printList(head);
   }
    printf("마지막 카드번호 : %d",head->data);
   return 0;
}