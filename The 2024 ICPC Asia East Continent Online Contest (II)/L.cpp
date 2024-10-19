#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using ll=long long;
void solve(){
    int n;
    cin>>n;
    //最优策略所以想让期望最小
    int down=int(sqrt(2*n));
    int up=down+1;
    double ans1=(down-1)/2.0 +(n*1.0/down);
    double ans2=(up-1)/2.0 + (n*1.0/up);
    ll y;
    if(ans1<ans2){
        y=down;
    }else{
        y=up;
    }
    ll a=(y-1)*y+2*n;
    ll b=2*y;
    ll d=__gcd(a,b);
    a/=d;
    b/=d;
    cout<<a<<' '<<b<<"\n";
}
int main()
{
    read_fast;
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}