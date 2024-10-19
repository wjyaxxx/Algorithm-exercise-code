#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
using namespace std;
int n,m,num;
bool vis[5005][5005];//用数组来记录点的存在，我真麻了....
struct node{
    int x;int y;
}p[5005];
int cmp(node a,node b)
{
    if (a.y==b.y) return a.x<b.x;
    return a.y<b.y;
}
int main()
{
    scanf("%d%d",&n,&m);
    scanf("%d",&num);
    for (int i=1;i<=num;i++)
    {
        scanf("%d%d",&p[i].x,&p[i].y);
        vis[p[i].x][p[i].y]=1;
    }
    sort(p+1,p+1+num,cmp);
    int ans=0;
    for (int i=1;i<=num;i++)
    for (int j=i+1;j<=num;j++)
    {
        int dx=p[j].x-p[i].x;
        int dy=p[j].y-p[i].y;
        if (p[i].x-dx>0&&p[i].x-dx<=n&&p[i].y-dy>0&&p[i].y-dy<=m)
        continue;//这个点不在稻田中,剪枝
        int cnt=2;
        int tmpx=p[j].x+dx;
        int tmpy=p[j].y+dy;
        while(tmpx<=n&&tmpx>=1&&tmpy>=1&&tmpy<=m)
        {
            if (vis[tmpx][tmpy])    cnt++;
            else {//剪枝，没必要在进行下去
                cnt=0;
                break;}//必须连续,且要跳出田野
            tmpx+=dx;
            tmpy+=dy;
        }
        if (cnt>=3) ans=max(ans,cnt); 
    }
    printf("%d\n",ans);
}