#include <bits/stdc++.h>
#include "getfrequency.cpp"
const int INF = 0x3f3f3f3f;
using namespace std;
typedef struct{
	char data;
	int weight;
	int parent, lchild, rchild;
}HTNode, *HuffmanTree;

bool vis[1000];
void Select(HuffmanTree &HT, int n, int &s1, int &s2){
	int min1 = INF, min2 = INF;
	for(int i=1;i<=n;++i){
		if(vis[i])	continue;
		if(min2 > HT[i].weight){
			min2 = HT[i].weight;
			s2 = i;
		}
		if(min1 > min2){
			swap(s1, s2);
			swap(min1, min2);
		}
	}
	vis[s1] = vis[s2] = 1;
}

ifstream fin;
ofstream fout;
void print(HuffmanTree HT, int x){
	if(HT[x].parent == 0)	return;
	print(HT, HT[x].parent);
	if(HT[HT[x].parent].lchild == x)	fout << 0;
	else	fout << 1;
}
void CreatHuffmanTree(HuffmanTree &HT){
	GetFrenquency();
	fin.open("frequency.txt");
	fout.open("recode.txt");
	int n;
	fin >> n;
	if(n<=1)	return;
	int m = 2*n-1;
	HT = new HTNode[m+1];
	for(int i=1;i<=m;++i){
		HT[i].parent = 0;
		HT[i].lchild = 0;
		HT[i].rchild = 0;
	}
	char ch;
	for(int i=1	;i<=n;++i){
		ch = fin.get();
		HT[i].data = fin.get();
		// fin >> HT[i].data;
		fin >> HT[i].weight;
	}
	int s1, s2;
	for(int i=n+1;i<=m;++i){
		Select(HT, i-1, s1, s2);
		HT[s1].parent = i;
		HT[s2].parent = i;
		HT[i].lchild  = s1;
		HT[i].rchild  = s2;	
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
	for(int i=1;i<=n;++i){
		fout << HT[i].data << ' ';
		print(HT, i);
		fout << endl;
	}
	fin.close();
	fout.close();
}

// int main(){
// 	HuffmanTree HT;
// 	CreatHuffmanTree(HT);
// 	return 0;
// }