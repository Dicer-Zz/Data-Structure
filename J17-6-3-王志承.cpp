#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct Node {
    ElemType data;               
    struct Node *next;          
}Node,*LinkedList;

LinkedList LinkedListInit() {
    Node *L;
    L = (Node *)malloc(sizeof(Node)); 
    if(L == NULL) { 
        printf("申请内存空间失败\n");
    }
    L->next = NULL;                  
 	return L;
}
 
LinkedList LinkedListCreatH() {
    Node *L;
    L = LinkedListInit();
    ElemType x;                    
    while(scanf("%d",&x) != EOF) {
        Node *p;
        p = (Node *)malloc(sizeof(Node));    
        p->data = x;                      
        p->next = L->next;
        L->next = p; 
    }
    return L; 
} 
LinkedList LinkedListCreatT() {
	Node *L,*q;
    L = LinkedListInit();
    ElemType x;
    q = L;                 
    while(scanf("%d",&x) != EOF) {
        Node *p;
        p = (Node *)malloc(sizeof(Node));
        p->data = x;
        p->next = NULL;
        q->next = p;
        q = q->next;
    }
    return L; 
}
 
LinkedList LinkedListInsert(LinkedList L,int i,ElemType x) {
    Node *pre;
    pre = L;
    int tempi;
    for (tempi = 1; tempi < i && pre != NULL; tempi++) {
    	pre = pre->next;
	}
	if(pre == NULL){
		printf("插入失败\n");
		return L;
	}
    Node *p;
    p = (Node *)malloc(sizeof(Node));
    p->data = x; 
    p->next = pre->next;
    pre->next = p;
    return L;
} 

LinkedList LinkedListDelete(LinkedList L,ElemType x)
{
    Node *p,*pre;
    pre = L;
    p = L->next;
    while(p->data != x && p != NULL) {               
        pre = p; 
        p = p->next;
    }
    if(p == NULL){
    	printf("删除失败\n");
    	return L;
    }
    pre->next = p->next;
    free(p);
    return L;
} 

void LinkedListFind(LinkedList L, ElemType x){
	Node *p;
	p = L->next;
	int i=1;
	while(p != NULL && p->data != x)	p = p->next,i++;
	if(p == NULL){
		printf("查找失败!\n");
		return;
	}
	printf("%d在第%d个位置\n", x, i);
}
int main() {
    LinkedList list,start;
 	int kase = 0;
 	printf("选择插入方式\n1：前插\n2：尾插\n");
 	scanf("%d",&kase);
 	printf("请输入单链表的数据："); 
 	switch(kase){
 		case 1:
 			list = LinkedListCreatT();
 			break;
 		case 2:
 			list = LinkedListCreatH();
 			break;
 	}
    for(start = list->next; start != NULL; start = start->next) {
    	printf("%d ",start->data);
	}
    printf("\n");
    int i;
    ElemType x;
    printf("请输入插入数据的位置：");
    scanf("%d",&i);
    printf("请输入插入数据的值：");
    scanf("%d",&x);
    LinkedListInsert(list,i,x);
    for(start = list->next; start != NULL; start = start->next) {
    	printf("%d ",start->data);
	}
    printf("\n");
    printf("请输入要删除的元素的值：");
    scanf("%d",&x);
    LinkedListDelete(list,x); 
    for(start = list->next; start != NULL; start = start->next) {
    	printf("%d ",start->data);
	}
    printf("\n");
    printf("请输入要查寻的元素的值：");
    scanf("%d",&x);
    LinkedListFind(list,x);
    return 0;
}
