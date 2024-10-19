#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const int N=1e5+10;
typedef long long ll;
struct node
{
    ll w,v,c;
    double avg;
}a[N];
ll s[N];
int main()
{
    read_fast
    int n;
    cin>>n;
    ll w,v,c;
    ll sum=0;
    for(int i=1;i<=n;i++){
      cin>>w>>v>>c;
      a[i]={w,v,c};
      a[i].avg=(c*1.0/w);
        sum+=v;
    }

    sort(a+1,a+1+n,[](node a,node b)->bool{
            if(a.avg!=b.avg)  return a.avg>b.avg;
            return a.w<b.w;
        });
    ll ans=0;
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i].w;
        
    }
    for(int i=1;i<=n;i++){
        ans+=a[i].c*(s[n]-s[i]);
        
    }
    cout<<sum-ans<<"\n";
    return 0;
}