#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=55;
LL dp[N*N][N][N];//走了i步到达j,k的最大值
LL a[N][N];
int n,m,K;
bool check(int &i,int &j){
    return (i<=n&&i>=0&&j<=m&&j>=1);
}
int dx[5]={0,0,1,-1,0},dy[5]={1,-1,0,0,0};
int main()
{
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>m>>K;
        int si,sj;
        cin>>si>>sj;
        int maxi,maxj,maxv=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
                if(maxv<a[i][j]){
                    maxv=a[i][j];
                    maxi=i;
                    maxj=j;
                }
            }
        //dp[0][si][sj]=a[si][sj];
        memset(dp,-0x3f,sizeof dp);
        dp[0][si][sj]=0;
        for(int i=1;i<=n*m;i++)
            for(int j=1;j<=n;j++)
                for(int k=1;k<=m;k++){
                    for(int d=0;d<5;d++){
                       int j_=j+dx[d],k_=k+dy[d];
                            if(dp[i-1][j_][k_]>-0x3f3f3f3f/2){
                                //if(i==1&&j==2&&k==3) cout<<j_<<' '<<k_<<endl;
                                dp[i][j][k]=max(dp[i][j][k],dp[i-1][j_][k_]+a[j][k]);
                        }     
                    }
                }
        LL ans=0;
        for(int i=0;i<=n*m;i++){
            for(int j=1;j<=n;j++){
                for(int k=1;k<=m;k++){
                    if(K-i>=0){
                        LL res=dp[i][j][k]+(K-i)*a[j][k];
                        //if(res==14) cout<<i<<' '<<j<<' '<<k<<"\n";
                        ans=max(ans,res);
                    }
                    
                }
            }
        }
        cout<<ans<<"\n";
        return 0;
}