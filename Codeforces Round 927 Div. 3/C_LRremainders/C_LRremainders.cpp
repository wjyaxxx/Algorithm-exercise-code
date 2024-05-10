#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 
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
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];

    int l=1,r=n;
    stack<int> q;
    string s;
    cin>>s;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='L') q.push(a[l]),l++;
        else q.push(a[r]),r--;
    }
    vector<int> ans(n,0);
    ll res=1;
    r=n-1;
    while(!q.empty())
    {
        int x=q.top();
        q.pop();
        res=(res*x)%m;
        ans[r--]=res;

    }

    for(int i=0;i<n;i++) cout<<ans[i]<<' ';
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