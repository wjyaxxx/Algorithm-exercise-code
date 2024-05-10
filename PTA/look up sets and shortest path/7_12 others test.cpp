#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl "\n"
#define int long long
#define fi first
#define se second
const int N = 1e5+10, INF = 0x3f3f3f3f;

void solve() {
	int ans=0,cnt=0;
	string a;
	getline(cin,a);
	char s[N];
	int len=a.size();
	s[++cnt]='#';
	for(int i=0;i<len;i++) //将每个字符隔开，变为奇数串 
	  s[++cnt]=a[i],s[++cnt]='#';
//	printf("%s\n",s+1);
	for(int i=1;i<=cnt;i++){
		int l=i-1,r=i+1,sum=0;
		while(l>0&&r<=cnt&&s[l]==s[r]) //向两边扩展 
		  l--,r++,sum++;
		ans=max(ans,sum); //取较大值 
	}
	cout<<ans;
}

signed main() {
//	IOS;
	int T=1;  
//	cin>>T;
	while(T--) {
		solve();
	}
	return 0;    
}


