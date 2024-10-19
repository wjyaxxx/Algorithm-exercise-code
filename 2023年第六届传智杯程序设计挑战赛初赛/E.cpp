#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int main()
{
    read_fast
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> g[26];
    for(int i=0;i<s.size();i++){
        g[(s[i]-'a')].push_back(i);
    }
    int ans=0;
    for(int i=0;i<26;i++){
        for(int j=0;j<g[i].size();j++){
            int sz=g[i].size();
            ans+=(sz-j-1)*(g[i][j]-j);
            //cout<<(sz-j-1)<<' '<<g[i][j]-j<<"\n";
        }
        //cout<<"--------\n";
    }
    cout<<ans<<"\n";
    return 0;
}