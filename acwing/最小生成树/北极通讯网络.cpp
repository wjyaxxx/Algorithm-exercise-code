#include <bits/stdc++.h>
using namespace std;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
/*
    
    本题可以抽象成
    假设这个卫星的辐射半径为固定值d
    在拥有卫星的每个联通块内半径都小于d
    每两个联通块之间的半径都将大于d

    本题就可以等价于
    我们需要找到一个最小的d值,使得在删去权值大于d的所有边后,
    剩下的联通块个数不超过k.

    所以采用kruskal算法

*/
const int N=510,M=N*N;
struct node
{
    int a,b;
    double w;
    bool operator<(const node&t) const{
        return w<t.w;
    }
}e[M];
int  cnt;
int p[N];
pair<int,int> pon[N]; 
int n,k;
double get_dis(int i,int j)
{
    int dx=abs(pon[i].first-pon[j].first),dy=abs(pon[i].second-pon[j].second);
    return sqrt(dx*dx+dy*dy);
}
int find(int x)
{
    if(x!=p[x]) p[x]=find(p[x]);
    return p[x];
}
int main()
{
        //cinquick();
        cin>>n>>k;
        for(int i=1;i<=n;i++) cin>>pon[i].first>>pon[i].second;

        for(int i=1;i<=n;i++)
            for(int j=1;j<i;j++)
                e[cnt++]={i,j,get_dis(i,j)};

        //kruskal
        sort(e,e+cnt);
        for(int i=1;i<=n;i++) p[i]=i;
        int res=n;
        double ans=0;
        for(int i=0;i<cnt;i++){
            if(res<=k) break;
            int a=e[i].a,b=e[i].b;
            double w=e[i].w;
            
            int pa=find(a),pb=find(b);
            if(pa!=pb){
                p[pa]=pb;
                res--;
                ans=w;
            }
        }

        printf("%.2lf",ans);
        return 0;
}