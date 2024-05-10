#include <bits/stdc++.h>
using namespace std;
int m,n,k;
const int N=1010;
int q[N],st[N],tt;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}

int main()
{
        cinquick();
        cin>>m>>n>>k;
    while(k--)
    {
        for(int i=1;i<=n;i++) cin>>q[i];//出栈的顺序

        int idx=1,tt=0;
        fill(st,st+m,0);
        for(int i=1;i<=n;i++)
        {
            if(tt>=m) break; 
            if(!tt||q[idx]!=st[tt]) st[++tt]=i;
            while(st[tt]==q[idx]&&tt)
            {
                tt--;
                idx++;
            }
        }
        if(!tt) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

        return 0;
}