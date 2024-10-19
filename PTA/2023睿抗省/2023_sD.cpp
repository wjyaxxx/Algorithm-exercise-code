#include <bits/stdc++.h>
using namespace std;
#define PSI pair<string,int>
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
map<PSI,int> mp;
map<PSI,PSI> r;
map<int,PSI> name;
vector<int> g[2010];
int idx; 
int m;
vector<int> ans;//存储答案
vector<int> res;//存储当前路径
void dfs(int st,int u){
    res.push_back(u);
    if(st==mp[r[name[u]]]){
        if(ans.empty()||ans.size()>res.size()) ans=res;
        return ;
    }
    for(auto x:g[u]){
        dfs(st,x);
    }
    res.pop_back();
}
void print(int x){
    cout<<name[x].first<<' '<<name[x].second;
}
int main()
{
    read_fast
    cin>>m;
    string A,B;
    int a,b;
    for(int i=1;i<=m;i++){
        cin>>A>>a>>B>>b;
        if(!mp[{A,a}]){
            //不存在这个点
             mp[{A,a}]=++idx;
             name[idx]={A,a};
             r [{A,a}]={A,!a};
        }
        if(!mp[{B,b}]){
            mp[{B,b}]=++idx;
            name[idx]={B,b};
            r [{B,b}]={B,!b};
        }

        //建边
        g[mp[{A,a}]].push_back(mp[{B,b}]);
    }

    //以每个点为起点遍历看是否能找到
    for(int i=1;i<=idx;i++){
        res.clear();
        dfs(i,i);
    }
    

    print(ans[0]);
    cout<<" ";
    for(int i=1;i<ans.size()-1;i++){
        print(ans[i]);
        cout<<' ';
        print(ans[i]);
        cout<<' ';
    }
    int n=ans.size();
    print(ans[n-1]);
    cout<<" = ";
    print(ans[0]);
    cout<<' ';
    print(ans[n-1]);
    return 0;
}