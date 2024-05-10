#include <bits/stdc++.h>
using namespace std;
const int  maxn = 2e6 + 7;
typedef long long LL;
LL fact[maxn], infact[maxn];
const int mod = 998244353;

int qmi(int a, int k, int p)    // 快速幂模板
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

void get_invfact()
{
    // 预处理阶乘的余数和阶乘逆元的余数
    fact[0] = infact[0] = 1;
    for (int i = 1; i < maxn; i++)
    {
        fact[i] = (LL)fact[i - 1] * i % mod;
        infact[i] = (LL)infact[i - 1] * qmi(i, mod - 2, mod) % mod;
    }
}

LL C(LL a, LL b)
{
    if (a < b) return 0;
    return ((fact[a] * infact[a - b]) % mod * infact[b]) % mod;
}
void cinquick()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
void solve()
{
    LL a, b, c, d;
    cin >> a >> b >> c >> d;
    if (abs(a - b) >= 2)
    {
        cout << 0 << endl;
    }
    else if (abs(a - b) == 1)
    {
        LL x = max(a, b);
        LL ans = (C(x + c - 1, x - 1) * C(x + d - 1, x - 1)) % mod;
        cout<<ans<<endl;
    }
    else {
        if (a == 0 && b == 0) {
            if (c != 0 && d != 0) cout << 0 << endl;
            else cout << 1 << endl;
            return ;
        }

        LL ans = 0;
        ans += (C(a + c - 1, a - 1) * C(a + d, a)) % mod;
        ans += (C(a + d - 1, a - 1) * C(a + c, a)) % mod;
        cout << ans % mod << endl;
    }
}
int main()
{
    cinquick();
    get_invfact();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}