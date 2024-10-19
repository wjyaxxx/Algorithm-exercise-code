#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using ll=long long;
const int  maxn = 2e6 + 7;
const int mod = 998244353;
ll qmi(int a, int k, int p)
{
    ll res = 1;
    while (k)
    {
        if (k & 1) res = (ll)res * a % p;
        a = (ll)a * a % p;
        k >>= 1;
    }
    return res;
}
                                                      

int main()
{
    read_fast
    ll a,b;
    cin>>a>>b;
    ll y=a+b;
    ll ans1=(a*qmi(y,mod-2,mod))%mod;
    ll ans2=(b*qmi(y,mod-2,mod))%mod;
    cout<<ans1<<' '<<ans2<<"\n";
    return 0;
}