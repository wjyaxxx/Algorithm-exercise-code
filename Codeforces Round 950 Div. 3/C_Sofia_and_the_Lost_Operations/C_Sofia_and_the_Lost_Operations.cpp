#include <bits/stdc++.h>
using namespace std;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
const int N=2*1e5+10;
int modi[N],org[N];
void solve()
{
    int n;
    cin>>n;
   
    for(int i=1;i<=n;i++) cin>>org[i];
    for(int i=1;i<=n;i++) cin>>modi[i];
    int m;
    map<int,int> mp;
    cin>>m;
    int x;
    int the_last_one;
    for(int i=1;i<=m;i++){
        cin>>x;
        mp[x]++;
        if(i==m) the_last_one=x;
    }
    bool ok=false;
    for(int i=1;i<=n;i++){
        if(modi[i]==the_last_one) ok=true;
        if(org[i]!=modi[i]&&(mp.find(modi[i])==mp.end()||!mp[modi[i]])){
            cout<<"NO"<<endl;
            return ;
        }
        else if(org[i]!=modi[i]){
            mp[modi[i]]--;
        }
    }
    if(ok) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
}
int main()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
        int t;
        cin>>t;
        while(t--) solve();
        return 0;
}