#include <bits/stdc++.h>
using namespace std;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
void solve()
{
    string s;
    cin>>s;
    int a=0,b=0;
    for(int i=0;i<5;i++)
    {
        if(s[i]=='A') a++;
        else b++;
    }
    a>b?cout<<'A':cout<<'B';
    cout<<endl;
}
int main()
{
        cinquick();
        int t;
        cin>>t;
        while(t--) solve();
        return 0;
}