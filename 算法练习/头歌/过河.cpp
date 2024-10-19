#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int len,s,t,m;
const int N=105,M=1e7;
int a[N],is[M],dp[M];
int main()
{
    read_fast
    cin>>len>>s>>t>>m;
    for(int i=1;i<=m;i++) cin>>a[i];
    if(s==t){
        int ans=0;
        for(int i=1;i<=m;i++) 
            if(a[i]%s==0) ans++;
        cout<<ans<<"\n";
    }else{
        //将石子平移 用数论知识可以知道大于 T*(T-1)的数一定可以到达，只要大于这个就将这个位置平移到T*（T-1）以内
        int dislen=t*(t-1),movelen=0;
        sort(a+1,a+1+m);
        a[0]=0;
        a[m+1]=len;
        for(int i=1;i<=m+1;i++){
            int cha=a[i]-a[i-1]-movelen;//原来的相邻的差值
            if(cha > dislen)
                movelen+=(cha - dislen);
            a[i]-=movelen;
            if(i!=m+1) is[a[i]]=1;
        }
        for(int i=1;i<=m;i++) cerr<<a[i]<<' ';
        memset(dp,0x3f,sizeof dp);
        dp[0]=0;
        //可以用dp求解了
        int ed=a[m+1]+t-1;
        for(int i=s;i<=ed;i++){
            for(int j=s;j<=t;j++){
                if(i-j>=0)
                    dp[i]=min(dp[i],dp[i-j]+is[i]);
            }
        }
        
        int ans=INT_MAX;
        for(int i=a[m+1];i<=ed;i++) ans=min(ans,dp[i]);
        cout<<ans<<"\n";
    }

    return 0;
}