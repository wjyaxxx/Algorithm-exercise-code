#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
void solve()
{
    long long n,m;
    int a,b;
    cin>>n>>m>>a>>b;
    if((n*m)&1) {
        cout<<"No\n";
        return;
    }
    //什么限制都没有
    if((a&&b) || (n*m==2)){
        cout<<"Yes\n";
        return ;
    }  
    //有限制1 将偶数边一直竖着放
    if(!a && b){
        if((n==1)||(m==1)) cout<<"No\n";
        else cout<<"Yes\n";
        return ;
    }
    //有限制2,只能 
    if(a && !b){
        if((n==1)||(m==1)) cout<<"Yes\n";
        else cout<<"No\n";
        return;
    }
    //两个限制有
    cout<<"No\n";
}
int main()
{
    read_fast;
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}