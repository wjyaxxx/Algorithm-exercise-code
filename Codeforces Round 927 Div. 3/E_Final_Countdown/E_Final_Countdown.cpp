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
    string a;
    cin>>a;
    vector<int> num(n+1);
    for(int i=0;i<n;i++)
    {
        num[i+1]=(a[i]-'0');
        num[i+1]+=num[i];
    }
    vector<int> ans;
    int t=0;
    for(int i=n;i>=1;i--)
    {
        t+=num[i];
        ans.push_back(t%10);
        t/=10;
    }
    if(t) ans.push_back(t);
    while(ans.back()==0&&ans.size()>1) ans.pop_back();
    for(int i=ans.size()-1;i>=0;i--) cout<<ans[i];
    cout<<endl;
}
int main()
{
        cinquick();
        int t;
        cin>>t;
        while(t--) solve();
        return 0;
}