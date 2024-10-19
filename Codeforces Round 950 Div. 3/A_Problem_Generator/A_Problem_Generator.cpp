#include <bits/stdc++.h>
using namespace std;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
void solve()
{
    int n,m;
    cin>>n>>m;
    int cnt[7]={0};
    char x;
    for(int i=1;i<=n;i++){
        cin>>x;
        cnt[x-'A']++;
    }
    int ans=0;
    for(int i=0;i<7;i++){
        if(cnt[i]<m){
            ans+=(m-cnt[i]);
        }
    }
    cout<<ans<<endl;
}
int main()
{
        cinquick();
        int t;
        cin>>t;
        while(t--) solve();
        return 0;
}