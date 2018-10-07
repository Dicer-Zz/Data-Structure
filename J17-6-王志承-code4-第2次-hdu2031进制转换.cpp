#include<bits/stdc++.h>
using namespace std;

char num[17] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G'};
void print(int n, int m){
    if(n){
        print(n/m,m);
        printf("%c",num[n%m]);
    }
}
int main(){
    int n, m;
    while(cin >> n >> m){
        if(n<0)    printf("-");
        print(abs(n), m);
        puts("");    
    }
    return 0;
}