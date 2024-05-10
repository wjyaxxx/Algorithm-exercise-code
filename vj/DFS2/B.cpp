#include <bits/stdc++.h>
using namespace std;
const int N=35;
int n,m,sum,ans;
int st[N],pre[N];//表示选到的数的状态，0表示还未选到，i表示选到了i
bool prime(int x)
{
    for(int i=2;i*i<=x;i++)
        if(x%i==0)
            return false;
    return true;
}
void dfs(int k,int x)//k表示位置，x表示可以选的数
{
    //剪枝 dfs  (k-1)//表示填了k-1个数  n-k+1 还可以最多填的数字个数  
    if((k-1)+(n-k+1)<m) return ;
    if(k>m) 
    {
        sum=0;
        for(int i=1;i<=m;i++)
        {
            sum+=pre[st[i]];
        }
       if(prime(sum) ) ans++;
        return ;
    }
    for(int i=x;i<=n;i++)
    {
        if(st[i]==0)
        {
            st[k]=i;
            dfs(k+1,i+1);
            //恢复现场
            st[k]=0;
        }
    }
    
}
int main()
{
    
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>pre[i];
    dfs(1,1);
    cout<<ans<<endl;
    return 0;
}