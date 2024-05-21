#include <bits/stdc++.h>
using namespace std;
/*
    由完全图的特性可以知道,在两个没有联通的点之间需要加上一条边

    最开始时候可以将每个点看成是一个联通块，在去做联通块的连接时(kruskal算法)，在连接两个联通块之间，我们去找到各联通块之间的两两之间的点
    除去将这两个联通块连接起来的那个边之外，在形成完全图时，还需要在加上两两所形成的边
    在合并两个联通块的时候ans+=(联通块1的点数*联通块2的点数-1)*各自的权重

    问题就是如何求该权重呢？
    假设连接两个连通块的权重为W
    1.若新加上的权重>W 则该最小生成树就改变为新加的那个边
    2.若相等，则最小生成树也可以通过新加入的那条边
    所以各自的权重>w
    
    那能否取成w+1呢？
    当取成w+1时，在求解最小生成树的时候，该边就一定不是最小生成树的边，假设如果是，那么将该边替换为连接两个点的情况下比他更小的权重的边
    则最小生成树改变

    所以答案为ans+=(联通块1的点数*联通块2的点数-1)*(w+1)
*/
const int N=6100;
int p[N],size[N];
struct  node
{
    int a,b,w;
    bool operator<(const  node &t) const{
        return w<t.w;
    }
}edge[N];
int n;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
int find(int x)
{
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) p[i]=i,size[i]=1;

    for(int i=1;i<n;i++){
        cin>>edge[i].a>>edge[i].b>>edge[i].w;
    }

    sort(edge+1,edge+n);
    int ans=0;
    for(int i=1;i<n;i++){
        int a=edge[i].a,b=edge[i].b,w=edge[i].w;
        int pa=find(a),pb=find(b);
        if(pa!=pb){
            ans+=(size[pa]*size[pb]-1)*(w+1);
            size[pb]+=size[pa];
            p[pa]=pb;
        }
    }
    cout<<ans<<endl;
}
int main()
{
        cinquick();
        int t;
        cin>>t;
        while(t--) solve();
        return 0;
}