#include <bits/stdc++.h>
using namespace std;

long long fac(long long n){
	if(n <= 0LL)	return 1LL;
	else return n*fac(n-1);
}
int main(){
	cout << "Input a number (no less than 0, no greater than 20):" << endl;
	long long n;
	cin >> n;
	cout << "The factorial of n is: ";
	cout << fac(n) << endl;
	return 0;
}