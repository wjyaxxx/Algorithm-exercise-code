#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int main()
{
    read_fast
    int n,k;
    vector<int> lim(k+1);
    map<string,set<int>> mp;
    cin>>n>>k;
    for(int i=1;i<=k;i++) cin>>lim[i];
    for(int i=1;i<=n;i++){
        int x;
        string name;
        cin>>x>>name;
        mp[name].insert(x);
    }
   
    vector<int> g[k+1];
    for(auto t:mp){
        int id=1;
        auto bg=t.second.begin();
        auto ed=t.second.end();
        int cnt=0;
        while(bg!=ed){
            if(cnt<lim[id]){
                cnt++;
                g[id].push_back(*bg);
            }else  {
                id++;
                g[id].push_back(*bg);
                cnt=1;
            }
            bg++;
        }
    }
    
    for(int i=1;i<=k;i++){
        for(auto x:g[i]) cout<<x<<' ';
        cout<<"\n";
    }
    return 0;
}