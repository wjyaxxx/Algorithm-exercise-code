#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010, MOD = 99999997;

int n;
int a[N], b[N], c[N], p[N];

void work(int a[])
{
    for (int i = 1; i <= n; i ++ ) p[i] = a[i];
    sort(p + 1, p + n + 1);
    for (int i = 1; i <= n; i ++ )
        a[i] = lower_bound(p + 1, p + n + 1, a[i]) - p;
}

int merge_sort(int l, int r)
{
    if (l >= r) return 0;
    int mid = l + r >> 1;
    int res = (merge_sort(l, mid) + merge_sort(mid + 1, r)) % MOD;
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r)
        if (b[i] <= b[j]) p[k ++ ] = b[i ++ ];
        else p[k ++ ] = b[j ++ ], res = (res + mid - i + 1) % MOD;
    while (i <= mid) p[k ++ ] = b[i ++ ];
    while (j <= r) p[k ++ ] = b[j ++ ];
    for (i = l, j = 0; i <= r; i ++, j ++ ) b[i] = p[j];
    return res;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i ++ ) scanf("%d", &b[i]);

    work(a), work(b);
    for (int i = 1; i <= n; i ++ ) c[a[i]] = b[i];
    for (int i = 1; i <= n; i ++ ) b[i] = c[i];

    for (int i = 1; i <= n; i ++ ) cout<<b[i]<<' ';
    //printf("%d\n", merge_sort(1, n));
    return 0;
}