#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int q[N], ne[N], e[N], h[N], idx;
int m[N], d[N];
int n, k;
void cinquick()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
bool topsort()
{
    int hh = 0, tt = -1;

    for (int i = 1; i <= n; i++)
        if (!d[i])
            q[++tt] = i;

    while (hh <= tt)
    {
        int t = q[hh++];
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (--d[j] == 0)
            {
                q[++tt] = j;
            }
        }
    }
    return  tt == n - 1;
}
void solve()
{

    cin >> n >> k;
    idx = 0;
    fill(h, h + n + 1, -1);
    fill(m, m + n + 1, 0);
    fill(ne, ne + n + 1, 0);
    fill(e, e + n + 1, 0);
    fill(q, q + n + 1, 0);
    fill(d, d + n + 1, 0);

    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> m[j];
        }

        for (int j = 2; j < n; j++)
        {
            add(m[j], m[j + 1]);
            d[m[j + 1]]++;
        }
    }
    if (k == 1) {
        cout << "YES" << endl;
        return;
    }
    if (topsort())
    {
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
}
int main()
{
    cinquick();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}