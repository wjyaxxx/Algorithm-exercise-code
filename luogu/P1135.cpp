#include <bits/stdc++.h>
using namespace std;
const int N=1000;
int n,a,b,ans;
bool st[N];
int ud[N],d[N];
queue<int> q;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
bool bfs()
{
    st[a]=true;
    q.push(a);
    while(!q.empty())
    {
        int now=q.front();
        q.pop();
        if(now==b) return true;
        int up=now+ud[now],down=now-ud[now];
        if(up<=n&&!st[up]) {st[up]=true; q.push(up);d[up]=d[now]+1;}
        if(down>=1&&!st[down]){st[down]=true ;q.push(down);d[down]=d[now]+1;}
    }
    if(q.empty()) return false ; 
}
int main()
{
        cinquick();
        
        cin>>n>>a>>b;
        for(int i=1;i<=n;i++) cin>>ud[i];
        if(bfs())
            cout<<d[b]<<endl;
        else cout<<-1<<endl; 
        return 0;
}