#include <iostream>
#include <cstdio>

#include <algorithm>
using namespace std;
const int N=10010,M=500010;
typedef long long LL;
struct node
{
    int a,b;
    LL w;
    bool operator<(const node &t) const{
        return w<t.w;
    }
}e[M];
int p[N],sz[N];
int n,m,q;

int find(int x)
{
    if(x!=p[x]) p[x]=find(p[x]);
    return p[x];
}
//离线查询将它一一对应
struct query
{
    LL w;
    int  id;
    bool operator<(const query&t) const{
        return w<t.w;
    }
}res[100010];
int mp[100010];
int ans[100010];
int main()
{
        
        while(scanf("%d %d",&n,&m)!=EOF){
            
            for(int i=1;i<=m;i++){
               scanf("%d %d %lld",&e[i].a,&e[i].b,&e[i].w);
            }
            sort(e+1,e+1+m);
            scanf("%d",&q);
            for(int i=1;i<=q;i++){
                scanf("%lld",&res[i].w);
                res[i].id=i;
            }
            sort(res+1,res+q+1);
            for(int i=1;i<=q;i++){
                mp[res[i].id]=i;
            }
            //将w一一对应起来
            for(int i=0;i<n;i++) p[i]=i,sz[i]=1;

            int j=1,cnt=n*(n-1);
            for(int i=1;i<=m;i++){
                int a=e[i].a,b=e[i].b,w=e[i].w;
                while(res[j].w<=w&&j<=q) ans[j++]=cnt;
                int pa=find(a),pb=find(b);
                if(pa!=pb){
                    cnt-=sz[pa]*sz[pb]*2;
                    sz[pb]+=sz[pa];
                    p[pa]=pb;
                }
            }
            while(j<=q) ans[j++]=cnt;
            for(int i=1;i<=q;i++) printf("%d\n",ans[mp[i]]);
        }
        return 0;
}