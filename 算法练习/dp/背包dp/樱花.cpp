#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const int N=1010;
int dp[N*10][N];
int q[N];
int main()
{
    //read_fast
    int h1,t1,h2,t2,n;
    scanf("%d:%d %d:%d %d",&h1,&t1,&h2,&t2,&n);
    int allt=(h2-h1)*60+(t2-t1);
    vector<array<int,3>> s(n+1);
    for(int i=1;i<=n;i++){
        int c,t,p;
        scanf("%d%d%d",&t,&c,&p);
        s[i]={t,c,p};
    }

    //需要优化
    //dp[i][j]=max(dp[i-1][j],dp[i-1][j-k*s[i].t]+k*s[i].c);
    for(int i=1;i<=n;i++){
        int hh=0,tt=-1;
        int cnt=s[i][2];
        if(!s[i][2]) cnt=1e9;
        for(int j=0;j<=allt;j++){
            if(j>=q[hh]){
                while(hh <= tt  && (j-q[hh])/s[i][0]> cnt) hh++;
                
                
            }
            if(j>=q[tt])
            while(hh <= tt  && dp[i-1][q[tt]]+(j-q[tt])/s[i][0]*s[i][1] < dp[i-1][j]) tt--;
            q[++tt]=j;
            dp[i][j]=dp[i-1][q[hh]]+(j-q[hh])/s[i][0]*s[i][1];
            //cout<<j<<' '<<dp[i-1][hh]<<' '<<(j-q[hh])/s[i][0]*s[i][1]<<"\n";
            int k=hh;
            while(k<=tt) cout<<q[k++]<<" ";
            cout<<"\n";
        }
        for(int j=0;j<=allt;j++) cout<<dp[i][j]<<" \n"[j==allt];
    }
    cout<<dp[n][allt]<<"\n";
    return 0;
}