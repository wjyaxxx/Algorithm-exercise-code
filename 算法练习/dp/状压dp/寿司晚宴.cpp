#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int  n,mod;
const int N=550,M=1<<9;

int p[9]={2,3,5,7,9,11,13,17,19};
pair<int,int> a[N];
int dp[M][M],f1[M][M],f2[M][M];
int main()
{
    read_fast
    cin>>n>>mod;
    for(int i=2;i<=n;i++){
        int val=i;
        for(int j=0;j<9;j++){
            if(val%p[j]==0) a[i].second|=(1<<j);
            while(val%p[j]==0) val/=p[j];
            
        }
        a[i].first=val;
    }
    sort(a+2,a+1+n);
    //for(int i=2;i<=n;i++) cout<<a[i].first<<' '<<a[i].second<<"\n";
    //什么都不选，为什么要用状压dp，其实你会发现，就是将每个合法状态累加起来，且两个集合之间没有交集，说明可以用状压
    //如果该状压无法表示，可以试着将它分为两个状压，即分情况优化数组
    dp[0][0]=1;
    for(int i=2;i<=n;i++){
        //开头
        
        if(i==2 || a[i].first==1 || a[i].first != a[i-1].first){
            memcpy(f1,dp,sizeof dp);
            memcpy(f2,dp,sizeof dp);
        }

        //开始转移
        for(int j=M-1;j>=0;j--){
            for(int k=M-1;k>=0;k--){
                int xu=a[i].second;
                if(j&k) continue;
                if((xu & j)==0) f2[j][xu | k]=(f2[j][xu | k]+f2[j][k])%mod;
                if((xu & k)==0) f1[j | xu][k]=(f1[j | xu][k]+f1[j][k])%mod;
            }
        }

        if(i==n||a[i].first!=a[i+1].first|| a[i].first==1){
            for(int j=0;j<M;j++){
                for(int k=0;k<M;k++){
                    if(j&k) continue;
                    
                    dp[j][k]=(f1[j][k]+(f2[j][k]+mod-dp[j][k])%mod)%mod;
                    
                }
            }
            
        }
    }

    long long ans=0;
    for(int j=0;j<M;j++){
        for(int k=0;k<M;k++){
            //cout<<j<<' '<<k<<' '<<dp[j][k]<<"\n";
            if((j&k)==0&&dp[j][k]) {
                
                ans=(ans+dp[j][k])%mod;
            }
        }
    }
    cout<<ans;
    return 0;
}