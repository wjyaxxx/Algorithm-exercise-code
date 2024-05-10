#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct stu{
    int v,pta;
}s[N];
int n,m,k,cnt,ans;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
bool cmp(stu a,stu b)
{
    if(a.v!=b.v) return a.v>b.v;
    return a.pta>b.pta;
}
int main()
{
        cinquick();
        cin>>n>>m>>k;
        for(int i=1;i<=n;i++)
        {
            int v,pta;
            cin>>v>>pta;
            if(v>=175) s[cnt++]={v,pta};
        }
        unordered_map<int,int> mp;
        sort(s,s+cnt,cmp);
        for(int i=0;i<cnt;i++)
        {
            
            if(s[i].pta>=k) ans++;
            else{
                mp[s[i].v]++;
            }
        }
        
        for(auto x:mp)
        {
            if(x.second<=m) ans+=x.second;
            else ans+=m;
        }
        cout<<ans<<endl;
        return 0;
}