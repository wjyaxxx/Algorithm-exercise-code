#include <bits/stdc++.h>

#define x first 
#define y second
using namespace std;
typedef long long LL;
bool cmp(pair<int,int> a,pair<int,int> b){
    if(a.x!=b.x)
        return a.x>b.x;
    return a.y<b.y;
}
void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<pair<int,int>> p(k);
    map<pair<int,int>,int> mp;
    for(int i=0;i<k;i++){
        cin>>p[i].first>>p[i].second;
        mp[p[i]]=i;
    }
    sort(p.begin(),p.end(),cmp);
    vector<int> ans(k);
    LL  total = 0;
    int cur = m + 1;
    int last = n;
    for(auto e: p){
        if(cur > e.y) {
            ans[mp[e]]=1;
            total += (LL)(cur - 1) * (last - e.x);//从下往上统计
            cur = e.y;
            last = e.x;
        }
    }
    total += (LL)(cur - 1) * last;
    
    cout << total << "\n";
    for(int i=0;i<k;i++) cout<<ans[i]<<' ';
    cout<<endl;
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