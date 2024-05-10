#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,k,p;
const int mod=1e9+7;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
int qmi(int a, int k, int p)
{
    int res = 1;
    while (k)
    {
        if (k & 1) res = (LL)res * a % p;
        a = (LL)a * a % p;
        k >>= 1;
    }
    return res;
}
LL inv(int x)
{
    return qmi(x,mod-2,mod);
}
int main()
{
        cinquick();
        cin>>n>>k>>p;
        if(k!=1)
        {
            LL ni=inv(k-1);
            LL ans=(((k+p-1)*((qmi(k,n,mod)-1)+mod)%mod*ni)%mod*ni)%mod-(p*inv(k-1)%mod*n)%mod;
            cout<<ans<<endl;
        }
        else
        {
            LL ans=(n%mod+(((n-1)%mod*n%mod)%mod*p%mod)%mod/2)%mod;
            cout<<ans<<endl;
        }
        return 0;
}