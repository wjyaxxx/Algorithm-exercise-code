#include <bits/stdc++.h>
 
using i64 = long long;
 
std::string T = "EWNS";
 
void solve() {
    int n;
    std::cin >> n;
    
    std::string s;
    std::cin >> s;
    
    std::vector<int> vec[4];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < n; j++) {
            if (s[j] == T[i]) {
                vec[i].push_back(j);
            }
        }
    }
    if ((vec[0].size() + vec[1].size()) % 2 || (vec[2].size() + vec[3].size()) % 2) {
        std::cout << "NO\n";
        return;
    }
    
    std::string ans(n, 'R');
    for (int i = 0; i < 4; i += 2) {
        if (vec[i].size() < vec[i + 1].size()) {
            std::swap(vec[i], vec[i + 1]);
        }
        for (int j = 0; j < vec[i].size() + vec[i + 1].size(); j++) {
            int t = (j % 2)  ^ (i==0) ^(j >= vec[i].size());
            int p = j < vec[i].size() ? vec[i][j] : vec[i + 1][j - vec[i].size()];
            if (t) {
                ans[p] = 'H';
            }
        }
    }
    int cnt = std::count(ans.begin(), ans.end(), 'R');
    if (cnt == 0 || cnt == n) {
        std::cout << "NO\n";
        return;
    }
    std::cout << ans << "\n";
}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}