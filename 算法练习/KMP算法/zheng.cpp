#include<bits/stdc++.h>
using namespace std;
#define rg register
#define ll long long
#define ull unsigned ll
#define inf 0x3f3f3f3f
#define djq 998244353
#define lowbit(x) (x&(-x))
inline void file(){
	freopen("baka.in","r",stdin);
	freopen("baka.out","w",stdout);
}
char buf[1<<21],*p1=buf,*p2=buf;
inline int getc(){
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;
}
inline int read(){
	rg int ret=0,f=0;char ch=getc();
    while(!isdigit(ch)){if(ch==EOF)exit(0);if(ch=='-')f=1;ch=getc();}
    while(isdigit(ch)){ret=ret*10+ch-48;ch=getc();}
    return f?-ret:ret;
}
int n,m,lim[10000005],z[10000005],f[10000005];;
char s[10000005],t[10000005];
int q[10000005],fr,re;
signed main(){
	//file();
	scanf("%d%d%s%s",&m,&n,t+1,s+1);
	z[1]=m;
	for(rg int i=2,l=0,r=0;i<=m;++i){
		if(i<=r) z[i]=min(r-i+1,z[i-l+1]);
		else z[i]=0;
		while(i+z[i]<=m&&t[1+z[i]]==t[i+z[i]]) ++z[i];
		if(r<i+z[i]-1) l=i,r=i+z[i]-1;
	}
	for(rg int i=1,l=0,r=0;i<=n;++i){
		if(i<=r) lim[i]=min(r-i+1,z[i-l+1]);
		else lim[i]=0;
		while(i+lim[i]<=n&&1+lim[i]<=m&&t[1+lim[i]]==s[i+lim[i]]) ++lim[i];
		if(r<i+lim[i]-1) l=i,r=i+lim[i]-1;
	}
    
    //用这个巧妙解决了，维护好i+lim[i]大的那一个
	for(rg int i=1,j=0;i<=n;++i) j>i+lim[i]?lim[i]=inf:j=i+lim[i];
    for(int i=1;i<=n;i++) cout<<lim[i]<<" ";
	memset(f,0x3f,sizeof(f));
	f[n+1]=0; q[fr=re=1]=n+1;
	for(rg int i=n;i>=1;--i){
		if(lim[i]==inf) continue;
		while(fr-1!=re&&q[fr]>i+lim[i]) ++fr; 
		const int j=q[fr];
		f[i]=f[j]+1;
        //if(i==102) cout<<i<<' '<<j<<' '<<lim[i]<<"\n";
		while(fr-1!=re&&f[q[re]]>=f[i]) --re;
		q[++re]=i;
	}
    for(int i=1;i<=n;i++) 
        cerr<<f[i]<<' ';
	// if(f[1]>=0x3f3f3f3f) puts("Fake");
	// else printf("%d",f[1]);
	return 0;
}