
#include <iostream>
#include <vector>
#include <map>
 
using namespace std;
 
const int maxn = 2e5 + 5;
 
map<string, int> mp; // 用于将字符串映射为数字的映射表
 
int index=1; // 全局唯一的数字标识索引
 
// 获取字符串对应的数字标识
int get(string s) {
    if (mp[s]) {
        return mp[s];
    } else {
        mp[s] = index++;
        return mp[s];
    }
}
 
int N, M;
int peo[maxn]; // peo[i] 记录编号为i的管理节点的老人数量
 
vector<int> G[maxn]; // 邻接表表示图
 
int fa[maxn]; // 记录每位老人所在的管理节点
 
// 递归计算以pos为根的子树中老人的总数量
int dfs(int pos) {
    int res = peo[pos];
    cout<<res<<' '<<pos<<endl;
    for (auto u : G[pos]) {
        res += dfs(u);
    }
    return res;
}
 
int main() {
    cin >> N >> M;
 
    while (M--) {
        string a, b;
        cin >> a >> b;
        int x = get(a);
        int y = get(b);
 
        if (a[0] >= '0' && a[0] <= '9') {
            // 如果a是老人编号，则更新老人所在管理节点的老人数量，同时记录老人所在的管理节点
            peo[y]++;
            fa[x] = y;
        } else {
            // 如果a是管理节点名称，则在图中添加边，表示y管理x
            G[y].push_back(x);
        }
    }
    int j=mp["CNTR"];
       cout<<j<<endl;
       int ans=dfs(j);
    // char opt;
    // while (cin >> opt) {
    //     if (opt == 'E') break;
 
    //     string w, des;
 
    //     if (opt == 'Q') {
    //         // 查询操作
    //         cin >> w;
    //         int res = dfs(get(w));
    //         cout << res << "\n";
 
    //     } else if (opt == 'T') {
    //         // 转移老人操作
    //         cin >> w >> des;
    //         int id = get(w);
    //         int dd = get(des);
 
    //         // 更新老人所在的管理节点的老人数量
    //         peo[fa[id]]--; // 老人从原管理节点转出
    //         fa[id] = dd;   // 更新老人所在的管理节点
    //         peo[dd]++;     // 老人转入新管理节点
    //     }
    // }
 
    return 0;

}