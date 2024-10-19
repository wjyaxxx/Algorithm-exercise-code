#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int main()
{
    read_fast
    int n,q;
    cin>>n>>q;
    vector<int> p(n+1);
    vector<set<int>> s(n+1);
    for(int i=1;i<=n;i++) p[i]=i,s[i].insert(i);
    
    auto find=[&](auto self,int x)->int{
        if(x!=p[x]) p[x]=self(self,p[x]);
        return p[x];
    };
    

    int id;
    while(q--){
        cin>>id;
        if(id==1){
            int u,v;
            cin>>u>>v;
            int fu=find(find,u),fv=find(find,v);
            if(fu==fv) continue;
            if(s[fu].size()>s[fv].size()) swap(fu,fv);
            //fv最大
            for(auto x:s[fu]) s[fv].insert(x);
            p[fu]=fv;
        }else{
            int v,k;
            cin>>v>>k;
            int fv=find(find,v);
            if(s[fv].size()<k) cout<<"-1\n";
            else{
                auto it=s[fv].end();
                while(k--) it--;
                cout<<*(it)<<"\n";
            }
        }

    }
    return 0;
}