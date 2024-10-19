
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(n);
    vector<int> pos(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      --a[i];
      pos[a[i]] = i;
    }
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
      cin >> b[i];
      --b[i];
    }
    vector<set<int>> s(n);
    for (int i = 0; i < m; i++) {
      s[b[i]].insert(i);
    }
    for (int i = 0; i < n; i++) {
        //表示i最后演示的位置不存在
      s[i].insert(m);
    }
    vector<int> val(n);
    for (int i = 0; i < n; i++) {
      val[i] = *s[a[i]].begin();
    }
    int fail = 0;
    for (int i = 0; i < n - 1; i++) {
      fail += val[i] > val[i + 1];
    }
    cout << (fail ? "TIDAK" : "YA") << '\n';
    auto Updata=[&](int i){
        //删除
        if(i);
        fail-=(val[i-1]>val[i]);
        if(i+1<n)
        fail-=(val[i]>val[i+1]);

        //将val[i]更改
        val[i]=*s[a[i]].begin();
        if(i);
        fail+=(val[i-1]>val[i]);
        if(i+1<n)
        fail+=(val[i]>val[i+1]);
    };
    int id,x;
    while(q--){
        cin>>id>>x;
        id--;
        x--;
        //找到b数组的数字
        int old=b[id];
        s[old].erase(id);
        b[id]=x;
        s[b[id]].insert(id);
        Updata(pos[old]);
        Updata(pos[b[id]]);
        cout << (fail ? "TIDAK" : "YA") << '\n';
    }
  }
  return 0;
}
