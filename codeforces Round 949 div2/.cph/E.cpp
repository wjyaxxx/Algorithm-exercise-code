#include <bits/stdc++.h>
using namespace std;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
const int N=5*1e5+10;
vector<pair<int,int>> g[N];
int n;
struct node{
    int l,r,a,id;
    bool operator()(node t){
        return l<t.l;
    }
}q[N];
struct 
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>q[i].l>>q[i].r>>q[i].a;
        q[i].id=i;
    }
    sort(q+1,q+1+n);
    for(int i=1;i<=n;i++){
        int rv=q[i].r;
        int id=i+1;
        while(q[id].l<=rv){
            g[i].push_back({id,abs(q[id].a-q[i].a)});
        }
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