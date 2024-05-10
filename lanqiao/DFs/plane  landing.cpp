#include <bits/stdc++.h>
using namespace std;
const int N=100;
struct plane{

     int t,d,l;   
}p[N];
bool st[N];
int n;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
bool dfs(int u,int last)
{
     if(u>n)   return true;

     for(int i=1;i<=n;i++)
     {
        int t1=p[i].t,d1=p[i].d,l1=p[i].l;
        if(!st[i]&&last<=t1+d1)
        {
                st[i]=true;
                if(dfs(u+1,max(last,t1)+l1)) return true;
                st[i]=false;
        }
     }
     return false;
}
void solve()
{
        
        
        cin>>n;
        fill(st,st+n+1,0);
        for(int i=1;i<=n;i++)
        {
             int t1,d1,l1;
             cin>>t1>>d1>>l1;
             p[i]={t1,d1,l1};   
        }

        if(dfs(1,0)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
}
int main()
{
        cinquick();
        int t;
        cin>>t;
        while(t--) solve();
        return 0;
}