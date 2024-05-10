#include <bits/stdc++.h>
using namespace std;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
const int N=1e3+10;
bitset<N> book[N];
vector<int> g[100010];//用来建图
bitset<N> fil;
int n,m,q;
//将bitset 全部弄成1，方便进行操作
void init()
{
    for(int i=1;i<=m;i++) fil[i]=1;
    
}
struct node
{
    int op,x,y;
}point[100010];
int ans[100010];
int cnt;
void dfs(int u)
{
    int op=point[u].op;
    bool ok=false;
    if(op==1){
        int i=point[u].x,j=point[u].y;
        if(!book[i][j]){
            book[i][j]=1;
            cnt++;
            ok=true;
        }
    }
    else if(op==2){
        int i=point[u].x,j=point[u].y;
        if(book[i][j]){
            book[i][j]=0;
            cnt--;
            ok=true;
        }
    }
    else if(op==3){
        int i=point[u].x;
        int A=book[i].count();
        book[i]^=fil;
        cnt+=(book[i].count()-A);
    }
    //cout<<u<<' '<<cnt<<endl;
    ans[u]=cnt;
    for(auto edge:g[u]){
        dfs(edge);
    }
    //回溯
    if(op==1){
        int i=point[u].x,j=point[u].y;
        if(ok){
            book[i][j]=0;
            cnt--;

        }
    }
    else if(op==2){
        int i=point[u].x,j=point[u].y;
        if(ok){
            book[i][j]=1;
            cnt++;

        }
    }
    else if(op==3){
        int i=point[u].x;
        int A=book[i].count();
        book[i]^=fil;
        cnt+=(book[i].count()-A);
    }
}
int main()
{
        cinquick();
        cin>>n>>m>>q;
        init();
        int op;
        //初始化0的操作,因为0不能被统计
        point[0].op=-1;
        for(int id=1;id<=q;id++){
           cin>>point[id].op;
           int op=point[id].op;
            
           if(op<=3) g[id-1].push_back(id);
           else{
              cin>>point[id].x;
              g[point[id].x].push_back(id);  
           }
           if(op<=2){
            cin>>point[id].x>>point[id].y;
            //建边
           }
           else if(op==3){
                cin>>point[id].x;
           } 
        }
        dfs(0);
        for(int i=1;i<=q;i++) cout<<ans[i]<<endl;
        return 0;
}