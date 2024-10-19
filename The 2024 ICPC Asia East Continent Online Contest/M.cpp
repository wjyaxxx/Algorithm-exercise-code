#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
void solve()
{
    int pro[26]={0};
    int n;
    cin>>n;
    map<pair<string,char>,bool>  mp; 
    int ans=0;
    for(int i=1;i<=n;i++){
        string name,st;
        char id;
        cin>>name>>id>>st;
        
        if(st=="accepted"){
            
            if(mp.find({name,id})==mp.end()) pro[(id-'A')]++;
            mp[{name,id}]=1;
            ans=max(ans,pro[id-'A']);
        }
    }
    
    for(int i=0;i<26;i++){
        if(ans==pro[i]){
            cout<<char('A'+i)<<"\n";
            break;
        }
    }
    
}
int main()
{
    read_fast;
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}