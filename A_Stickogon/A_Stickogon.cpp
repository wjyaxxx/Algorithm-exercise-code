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
    int n;
    cin>>n;
    vector<int> res(n);
    for(int i=0;i<n;i++) cin>>res[i];
    sort(res.begin(),res.end());
    int ans=0;
    for(int i=0;i<n;i++){
        int j=i;
        while(j<n&&res[j]==res[i]) j++;
        int len=j-i;
        if(len>=3){
            ans+=(len/3);
        }
        i=j-1;
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