#include <bits/stdc++.h>
using namespace std;
const int N=3*1e3+10;
int q[N][N];
char g[N][N];
int n,m;
int main()
{
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>m;
        char c;
        int x,y;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
                    cin>>g[i][j];
                    if(g[i][j]=='#') q[i][j]=1;
                    if(g[i][j]=='S') x=i,y=j;
               }
        for(int j=1;j<=m;j++)
            for(int i=0;i<=n;i++){
                q[i][j]+=q[i-1][j];
            }
        
        int y1=y,y2=y;
        while(g[x][y1]=='.'||g[x][y1]=='S'&&y1) y1--;//上或者下边界左端点
        while(g[x][y2]=='.'||g[x][y2]=='S'&&y2<=m) y2++;
        y1++;
        y2--;
        bool ok=false;
        //枚举上下边界
        for(int i=1;i<=n;i++){
            if(i==x) continue;
            int y3=y,y4=y;
            while(g[i][y3]=='.'&&y3) y3--;//上或者下边界左端点
            while(g[i][y4]=='.'&&y4<=m) y4++;
            y3++;
            y4--;
            int lmax=min(y3,y1),rmax=min(y2,y4);
            
            for(int l=lmax;l<=rmax;l++)
                for(int r=l+1;r<=rmax;r++){
                    if(i>x){
                //则为下边界
                    if(q[i][l]-q[x-1][l]==0&&q[i][r]-q[x-1][r]==0){
                        ok=true;
                        break;
                    }

                }
                else{
                    if(q[x][l]-q[i-1][l]==0&&q[x][r]-q[i-1][r]==0){
                        ok=true;
                        break;
                    }
                }
            }
        }
        if(ok) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
        return 0;
}