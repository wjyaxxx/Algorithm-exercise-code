#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const int N=45;
int n,m;
int dp[355][N][N][N];
int main()
{
    read_fast
  
    cin>>n>>m;
    vector<int> num(n+1);
    vector<int> cnt(5);
    for(int i=1;i<=n;i++) cin>>num[i];
    int x;
    for(int i=1;i<=m;i++){
        cin>>x;
        cnt[x]++;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        //在第i个阶段
        for(int a=0;a<=cnt[1];a++){
            for(int b=0;b<=cnt[2];b++){
                for(int c=0;c<=cnt[3];c++){
                    int d=m-a-b-c;
                    int & v=dp[i][a][b][c];
                    if(i>=1 && a>=1)v=max(v,dp[i-1][a-1][b][c]);
                    if(i>=2 && b>=1)v=max(v,dp[i-2][a][b-1][c]);
                    if(i>=3 && c>=1)v=max(v,dp[i-3][a][b][c-1]);
                    if(i>=4)         v=max(v,dp[i-4][a][b][c]);
                    v+=num[i];  
                    if(i==n) ans=max(ans,v);
                }
            }
        }
    }
    cout<<ans<<"\n";

    return 0;
}