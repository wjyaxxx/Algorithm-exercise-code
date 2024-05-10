#include <bits/stdc++.h>
using namespace std;
const int N = 1010, M = 1010;

int h[N], e[M], w[M], nxt[M], eidx;

void add(int u, int v, int weight)   // 添加有向边 u->v, 权重为weight
{
    e[eidx] = v;        // 记录边的终点
    w[eidx] = weight;   // 记录边的权重
    nxt[eidx] = h[u];   // 将下一条边指向结点u此时的第一条边
    h[u] = eidx;        // 将结点u的第一条边的编号改为此时的eidx
    eidx++;             // 递增边的编号edix, 为将来使用
}

void iterate(int u)   // 遍历结点u的所有邻边
{
    // 从u的第一条边开始遍历，直到eid==-1为止
    for(int eid = h[u]; eid != -1; eid = nxt[eid])
    {
        int v = e[eid];
        int weight = w[eid];
        cout << u << "->" << v << ", weight: " << weight << endl;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    memset(h, -1, sizeof h);  // 初始化h数组为-1
    eidx = 0;                 // 初始化边的编号为0

    while(m--)
    {
        int u, v, weight;
        cin >> u >> v >> weight;
        add(u, v, weight);
        add(v,u,weight);
    }

    for(int u = 1; u <= n; ++u)
        iterate(u);

    return 0;
}

