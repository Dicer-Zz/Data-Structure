#include <bits/stdc++.h>
#include "huffmantree.cpp"
using namespace std;

HuffmanTree recodetext(){
	HuffmanTree HT;
	CreatHuffmanTree(HT);
	ifstream fin("recode.txt");
	ofstream fout("recode-text.txt");
	char ch;
	string s;
	map<char, string> dic;
	while((ch = fin.get()) != EOF){
		fin >> s;
		dic[ch] = s;
		// fout << ch << endl;
		ch = fin.get();
	}
	fin.close();
	fin.open("text.txt");
	while((ch = fin.get()) != EOF){
		// if(ch == '\n')	continue;
		fout << dic[ch];
	}
	fin.close();
	fout.close();
	return HT;
}

// int main(){
// 	recodetext();
// 	return 0;
// }