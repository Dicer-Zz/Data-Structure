#include <bits/stdc++.h>
#define MAXN 1024
using namespace std;

int front, rear, tag, Q[MAXN];

void InitQueue(){
	tag = 0;
	front = 0;
	rear = 0;
	memset(Q, 0, sizeof Q);
}

bool enqueue(int x) {
	if(tag == 1)	return 0;
	Q[rear] = x;
	rear = (rear+1)%MAXN;
	if(rear == front)	tag = 1;
	return 1;
}

bool dequeue(int &x){
	if(tag == 0 && front == rear)	return 0;
	x = Q[front];
	Q[front] = 0;
	front = (front+1)%MAXN;
	if(tag == 1)	tag = 0;
	return 1;
}

int main(){
	cout << "* Welcome to use the LoopQueue 8102" << endl;
	cout << "* The program is easy to use ;)" << endl;
	cout << "* The program can carry out enqueue and dequeue" << endl;
	cout << "* The maximun capacity of the program's queue if 1024" << endl;
	cout << "* First input what times you want to operator " << endl;
	cout << "* If you want to enqueue, you should typing 1 and which number you want to enqueu" << endl;
	cout << "* If you want to dequeue, you should typing 2" << endl;
	cout << "/------------------------------------------------------------------------------/" << endl << endl;
	InitQueue();
	int n;
	cout << "Input the number of the operator : " << endl;
	cin >> n;
	int op, x;
	while(n--){
		cin >> op;
		if(op == 1){
			cin >> x;
			if(enqueue(x) == 0){
				cout << "Queue is Full!" << endl;
			} else{
				cout << "Enqueue is finished" << endl;
			}
		}
		else if(op == 2){
			if(dequeue(x)){
				cout << "The value of front is: " << x << endl;
			}
			else {
				cout << "Queue is empty!" << endl;
			}
		}
	}
	return 0;
}