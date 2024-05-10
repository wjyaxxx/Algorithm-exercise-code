#include <bits/stdc++.h>
using namespace std;
const int N=100010;
typedef long long LL;
LL q[N];
LL ans;
int n,k;
unordered_map<LL,int> mp;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
int main()
{
        cinquick();
        cin>>n>>k;
        for(int i=1;i<=n;i++) cin>>q[i],q[i]+=q[i-1];
        //枚举右边界
        
        mp[0]++;
        set<LL> res;
        LL now=1;
        for(int i=1;i<=60;i++){
            res.insert(now);
            now*=k;
            if(now>=1e14+5) break;
        }

        for(int i=1;i<=n;i++){
            mp[q[i]]++;
            for(set<LL>::iterator it=res.begin();it!=res.end();it++){
                LL tmp=q[i]-(*it);
                ans+=mp[tmp];
            }
        }
        cout<<ans<<endl;
        return 0;
}