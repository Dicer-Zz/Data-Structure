#include<bits/stdc++.h>
using namespace std;
struct ElemType{
	string name;
	int id;
};
typedef struct LNode{
	ElemType	data;
	struct LNode *next; 
	struct LNode *prior; 
}LNode, *CirList;
int length;
void InitList(CirList &L, int n){
	length = n;
	L = new LNode;
	CirList p;
	p = new LNode; 
	L->prior = NULL;
	L->next = p;
	for(int i=1; i<=n; ++i){
		p->next = new LNode;
		p->data.id = i;
		p->next->prior = p;
		if(i != n)	p = p->next;
	}
	p->next = L->next;
	L->next->prior = p;
//	cout << "Finish!" << endl;
}

void DeleteElem(CirList &L, int pos, int m){
	if(pos > length)	return;
	CirList p = L->next, q;
	int i=1;
	while(i<pos){
		++i;
		p = p->next;
	}
	cout << "Death order:" << endl;
	while(length >= m){
		--length;
		int tmp = m-1;
		while(tmp--)	p = p->next;
		if(p == L->next){
			L->next = p->next;
		}
		cout << p->data.id << ' ';
		q = p->next;
		p->prior->next = p->next;
		p->next->prior = p->prior;
		free(p);
		p = q;
	}
	cout << endl;
}
void PrintList(CirList &L, int n){
	if(length == 0){
		cout << "None Alive!" << endl;
		return;
	}
	CirList p;
	p = L->next;
	cout << length << " people alive" << endl;
	cout << "Their number is:" << endl;
	while(1){
		cout << p->data.id << ' ';
		if(p->next == L->next)	break;
		p = p->next;
	}
	cout << endl;
}
int main(){
	int n, pos, m;
	cout << "Input the number of people:" << endl;
	cin >> n;
	cout << "Input the number of death:"<< endl;
	cin >> m;
	cout << "Inpus the start position:"<< endl;
	cin >> pos;
	CirList L;
	InitList(L, n);
//	PrintList(L, n);
	DeleteElem(L, pos, m);
	PrintList(L, n);
	return 0;
}