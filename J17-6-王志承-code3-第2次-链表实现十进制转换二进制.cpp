#include <stdio.h> 
#include <malloc.h> 
#include <iostream>
using namespace std;
typedef int ElemType; 
typedef int SElemType; 
typedef int Status;
#define OK 1 
#define EROOR 0 
#define True 1 
#define False 0 
typedef struct StackNode
{ 
    ElemType data;
    struct StackNode *next;
}StackNode, *LinkStack; 
  
//初始化栈 
Status InitStack(LinkStack &s) 
{ 
	s = NULL;
	return OK;
} 
Status Push(LinkStack &s, SElemType e){
	StackNode *p;
	p = new StackNode;
	p->data = e;
	p->next = s;
	s  = p;
	return OK;
}

Status Pop(LinkStack &s, SElemType &e){
	StackNode *p;
	if(s == NULL)	return EROOR;
	e = s->data;
	p = s;
	s = s->next;
	delete p;
	return OK;
}

SElemType GetTop(LinkStack s, SElemType &x){
	if(s == NULL)	return 0;
	else {
		x = s->data;
		return 1;
	}
}
int main() 
{ 
    LinkStack s;
    InitStack(s); 
    long long n;
    cin >> n;
    while(n){
        Push(s,n&1);
        n >>= 1;
    }
    int x;
    while(s != NULL) {
        Pop(s,x);
        cout << x;
    }
    return 0; 
} 

