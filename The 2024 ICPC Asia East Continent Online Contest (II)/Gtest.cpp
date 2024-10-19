#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const int  maxn = 2e6 + 7;
typedef long long LL;
LL fact[maxn], infact[maxn];
const int mod = xxxxx;
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
int main()
{
    read_fast
    return 0;
}