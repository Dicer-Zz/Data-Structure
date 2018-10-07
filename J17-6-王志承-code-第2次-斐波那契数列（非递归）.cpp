#include <bits/stdc++.h>
using namespace std;

int main(){
	cout << "Input a number(no greater than 100)" << endl;
	long long n;
	cin >> n;
	cout << "The " << n << "th item of Fibonacci if: ";
	if(n == 1 || n == 2)	cout << 1 << endl;
	else{
		long long ans = 0, a, b;
		a = b = 1;
		for(int i=3;i<=n;++i){
			ans = a + b;
			a = b;
			b = ans;
		}
		cout << ans << endl;
	}
	return 0;
}