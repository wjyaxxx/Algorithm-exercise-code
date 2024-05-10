#include <bits/stdc++.h>
using namespace std;

const int N=100010;
//store of graph:
//adjacency list 
int h[N],e[N],ne[N],idx;
// initialize(初始化)
idx=0;
memset(h,-1,sizeof h);
void add(int a,int b)
{
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}

//use dfs to traversal of tree or graph
bool st[N];//记录每个点是否被搜索过

//具体题目具体加上一个逻辑(different problem ,different logic)
void dfs(int u)
{
    st[u]=true;
    for(int i=h[u];i!=-1;i=ne[i])
    {
        int j=ne[i];
        if(!st[j]) dfs(j);
    }
    return ;
}
//use bfs to traversal of tree or graph
int q[N],hh,tt;
void bfs()
{
    hh=0,tt=-1;
    q[0]=1;//把1号点放在队列中 put first point in the queue
    st[1]=true;
    while(hh<=tt)
    {
        int tmp=q[hh++];//取出元素 take out element
        for(int i=h[tmp];i!=-1;i=ne[i])
        {
            int j=e[i];
            if(!st[j])
            {
                q[++tt]=j;//join the queue
                st[j]=true;
            }
        }

    }

}
//有向无环图被称为拓扑图   Directed acyclic graphs are called topological graph 
//可以用来检测是否有环  can be  used to detect whether there is a ring
int d[N];
bool topsort()
{
    int hh=0,tt=-1;
    for(int i=1;i<=n;i++)
        if(!d[i])
            q[++tt]=i;
    
    while(hh<=tt){
        int tmp=q[hh++];
        for(int i=h[tmp];i!=-1;i=ne[i])
        {
            int j=e[i];
            if(--d[j]==0)
            {
                q[++tt]=j;
            }
        }
    }

    return  tt==n-1;
}
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
int main()
{
        cinquick();
        return 0;
}