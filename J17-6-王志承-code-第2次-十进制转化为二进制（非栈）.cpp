#include<bits/stdc++.h>
using namespace std;

bool bn[64];
int main(){
	cout << "Input a decimal number(64bits) that you want chang to binary number:" << endl;
	long long num = 0;
	cin >> num;
	memset(bn, 0, sizeof bn);
	int cnt = 0;
	while(num){
		bn[cnt++] = num&1;
		num >>= 1;
	}
	cout << "The result is: " << endl;
	for(int i=cnt-1;i>=0;--i)	cout << bn[i];
	cout << endl;
	return 0;
}