#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int main()
{
    read_fast
    int n;
    cin>>n;
    
    vector<int> prime[n];
    int x;
    auto check=[&](int x)->bool{
        if(x==1) return false;
        bool ok=false;
        for(int i=2;i*i<=x;i++){
            if(x%i==0){
                ok=true;
                break;
            }
        }
        return (!ok);
    };


    auto f=[&](int x){
        vector<int> a;
        for(int i=1;i*i<=x;i++){
            if(x%i==0) {
                if(check(i)) a.push_back(i);
                if(i!=(x/i) && check(x/i)) a.push_back(x/i);
            }
        }  
        return a;
    };
    for(int i=0;i<n;i++){
        cin>>x;
        prime[i]=f(x);
        // for(auto x:prime[i]) cout<<x<<' ';
        // cout<<"\n";
    }
    int ans=1e9;
    int st[100]={0};
    auto dfs=[&prime,&ans,&n,&st](auto  self ,int u,int sum){
        if(u==n){
            ans=min(ans,sum);
            return ;
        }
        for(auto p:prime[u]){
            if(st[p]) continue;
            st[p]=1;
            self(self,u+1,sum+p);
            st[p]=0;
        }
    };
    dfs(dfs,0,0);
    if(ans!=1e9)
    cout<<ans<<"\n";
    else cout<<-1<<"\n";
    return 0;
}