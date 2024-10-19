#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

int main()
{
    read_fast
    stack<int> stk;
    int n;
    cin>>n;
    vector<int> a(n+1);
    vector<int> l(n+1);
    vector<int> cha(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];

    //找到左边第一个比我大的
    for(int i=1;i<=n;i++){
        while(!stk.empty() && a[i]>=a[stk.top()]) stk.pop();
        if(!stk.empty()) l[i]=stk.top();
        stk.push(i);
    }

    for(int i=1;i<=n;i++){
        cha[l[i]]++;
        cha[i]--;
    }
    for(int i=1;i<=n;i++){
        cha[i]+=cha[i-1];
        cout<<cha[i]<<' ';
    }
    return 0;
}