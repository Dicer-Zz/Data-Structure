#include <bits/stdc++.h>
using namespace std;

long long fib(long long n){
	if(n == 1 || n == 2)	return 1;
	else	return fib(n-1)+fib(n-2);
}
int main(){
	cout << "Input a number(no greater than 25)" << endl;
	long long n;
	cin >> n;
	cout << "The " << n << "th item of Fibonacci if: ";
	cout << fib(n) << endl;
	return 0;
}