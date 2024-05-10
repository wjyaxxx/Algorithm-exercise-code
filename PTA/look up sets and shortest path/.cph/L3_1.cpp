#include <bits/stdc++.h>
using namespace std;
const int N=1010;
int p[N],vis[N];
int n;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
int find(int x)
{
    if(x!=p[x]) p[x]=find(p[x]);
    return p[x];
}
void mg(int a,int b)
{
    p[find(a)]=find(b);
}
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
        //cinquick();

        for(int i=1;i<=N;i++) p[i]=i;
        cin>>n;
        
        for(int i=1;i<=n;i++)
        {
            int k;
            scanf("%d:",&k);
            for(int j=1;j<=k;j++)
            {
                int x;
                scanf("%d",&x);
                if(!vis[x]) vis[x]=i;//这个爱好之前没有人喜欢
                else mg(i,vis[x]);
            }
        }
        int res=0;
        vector<int> ans(n+1);
       for(int i=1;i<=n;i++)
       {
            if(find(i)==i) {res++;ans[find(i)]++;}
            else ans[find(i)]++;
       }
        cout<<res<<endl;
        sort(ans.begin(),ans.end(),cmp);

        for(int i=0;i<res;i++)
        {
            cout<<ans[i];
            if(i!=res-1) cout<<" ";
        }
        return 0;
}