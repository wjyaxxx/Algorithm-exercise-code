#include <bits/stdc++.h>
using namespace std;
const int N=100010;
typedef long long LL;
LL  q[N];
int p[N],vis[N];
int k;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
void s(int n)
{
    for(int i=2;i<=n;i++)
    {
        if(vis[i]==0)//i是素数，则存起来
            p[k++]=i;
        for(int j=0;j<k;j++)//进行倍增，用i去乘以i之前(包括i)的素数
        {
            if(i*p[j]>n)//倍增结果超出范围，退出
                break;

            vis[ i*p[j] ]=1;//将倍增结果进行标记

            if(i%p[j]==0)//i是前面某个素数的倍数时，也需要退出
                break;
        }
    }
}
int main()
{
        cinquick();
        int n;
        cin>>n;
         for(int i=1;i<=n;i++){
             cin>>q[i];
            q[i]+=q[i-1];//前缀和
        
         }
        s(n);
        LL ans=-1e12;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<k;j++)
            {
                int r=p[j]+i-1;
                if(r<=n){
                    LL sum=q[r]-q[i-1];
                    ans=max(ans,sum);
                }
            }
        }
        cout<<ans<<endl;
        return 0;
}