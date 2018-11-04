#include <bits/stdc++.h>
using namespace std;

void GetFrenquency(){
	ifstream fin;
	ofstream fout;
	fin.open("text.txt");
	fout.open("frequency.txt");
	string s;
	set<char> charset;
	map<char, int> dic;
	int len;
	while(getline(fin, s)){
		len = s.length();
		for(int i=0;i<len;++i){
			// if(s[i] == ' ') continue;
			charset.insert(s[i]);
			dic[s[i]]++;
		}
		// dic['\n']++;
	}
	set<char>::iterator op = charset.begin();
	fout << charset.size() << endl;
	for(;op != charset.end();op++){
		fout << *op  << ' ' << dic[*op] << endl;
	}
	fin.close();
	fout.close();
}

// int main(){
// 	GetFrenquency();
// 	return 0;
// }