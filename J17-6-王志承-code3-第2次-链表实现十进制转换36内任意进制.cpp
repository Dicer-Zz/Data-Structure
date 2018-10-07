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
char dic[40] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
int main() 
{ 
    long long n, m;
    LinkStack s;
    while(cin >> n >> m){
    	if(n < 0)	cout << '-';
    	n = abs(n);
	    InitStack(s);
	    while(n){
	        Push(s,n%m);
	        n /= m;
	    }
	    int x;
	    while(s != NULL) {
	        Pop(s,x);
	        cout << dic[x];
	    }
	    cout << endl;
	}
    return 0; 
} 

