#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 55;
int n, m;
i64 G[N];
int main() {
// 	freopen("in.txt", "r", stdin);
	std::ios::sync_with_stdio(false), std::cin.tie(0);
    
	std::cin >> n >> m;
	for(int i = 1; i <= m; i ++) {
		int u, v;
		std::cin >> u >> v;
		u --, v --;
		G[u] |= 1ll << v;
		G[v] |= 1ll << u;//i64来状态压缩
	}
	int ans = 0;
	for(int i = 0; i < n; i ++) {
		std::function<void(int, int, i64)> dfs = [&] (int u, int cnt, i64 ban) {
			i64 next = G[u] & ~ban;//将之前禁用的点变成0，然后其他点为1,如果它的邻居点为禁用点(0 & 1=0)，不为邻居点(1&1=0)，其他点(0&0=0)
			ans = std::max(ans, cnt);
			while(next) {
				int i = __builtin_ctzll(next);//就最后的0的个数
				next ^= 1ll << i;//将邻接点减少1
				dfs(i, cnt + 1, ban | G[u]);//然后dfs递归
			}
		};
		dfs(i, 1, 1ll << i);//ban就是被禁掉的邻居
	}
	std::cout << ans << '\n';
	
	return 0;
}