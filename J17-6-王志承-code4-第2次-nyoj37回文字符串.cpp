#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define clr(s, x) memset(s, x, sizeof(s))
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
inline int read(){int r=0;char c=getchar();while(c<'0'||c>'9') {c=getchar();}while(c>='0'&&c<='9') {r=r*10+c-'0';c=getchar();}return r;}
inline ll readll(){ll r=0;char c=getchar();while(c<'0'||c>'9') {c=getchar();}while(c>='0'&&c<='9') {r=r*10+c-'0';c=getchar();}return r;}
inline ll qpow(ll a,ll b,ll mod){ll res=1;while(b){if(b&1)res = (res*a)%mod;a=(a*a)%mod;b>>=1;}return res;}
inline ll gcd(ll a,ll b){while(b^=a^=b^=a%=b);return a;}
const double eps = 1e-8;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const int MAXN = 2e3;
const int MAXM = 2e3;

int dp[MAXN][MAXN];
int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	string a,b;
	while(T--){
		clr(dp, 0);
		cin >> a;
		b = a;
		reverse(b.begin(),b.end());
		int len = a.length();
		for(int i=1;i<=len;++i){
			for(int j=1;j<=len;++j){
				if(a[i-1] == b[j-1])	dp[i][j] = dp[i-1][j-1]+1;
				else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
		cout << len-dp[len][len] << endl;
	}
	return 0;
}