#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
void solve()
{
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        string s1=s.substr(i,5);
        if(s1=="avava)") i+=4;
        else{
            string s2=s.substr(i,3);
            if(s2=="ava") i+=2;
            else{
                cout<<"No\n";
                return ;
            }
        }

    }
    cout<<"Yes\n";
}
int main()
{
    read_fast;
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}