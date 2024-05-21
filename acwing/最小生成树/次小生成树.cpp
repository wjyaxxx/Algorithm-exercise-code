#include <bits/stdc++.h>
using namespace std;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
const int N=510,M=1e4+10;
//vector<pair<int,int>> g[N];
struct node
{
    int a,b,w;
    bool flag;

    
    bool operator<(const node&t) const{
        return w<t.w;
    }
    
}ed[M];
int p[N];
int m1[N][N],m2[N][N];
int n,m,k;
int h[N], e[M], w[M], ne[M], idx;
int find(int x)
{
    if(x!=p[x]) p[x]=find(p[x]);
    return p[x];
}
void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
void dfs(int s, int u, int fa, int max1, int max2) {
    for (int i = h[u]; ~i; i = ne[i]) { // 枚举u的每一条出边
        int v = e[i];                   // v为u的对边节点
        if (v == fa) continue;          // 不走回头路
        int t1 = max1, t2 = max2;           // 必须要复制出来td1和td2,原因是此轮要分发多个子任务，此m1,m2是多个子任务共享的父亲传递过来的最大和次大值
        if (w[i] > t1)
            t2 = t1, t1 = w[i]; // 更新最大值、次大值
        else if (w[i] < t1 && w[i] > t2)
            t2 = w[i]; // 更新严格次大值
        // 记录从s出发点，到v节点，一路上的最长路径和严格次长路径
        m1[s][v] = t1, m2[s][v] = t2;
        // 生命不息，探索不止
        dfs(s, v, u, t1, t2);
    }
}






int main()
{
        cinquick();
        cin>>n>>m;
        fill(h,h+N,-1);
        int a,b,w;
        for(int i=1;i<=m;i++){
            cin>>a>>b>>w;
            
            ed[i]={a,b,w,0};

        }
        for(int i=1;i<=n;i++) p[i]=i;
        sort(ed+1,ed+m+1);
        long long sum=0;
        for(int i=1;i<=m;i++){
            int a=ed[i].a,b=ed[i].b,w=ed[i].w;
            int pa=find(a),pb=find(b);
            if(pa!=pb){
                sum+=w;
                add(a,b,w);
                add(b,a,w);
                p[pa]=pb;
                ed[i].flag=1;
            }
        }
        long long ans=1e17;
        for (int i = 1; i <= n; i++) dfs(i, i, 0, -1e18, -1e18);
        
        for(int i=1;i<=m;i++){
            if(!ed[i].flag){
                int a=ed[i].a,b=ed[i].b,w=ed[i].w;
                if(w>m1[a][b]){
                    ans=min(ans,sum-m1[a][b]+w);
                }
                else if(w>m2[a][b]){
                    ans=min(ans,sum-m2[a][b]+w);
                }
            }
        }
        cout<<ans<<endl;
        return 0;
}