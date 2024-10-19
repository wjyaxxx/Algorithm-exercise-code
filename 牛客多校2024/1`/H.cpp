#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int n,m;
const int N=1e5+10;
struct f46
{
    string name;
    int v,t;
    bool operator<(f46& s){
        if(v!=s.v) return v>s.v;
        return t<s.t; 
    };
}a[N],b[N];
map<string,pair<int,int>> mp; 

int main()
{
    string x;
    int v,t;
    for(int i=1;i<=n;i++){
        cin>>x>>v>>t;
        a[i]={x,v,t};
        mp[x].first=1;
    }
    cin>>m;
    for(int i=1;i<=m;i++){
        cin>>x>>v>>t;
        b[i]={x,v,t};
        mp[x].second=1;
    }
    sort(a+1,a+1+n);
    sort(b+1,b+1+m);
    int ans=1e9,cnt=0;
    
    for(int i=1;i<=n;i++){
        if(mp[a[i].name].second && a[i].name!="lzr010506") cnt++;
        if(a[i].name=="lzr010506"){
            //cout<<i<<' '<<cnt<<"\n";
            ans=min(ans,i-cnt);
            break;
        }
    }
    cnt=0;
    for(int i=1;i<=m;i++){
        if(mp[b[i].name].first&& b[i].name!="lzr010506") cnt++;
        if(b[i].name=="lzr010506"){
            //cout<<i<<' '<<cnt<<"\n";
            ans=min(ans,i-cnt);
            break;
        }
    }
    cout<<ans<<"\n";
    return 0;
}