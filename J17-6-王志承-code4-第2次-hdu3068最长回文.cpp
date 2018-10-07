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
const int MAXN = 2e5;
const int MAXM = 2e5;

char s[MAXN];
char s_new[MAXN];
int p[MAXN];

int Init()
{
    int len = strlen(s);
    s_new[0] = '$';
    s_new[1] = '#';
    int j = 2;
    for (int i = 0; i < len; i++)
    {
        s_new[j++] = s[i];
        s_new[j++] = '#';
    }
    s_new[j] = '\0';
    
    return j; 
}

int Manacher()
{
    int len = Init();
    int max_len = -1; 
    int id = 1;
    int mx = 0;
    for (int i = 1; i < len; i++)
    {
        if (i < mx)
            p[i] = min(p[2 * id - i], mx - i);
        else
            p[i] = 1;
        while (s_new[i - p[i]] == s_new[i + p[i]]) 
            p[i]++;
        if (mx < i + p[i])
        {
            id = i;
            mx = i + p[i];
        }
        max_len = max(max_len, p[i] - 1);
    }
    return max_len;
}
int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	while(~scanf("%s",s)){
		cout << Manacher() << endl;
	}
	return 0;
}