#include <bits/stdc++.h>
using namespace std;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
int sum,n,m;
int q[25];
bool st[25],dp[30][2010];
int ans;
void fdp(){
    memset(dp,0,sizeof dp);
    for(int i=0;i<=n;i++) dp[i][0]=1;
    //本来应该是选到第i个时,能否凑出j
    /*
        dp[i][j]=dp[i-1][j]|dp[i-1][j-a[i]]
    
    */
    for(int i=1;i<=n;i++){
        for(int j=0;j<=sum;j++){
            dp[i][j]=dp[i-1][j];
            if(!st[i]&&j-q[i]>=0)//这个数没有被删
            {
            //为啥逆序？
            /*
                顺序时会将同一层的值再一次赋给j
                逆序就避免了这个问题
            
            */
                    dp[i][j]|=dp[i-1][j-q[i]];

            }
        }       
    }

    int cnt=0;
   
    for(int j=1;j<=sum;j++)
        if(dp[n][j]) cnt++;

    ans=max(ans,cnt);
    return; 
}
void dfs(int u,int x)
{
    //剪枝
    if((n-x+1)+u<m) return;
    if(u==m){
        fdp();
        return ;
    }
    //选数
    for(int i=x;i<=n;i++){
        if(!st[i]){
            st[i]=true;
            dfs(u+1,i+1);
            st[i]=false;
        }
    }
}
   
int main()
{
        cinquick();
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>q[i];
            sum+=q[i];
        }
        dfs(0,1);
        cout<<ans<<endl;
        return 0;
}