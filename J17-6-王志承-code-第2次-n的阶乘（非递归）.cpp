#include <bits/stdc++.h>
using namespace std;

int main(){
	cout << "Input a number (no less than 0, no greater than 20):" << endl;
	long long n;
	cin >> n;
	cout << "The factorial of n is: ";
	long long ans = 1;
	for(long long i=1;i<=n;++i)	ans *= i;
	cout << ans << endl;
	return 0;
}