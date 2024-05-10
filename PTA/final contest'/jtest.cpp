#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> PII;
int n,m;
int res,ans;

void bfs(vector<vector<char>> &g, int sx, int sy)
{
    int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
	queue<PII> Q;
    Q.push({sx,sy});

    res++;
    int ok=0;
    if(g[sx][sy]>'1') ok=1;
    g[sx][sy]='0';

    while(!Q.empty())
    {
        PII t=Q.front();Q.pop();
        for(int i=0;i<4;i++)
        {
            int x=t.first+dx[i],y=t.second+dy[i];
            if(x<1 || x>n || y<1 || y>m) continue;
            if(g[x][y]=='0') continue;
            if(g[x][y]>'1') ok=1;
            g[x][y]='0';
            Q.push({x,y});
        }
    }
    ans+=ok;
}

int main()
{
	while(cin>>n>>m){
        ans=0,res=0;
	vector<vector<char>> g(n+1,vector<char>(m+1));
	for(int i=1;i<=n;i++) 
		for(int j=1;j<=m;j++)
			cin>>g[i][j];
	
	res=ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(g[i][j]-'0')
				bfs(g,i,j);
	cout<<res<<" "<<ans<<endl;
    }
    return 0;
}
