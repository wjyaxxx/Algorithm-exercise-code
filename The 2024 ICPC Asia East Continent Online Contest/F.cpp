#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const int N=1e6+10;
int stk[N];
int a[N],l[N],r[N];


void solve()
{
    int n;
    cin>>n;
    
    
    for(int i=1;i<=n;i++) cin>>a[i],r[i]=n+1,l[i]=0;

    int top=0;
    for(int i=1;i<=n;i++) {
        
		while(top && a[stk[top]]<=a[i]) {
            r[stk[top]]=i;
            top--;
        }
        stk[++top]=i;
	}
    
    top=0;
    for(int i=n;i;i--) {
		while(top && a[stk[top]]<=a[i]) {
            l[stk[top]]=i;
            top--;
        }
        stk[++top]=i;
	}
    // for(int i=1;i<=n;i++) cout<<l[i]<<" \n"[i==n];
    // for(int i=1;i<=n;i++) cout<<r[i]<<" \n"[i==n];

    long long ans=0ll;
    for(int i=1;i<=n;i++){
        if (!l[i] || a[l[i]] != a[i]) ans += r[i] - l[i] - 2;
            else ans += r[i] - i - 1;
    }
    cout<<ans<<"\n";

   
}
int main()
{
    read_fast;
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}