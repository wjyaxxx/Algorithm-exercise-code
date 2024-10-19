#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const int N=75;
struct node{
    int h,t;
    bool operator<(node a){
        return h>a.h;
    }
}book[N];
int ans;
int n;
int cnt;
int sum[N],dp[2][2105][2105];//压缩状态
//dp[i][j]表示第二层具有的厚度，和第一层具有的厚度
//会发现我们不关心这层的每一本书的高度，但一定关心每层的厚度
//但是这题会发现具有很明显的dp性质

int main()
{
    read_fast
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        int h,t;
        int tmp=0;
        for(int i=1;i<=n;i++){
            cin>>h>>t;
            book[i]={h,t};
            tmp+=t;
        }
        sort(book+1,book+1+n);
        for(int i=1;i<=n;i++) sum[i]=sum[i-1]+book[i].t;
        memset(dp,0x3f,sizeof dp);
        dp[0][0][0]=0;
        int now=0,last=1;
        
        //阶段
        for(int i=2;i<=n;i++){
            now^=1,last^=1;          
            memset(dp[now],0x3f,sizeof(dp[now]));
            for(int j=sum[i];j>=0;j--){
                for(int k=sum[i];k>=0;k--){
                    dp[now][j][k]=min(dp[now][j][k],dp[last][j][k]);//复制上一层，将他放在第一层的位置
                    if(j>book[i].t)  dp[now][j][k]=min(dp[now][j][k],dp[last][j-book[i].t][k]);
                    if(j==book[i].t)  dp[now][j][k]=min(dp[now][j][k],dp[last][0][k]+book[i].h);
                    if(k>book[i].t) dp[now][j][k]=min(dp[now][j][k],dp[last][j][k-book[i].t]);
                    if(k==book[i].t) dp[now][j][k]=min(dp[now][j][k],dp[last][j][0]+book[i].h); 
                }
            }
            
        }
        
        ans=0x3f3f3f3f;
         for(int i=1;i<=sum[n];i++)
	    	for(int j=1;j<=sum[n];j++){
	    		if(dp[now][i][j]<=600)
                    //cout<<i<<' '<<j<<' '<<dp[now][i][j]<<"\n";
				  ans = min(ans, (dp[now][i][j] + book[1].h) * max(j, max(i, sum[n]-j-i)));
                //if((dp[i][j]+book[1].h)*max(max(i,j),t-i-j)==12300) cout<<i<<' '<<j<<' '<<dp[i][j]<<"\n";   
            }
    
        cout<<ans<<"\n";
    }
    return 0;
}