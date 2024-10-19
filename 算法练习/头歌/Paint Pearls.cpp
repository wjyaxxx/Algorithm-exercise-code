#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int n;
//双向链表加速
const int N=5*1e4+10;
int dp[N],pre[N],nxt[N],a[N];
unordered_map<int,int> mp;
//由样例的局部解发现以颜色为状态转移是最好的
int main()
{
    read_fast
    while(cin>>n){
        
        for(int i=1;i<=n;i++){
            cin>>a[i];
            pre[i]=i-1;
            nxt[i]=i+1;
        }
        memset(dp,0x3f,sizeof dp);
        mp.clear();
        dp[0]=0;
        pre[0]=-1;
        for(int i=1;i<=n;i++){
            if(!mp.count(a[i])) mp[a[i]]=i;
            else{
                //将它的那个链表删除
                int id=mp[a[i]];
                nxt[pre[id]]=nxt[id];
                pre[nxt[id]]=pre[id];
                mp[a[i]]=i;
            }
            int cnt=0;
            for(int j=pre[i];j!=-1;j=pre[j]){
                cnt++;
                dp[i]=min(dp[i],dp[j]+cnt*cnt);
                if(cnt*cnt>i) break;
                /*
                在DP过程中，以此为另一个剪枝优化：
                设当前已经用了cnt种颜色，当前计算dp[i]；如果i>cnt2，则停止DP过程。

                
                */
            }
        }
        cout<<dp[n]<<"\n";
    }
    return 0;
}