#include <bits/stdc++.h>
using namespace std;
int arr[110][110];//这里用int还是char取决于数据给得是含空格的还是不含空格的
/*
    吐槽一句，谁家做题连数据样例就画个图啊
*/
int n,m;

int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};//前后左右四个偏移量
void dfs(int x,int y)
{
    if(arr[x][y]==0)//如果是陆地返回
        return ;

    if(arr[x][y]==-1) //如果被搜过返回
        return ;

    if((x<1||x>n||y<1||y>m))//越界返回
        return ;

    arr[x][y]=-1;//表示已经被搜过
    for(int i=0;i<4;i++){
        dfs(x+dx[i],y+dy[i]);//向其他地方搜
    }
}
int main()
{
        cin>>n>>m;//岛屿的规模
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>arr[i][j];

        int cnt=0;//岛屿的数量
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(arr[i][j]==1){
                    cnt++;
                    dfs(i,j);
                }
        
        cout<<cnt<<endl;
        return 0;
}