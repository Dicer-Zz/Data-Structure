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
    cout << "Push:  1" << endl;
    cout << "Pop:   2" << endl;
    cout << "Top:   3" << endl;
    cout << "Exit:  0" << endl;
    int kase, x;
    while(cin >> kase && kase){
        switch(kase){
        case 1:
            cin >> x;
            if(Push(s, x))  cout << "Insert finished." << endl;
            else cout << "INsert failed!" << endl;
            break;
        case 2:
            if(Pop(s, x)){
                cout << "The top of stack is:" << x << endl;
            }
            else    cout << "Pop failed!" << endl;
            break;
        case 3:
            if(GetTop(s,x)){
                cout << "The top of stack is:" << x << endl;
            }
            else    cout << "Pop failed!" << endl;
            break;
        }
    }
    return 0; 
} 

