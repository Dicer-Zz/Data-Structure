#include <bits/stdc++.h>
#include "recodetext.cpp"
using namespace std;

void compiletext(){
	int n, m;
	HuffmanTree HT;
	HT = recodetext();
	ifstream f("frequency.txt"),fin;
	ofstream fout("realtext.txt");
	f >> n;
	f.close();
	fin.open("recode-text.txt");
	m = 2*n -1;
	char x;
	int now;
	// fout << HT[1].data;
	while(fin >> x){
		now = m;
		if(x == '0')	now = HT[m].lchild;
		else if(x == '1')	now = HT[m].rchild;
		while(HT[now].lchild != 0 && HT[now].rchild != 0){
			fin >> x;
			if(x == '0')	now = HT[now].lchild;
			else if(x == '1')	now = HT[now].rchild;
		}
		fout << HT[now].data;  
	}
}