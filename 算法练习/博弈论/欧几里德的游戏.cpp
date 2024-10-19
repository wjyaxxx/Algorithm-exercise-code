#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
bool dfs(int a,int b){
    if(!b) return false;
    if(a/b==1) return !dfs(b,a%b);
    else return true;
}
void solve()
{
    int a,b;
    cin>>a>>b;
    if(dfs(max(a,b),min(a,b))){
        cout<<"Stan wins\n";
    }else{
        cout<<"Ollie wins\n";
    }
}
int main()
{
    read_fast;
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}