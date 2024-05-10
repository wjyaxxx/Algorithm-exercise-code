#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
const int P=131;
const int N=1010;
ULL h[N],p[N];
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
ULL get(int l, int r)
{
    return h[r] - h[l - 1] * p[r - l + 1];
}
int main()
{
    cinquick();
    int ans=0,cnt=0;
	string a;
	getline(cin,a);
	char s[N];
	int len=a.size();
	s[++cnt]='#';
	for(int i=0;i<len;i++) 
	  s[++cnt]=a[i],s[++cnt]='#';
	for(int i=1;i<=cnt;i++){
		int l=i-1,r=i+1,sum=0;
		while(l>0&&r<=cnt&&s[l]==s[r]) 
		  l--,r++,sum++;
		ans=max(ans,sum); 
	}
	cout<<ans;
    
    return 0;
}