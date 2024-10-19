#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int n,m;
map<string,char> mp;
int main()
{
    read_fast
    cin>>n>>m;
    string a;
    char b;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        mp[a]=b;
    }


    string s;
    
    for(int i=1;i<=m;i++){
        cin>>s;
        if(mp.find(s)!=mp.end()) {
            cout<<mp[s]<<"\n";
            continue;
        }
        set<string> st;
        for(auto name1:mp)
            for(auto name2:mp){
                string x=name1.first+name2.first;
                if(x==s){
                    
                    string g;
                    g+=name1.second;
                    g+=name2.second;
                    //cout<<g<<"\n";
                    st.insert(g);
                }
            }

        if(st.size()==1) cout<<*st.begin()<<"\n";
        else cout<<"D"<<"\n";
        
    }
    return 0;
}