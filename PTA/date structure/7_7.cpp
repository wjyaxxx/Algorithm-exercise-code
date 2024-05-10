#include <bits/stdc++.h>
using namespace std;
const int N=1010;
int st[N],q[N];
int n,m,k,tt;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
void solve()
{
    fill(st,st+m,0);
    tt=0;

    for(int i=1;i<=n;i++) cin>>q[i];

    int idx=1,cnt=1;//cnt表示要依次取出的数
    while(idx<=n&&tt<=m)
    {
        st[++tt]=q[idx++];
        while(st[tt]==cnt)
        {
            tt--;
            cnt++;
        }
    }
    if(tt) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}
int main()
{
        cinquick();
        cin>>n>>m>>k;
        while(k--) solve();
        return 0;
}