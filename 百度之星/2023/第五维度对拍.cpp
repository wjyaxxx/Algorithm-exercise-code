#include<bits/stdc++.h> 

using namespace std;

typedef long long ll;

const int N = 100010;
int n, m;
int s[N], v[N];

int check(ll t) {
    // 如果能让人类理解第五维度，则返回1；否则返回0 
    ll sum = 0, _max = -1;
    for(int i = 0; i < n; i ++ ) {
        ll cur = max((t - s[i]) * v[i], 0ll); // s * v最大可能为10^12，所以这里要用long long
        _max = max(_max, cur);
        sum += cur;
    } 
    return sum - _max > m;
}

int main( )
{
    
    scanf("%d%d", &n ,&m);
    for(int i = 0; i < n; i ++ ) scanf("%d%d", &s[i], &v[i]);
    ll l = 1, r = 2e9;

    ll ans = -1;
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid)) { 
            r = mid;
            ans = mid;
        }
        else l = mid + 1;
    }
    
    cout << ans << endl;

    return 0;
}
