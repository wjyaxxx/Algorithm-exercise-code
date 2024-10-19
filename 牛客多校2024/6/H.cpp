#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
void solve()
{
    string s;
   
    cin>>s;
    //cout<<s.size()<<"\n";
    vector<int> idx;
    bool ok=false;
    //先判断1
    for(int i=0;i<s.size();i++){
        if(s[i]=='3'){
            int cnt=0;
            while(i<s.size() && s[i]=='3'){
                cnt++;
                i++;
            }
            if(cnt>=10) ok=true;
            i--;
        }
    }
    idx.push_back(-1);
    
    for(int i=0;i<s.size();i++){
        if(s[i]=='5'|| s[i]=='U') {
            idx.push_back(i);
        }
    }
    idx.push_back(s.size());
    for(int i=0;i<idx.size()-1;i++){
        if(idx[i+1]-idx[i]>90) ok=true;
        if(i>=1 && i<idx.size()-2 && s[idx[i+1]]==s[idx[i]]&& s[idx[i]]=='5') {
            
            ok=true;
        }

    }
    
    if(ok) cout<<"invalid\n"; 
    else cout<<"valid\n";

}
int main()
{
    read_fast;
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}
