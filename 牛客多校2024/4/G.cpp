#include <bits/stdc++.h>
using namespace std;
#define int long long
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int sr(int x){
     return x*x;
}
void solve(){
    int  x1,y1,x2,y2;
    scanf("%lld %lld %lld %lld",&x1,&y1,&x2,&y2);
//     printf("%lld\n",x1);
    int a=sr(x1+x2)+sr(y1-y2);
    int b=sr(x1-x2)+sr(y1+y2);
    int ans=min(a,b);
     printf("%.9lf\n",sqrt(ans));
    
}
signed main()
{
    //read_fast;
    int t;
    scanf("%lld",&t);
    while(t--) solve();
    return 0;
}