#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
double Rand() { return (double)rand() / RAND_MAX; }
struct point
{
    int x,y,w;
}p[1010];
int n;
double  ansx,ansy,dis;
double calc(double x,double y){
    double res=0;
    for(int i=1;i<=n;i++){
        double dx=p[i].x-x;
        double dy=p[i].y-y;
        res+=sqrt(dx*dx+dy*dy)*(double)p[i].w;
    }
    
    if(res<dis) ansx=x,ansy=y,dis=res;
    return res; 
}
void solve(){
    double t=100000,tk=1e-3;
    double nowx=ansx,nowy=ansy;
    while(t>tk){
        //找到下一个解
        double nxx=nowx+(Rand()*2-1)*t;
        double nxy=nowy+(Rand()*2-1)*t;
        double d=calc(nxx,nxy)-calc(nowx,nowy);
        if(exp(-d/t)>Rand()) nowx=nxx,nowy=nxy;
        t*=0.97;
    }
    //找到最优解后在附近继续找
    for(int i=1;i<=100000;i++){
        double nx=ansx+(Rand()*2-1)*tk;
        double ny=ansy+(Rand()*2-1)*tk;
        calc(nx,ny);
    }

}
int main()
{
    //read_fast
    srand(time(0));
    cin>>n;
    int x,y,w;
    for(int i=1;i<=n;i++){
        cin>>x>>y>>w;
        p[i]={x,y,w};
        ansx+=p[i].x;
        ansy+=p[i].y;
    }
    //选择初值
    ansx/=n,ansy/=n;
    
    dis=calc(ansx,ansy);
    
    //模拟退火
    solve();
    solve();
    solve();
    solve();
    solve();
    printf("%.3lf %.3lf",ansx,ansy);
    return 0;
}