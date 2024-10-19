#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int  n,p;
int st1[520],st2[520];
long long ans;
void dfs(int  u,vector<int>&s1,vector<int>&s2){
    if(u>n){
        //检验
        bool ok=false;
        for(auto x:s1){
            for(auto y:s2){
                if(__gcd(x,y)!=1){
                    ok=true;
                    break;
                }
            }
        }
        if(!ok) {
            ans=(ans+1)%p;        
        }
        return ;
    }

    dfs(u+1,s1,s2);

    //给s1
    if(!st1[u]){
        s1.push_back(u);
        for(int i=u;i<=n;i+=u) st1[u]=1;
        dfs(u+1,s1,s2);
        for(int i=u;i<=n;i+=u) st1[u]=0;
        s1.pop_back();
    }
    if(!st2[u]){
        s2.push_back(u);
        for(int i=u;i<=n;i+=u) st2[u]=1;
        dfs(u+1,s1,s2);
        for(int i=u;i<=n;i+=u) st2[u]=0;
        s2.pop_back();
    }
}
int main()
{
    read_fast
    cin>>n>>p;
    vector<int> s1,s2;
    dfs(2,s1,s2);
    cout<<ans<<"\n";
    return 0;
}