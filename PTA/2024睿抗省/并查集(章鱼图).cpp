#include<iostream>
#include<queue>
#include<vector>
using namespace std;
const int N=1e5+5;
vector<int> g[N]; 
int f[N],s[N],d[N],v[N];//s表示每一个联通子图中的环的个数 
int t,n,m;
int find(int x)//求祖宗节点的模版来自y总 
{
	if(x!=f[x])
	return f[x]=find(f[x]);
	return f[x];
}
int bfs(int u,int last)//在中求两个端点的最短距离可以当作板子用 
{
	queue<int> q;
	q.push(u);
	v[u]=1;
	while(!q.empty())
	{
		int t=q.front();
		q.pop();
		for(auto j:g[t])//遍历以t为顶点的所有边 
		{  if(!v[j])
			{
			if(t==u&&j==last)
			continue;
			v[j]=1;
			d[j]=d[t]+1;
			q.push(j);
			}
		}
	}
	return d[last];
}
int main()
{
	cin>>t;
	while(t--)
	{
	cin>>n>>m;
   //初始化 
	for(int i=1;i<=n;i++)
	f[i]=i,s[i]=0,d[i]=0,v[i]=0,g[i].clear();
	//环中的两个端点 
	int l,r;
	for(int i=1;i<=m;i++)
	{
		int a,b;
		cin>>a>>b;
		//用二维vector建边  
		g[a].push_back(b);
		g[b].push_back(a);
		//保存两个点的祖先 
		int fa=find(a);
		int fb=find(b);
		//如果两个点的祖先相等再建边一定会出现一个环 
		if(fa==fb)  s[fb]++,l=a,r=b;
		else//连接两个点并把两个子图中的换的个数连接一下 
		f[fa]=fb,s[fb]+=s[fa];
	}
	int ans=0;//章鱼子图的个数 
	for(int i=1;i<=n;i++)
	{
		if(find(i)==i&&s[i]==1)//如果该点就是祖宗节点并且该子图中的子图的个数是1那么该子图就是章鱼子图 
		ans++;
	}
	if(ans!=1)//如果章鱼子图的个数不是1直接输出即可 
	cout<<"No "<<ans<<endl;
	else
	{
	 	cout<<"Yes "<<bfs(l,r)+1<<endl;
	}
	}
	return 0; 
 } 