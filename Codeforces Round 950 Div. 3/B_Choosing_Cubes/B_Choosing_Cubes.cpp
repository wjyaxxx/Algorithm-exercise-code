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
    int n,f,k;
    cin>>n>>f>>k;
    vector<int> num(n+1);
    for(int i=1;i<=n;i++) cin>>num[i];
    int fav=num[f];
    sort(num.begin()+1,num.end(),greater<int>());
    //cout<<num[k]<<endl;
    if(num[k]<fav) cout<<"YES"<<endl;
    else if(num[k]>fav) cout<<"NO"<<endl;
    else{
     if(num[k+1]==fav&&k!=n) cout<<"MAYBE"<<endl;
        else cout<<"YES"<<endl;
    }
}
int main()
{
        cinquick();
        int t;
        cin>>t;
        while(t--) solve();
        return 0;
}