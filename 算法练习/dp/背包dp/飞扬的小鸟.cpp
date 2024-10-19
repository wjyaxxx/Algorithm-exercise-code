#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int n,m,k;
const int N=1e3+5;
int up[N*10],down[N*10];
map<int,pair<int,int>> mp;
int dp[N*10][N];
bool check(int i,int x){
   if(!x) return false;
   if(mp.count(i) && (x<=mp[i].first || x>=mp[i].second)) return false;
   return true;
}
int main()
{
    //read_fast
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        cin>>up[i]>>down[i];
    }
    int x,d1,d2;
    for(int i=1;i<=k;i++){
        scanf("%d %d %d",&x,&d1,&d2);
        mp[x]={d1,d2};
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            dp[i][j]=1e9;
        }
    }
    dp[0][0]=1e9;
    for(int i=0;i<n;i++){
        for(int j=0;j<=m;j++){
                //这个位置合法
                //下降
                if(j>=down[i] && check(i+1,j-down[i]))
                dp[i+1][j-down[i]]=min(dp[i][j],dp[i+1][j-down[i]]);
                //上升
               
                    //if(i==1 && j==3) cout<<"Yes "<<up[i]<<"\n";
                    if(j+up[i]<=m){
                        if(check(i+1,j+up[i]))
                        dp[i+1][j+up[i]]=min(dp[i][j]+1,dp[i+1][j]+1);
                    }
                    else{
                    if(check(i+1,m))
                        dp[i+1][m]=min(dp[i+1][m],min(dp[i][j]+1,dp[i+1][j]+1));
                }
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++)
            cout<<dp[i][j]<<' ';
        cout<<"\n";
   }
     int ans=1e9;
   for(int i=0;i<=m;i++) ans=min(ans,dp[n][i]);
   if(ans<1e9){
        cout<<1<<"\n";
        cout<<ans<<"\n";
   }else{
        cout<<0<<"\n";
        int cnt=0;
        for(auto x:mp){
            bool ok=false;
            for(int i=0;i<=m;i++) 
             if(dp[x.first][i]<1e9) {
                cnt++;
                ok=true;
                break;
             }
             if(!ok){
                cout<<cnt<<"\n";
                return 0;
             }
        }
   }
    
    return 0;
}