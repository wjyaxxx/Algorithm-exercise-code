#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const int N=105;
int g[N][N];
int p[N];
int n,q;
int find(int x){
    if(x!=p[x]) p[x]=find(p[x]);
    return p[x];
}
struct node{
    int u,v,w; 
    bool operator<(node s){
        return w<s.w;
    }
}e[N*100];
int m;
int main()
{
    read_fast
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>g[i][j];

    //初始化并查集
    for(int i=1;i<=n;i++) p[i]=i;
    cin>>q;
    int a,b;
    while(q--){
        cin>>a>>b;
        int fa=find(a),fb=find(b);
        if(fa!=fb){
            p[fa]=fb;
        }
    }
    //将边加入
    for(int i=1;i<=n;i++)
        for(int j=1;j<i;j++){
            if(find(i)!=find(j)){
                e[++m]={i,j,g[i][j]};
            }
        }
    sort(e+1,e+1+m);
    int ans=0;
    for(int i=1;i<=m;i++){
        int u=e[i].u,v=e[i].v,w=e[i].w;
        if(find(u)!=find(v)){
            p[find(u)]=find(v);
            ans+=w;
        }
    }
    cout<<ans<<"\n";
    return 0;
}