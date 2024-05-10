#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int sk[N],tt;
unordered_map<int,int>mp;
struct order
{
    int id,type;
}q[N];
int n,s,k;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
int main()
{
        cinquick();
        cin>>n>>s;
        for(int i=1;i<=n;i++) cin>>q[i].id;
        int cnt=1;
        for(int i=1;i<=n/s;i++)
        {
            for(int j=1;j<=s;j++){
                int x;
                cin>>x;
                sk[++tt]=x;
            }
            while(tt){
                mp[q[cnt++].id]=sk[tt];
                tt--;
            }
        }
        cin>>k;
        for(int i=1;i<=k;i++)
        {
            int idx;
            cin>>idx;
            if(mp.find(idx)==mp.end()) cout<<"Wrong Number"<<endl;
            else cout<<mp[idx]<<endl;
        }
        return 0;
}