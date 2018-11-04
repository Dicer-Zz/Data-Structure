#include <bits/stdc++.h>
#include "compile.cpp"
using namespace std;

int main(){
	ofstream fout("text.txt");
	cout << "Input a text." << endl;
	char ch;
	while((ch = getchar()) != EOF) fout.put(ch);
	fout.close();
	compiletext();
	cout << "Finish." << endl;
	return 0;
}