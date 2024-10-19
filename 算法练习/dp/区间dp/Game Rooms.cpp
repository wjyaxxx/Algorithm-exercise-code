#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

void solve(int id)
{
    int n;
    cin>>n;
    vector<array<ll,2>> a(n+1);
    for(int i=1;i<=n;i++){ 
        int x,y;
        scanf("%d %d",&x,&y);
        a[i]={x,y};
    }

    //处理一下前缀和
    vector<array<ll,2>> s1(n+1);
    vector<array<ll,2>> s2(n+1);
    
    for(int i=1;i<=n;i++){
        s1[i][0]=s1[i-1][0]+a[i][0];
        s1[i][1]=s1[i-1][1]+a[i][1];
        s2[i][0]=s2[i-1][0]+a[i][0]*i;
        s2[i][1]=s2[i-1][1]+a[i][1]*i;
    }
    
    auto cost1 =[&] (int l,int mid,int k){
        return s2[mid][k]-s2[l-1][k]-(l-1)*(s1[mid][k]-s1[l-1][k]);
    };
    auto cost2 =[&](int l,int r,int k){
        return (r+1)*(s1[r][k]-s1[l-1][k])-(s2[r][k]-s2[l-1][k]);
    };
    auto cost = [&](int l,int r,int k) -> ll{
        if(l==1 && r==n) return 1e18;
        if(l==1) return cost2(l,r,k);
        if(r==n) return cost1(l,r,k);
        int mid=(l+r)>>1;
        return cost1(l,mid,k)+cost2(mid+1,r,k);
    };

    vector<array<ll,2>> dp(n+1);
    for(int i=1;i<=n;i++){
        for(int k=0;k<2;k++){
            dp[i][k]=1e18;
            for(int j=0;j<i;j++){
                dp[i][k]=min(dp[i][k],dp[j][k^1]+cost(j+1,i,k^1));
            }
        }
    }
    //开始转移
    printf("Case #%lld: %lld\n",id, min(dp[n][0], dp[n][1]));

}
int main()
{
    //read_fast;
    int t;
    
    cin>>t;
    int ct=t;
    while(t--) solve(ct-t);
    return 0;
}