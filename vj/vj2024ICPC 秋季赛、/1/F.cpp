#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
typedef long long LL;
LL sum(LL n)
{
    LL ans = 0;
    while(n) {
        LL x = n % 10;
        n /= 10;
        ans += ((1 + x) * x) / 2 + n * 45;
    }
    return ans;
}

int main()
{
    read_fast
    LL a,b;
    while(cin>>a>>b && a>=0){
        cout<<sum(b)-sum(a-1)<<"\n";

    }
    return 0;
}