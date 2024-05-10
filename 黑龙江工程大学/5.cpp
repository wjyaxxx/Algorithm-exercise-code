#include <bits/stdc++.h>
using namespace std;
string str;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
void solve()
{
    int n;
    cin>>n;
    cin>>str;
    reverse(str.begin(),str.end());
    while(str.back()=='0'&&str.size()>1) str.pop_back();

    reverse(str.begin(),str.end());

    
}
int main()
{
        cinquick();
        int t;
        cin>>t;
        while(t--) solve();
        return 0;
}