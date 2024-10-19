#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e5+10;
int n,m;
pair<LL,LL> q[N];
LL sb,sab;
LL ans=LONG_LONG_MIN;
bool check(LL  x){
    LL res=-1;
    LL sum=0;
    for(int i=1;i<=n;i++){
        if(x-q[i].first>0){
            sum+=(LL)(x-q[i].first)*q[i].second;
            res=max(res,(LL)(x-q[i].first)*q[i].second);
        }
    }
    
    return (sum-res>m);
}
int main()
{
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        cin>>n>>m;
        int cnt=0;
        for(int i=1;i<=n;i++){
            cin>>q[i].first>>q[i].second;
            
        }
        
        LL l=1,r=2*1e9;
        while(l<r){
            LL mid=(l+r)>>1;
            if(check(mid)) r=mid;
            else l=mid+1;
        }
        
        if(check(l)) cout<<l<<endl;
        else cout<<-1<<endl;
        return 0;
}