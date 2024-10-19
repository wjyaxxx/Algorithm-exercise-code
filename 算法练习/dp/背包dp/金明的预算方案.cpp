#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int dp[65][32005];
vector<int> g[65];
int main()
{
    read_fast
    int n,m;
    cin>>n>>m;
    int v,w,p;
    vector<array<int,3>> ord(m+1);
    for(int i=1;i<=m;i++){
        cin>>v>>w>>p;
        ord[i]={v,w,p};
        if(p){
            g[p].push_back(i);
        }
    }
    //开始转移
    for(int i=1;i<=m;i++){
        
            
            for(int j=0;j<=n;j++){
                // 说明为件
                // 不选
                dp[i][j]=dp[i-1][j];
                 if(!ord[i][2]){
                        //选自己
                    int&v = dp[i][j];
                    if(j>=ord[i][0]) v=max(v,dp[i-1][j-ord[i][0]]+ord[i][1]*ord[i][0]);
                    //选儿子
                    int z=ord[i][0],sum=ord[i][1]*ord[i][0];
                    int cz=z,cs=sum;
                    for(auto x:g[i]){
                        z+=ord[x][0];
                        sum+=ord[x][1]*ord[x][0];
                        if(j>=cz+ord[x][0])
                        v=max(v,dp[i-1][j-cz-ord[x][0]]+ord[x][1]*ord[x][0]+cs);
                    }
                    if(j>=z)
                        v=max(v,dp[i-1][j-z]+sum);  
                 }
            //cout<<v<<' ';
        }
             //cout<<"\n";        
    
    }
    cout<<dp[m][n]<<"\n";
    return 0;
}
