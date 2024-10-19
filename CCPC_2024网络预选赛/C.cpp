#include <bits/stdc++.h>
using namespace std;
#define read_fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> vis(n + 1); // 标记是否被标记过
    vector<int> num(n + 1);
    vector<vector<int>> g(n + 1);

    int x;
    for (int i = 1; i <= m; i++) {
        cin >> x;
        vis[x] = 1;
    }
    int u, v;
    for (int i = 1; i <= n - 1; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans = 0;

    // 修改后的 lambda 表达式，明确指定参数类型和递归终止条件
    auto dfs = [&vis, &num, &g, &ans](const auto& self, int u, int f) -> int {
        int sz = 0;
        for (const auto& v : g[u]) {
            if (v == f) continue;
            num[v] = self(self, v, u);
        }

        for (const auto& v : g[u]) {
            if (v == f) continue;
            if (!vis[u] && vis[v] && num[v]) {
                vis[u] = 1;
            }
        }

        for (const auto& v : g[u]) {
            if (v == f) continue;
            sz += (vis[v]? 0 : num[v]);
        }

        if (!vis[u]) {
            sz++;
            return sz;
        }

        ans += (sz + 1) / 2;
        return (sz & 1);
    };

    int sz = dfs(dfs, 1, -1);
    if (!vis[1]) {
        ans += (sz + 1) / 2;
    }

    cout << ans << "\n";
}

int main() {
    read_fast;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}