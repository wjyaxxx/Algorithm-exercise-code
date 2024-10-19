#include<bits/stdc++.h>
using namespace std;
#define re register
#define maxn 100010
#define inf 0x7f7f7f7f
#define int long long
#define Orz cout<<"stO %王队% Orz"<'\n';
int n,q;
struct node
{
	int d,c;
}a[maxn];
int s[maxn],size;
int f[maxn][25],u[maxn][25];
inline int read(){
    int x=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
    while (ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0'; ch=getchar();}
    return x*f;
}
signed main()
{
		
	cin>>n>>q;
	for(re int i=1;i<=n;++i)
		a[i].d=read(),a[i].c=read();//读入数据
	for(re int i=n;i>=1;--i)
	{
		while(size&&a[s[size]].d<=a[i].d)	size--;
		f[i][0]=s[size];
		s[++size]=i;
	}	//单调栈

    
	for(re int i=1;i<=23;++i)
		for(re int j=1;j<=n;++j)
			f[j][i]=f[f[j][i-1]][i-1];
	for(re int i=1;i<=n;++i)	
		u[i][0]=a[f[i][0]].c;
	for(re int i=1;i<=n;++i)
		if(f[i][0]==0)	
			u[i][0]=inf; //初始化u数组 
	for(re int i=1;i<=23;++i)
		for(re int j=1;j<=n;++j)
			u[j][i]=u[j][i-1]+u[f[j][i-1]][i-1];//倍增
	while(q--)
	{
		int r=read(),v=read();
		if(v<=a[r].c)
		{
			cout<<r<<'\n';
			continue;
		}
		v-=a[r].c;
		for(re int i=23;i>=0;--i){
			if(u[r][i]<=v)	
				v-=u[r][i],r=f[r][i];
        }
		if(v)	r=f[r][0];
		cout<<r<<'\n';
	}//回答询问
	return 0;
}


