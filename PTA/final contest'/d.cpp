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
    int a,b,c;
    cin>>a>>b>>c;
    if(a*b==c) cout<<"Lv Yan"<<endl;
    else if(a+b==c) cout<<"Tu Dou"<<endl;
    else cout<<"zhe du shi sha ya!"<<endl;

}
int main()
{
        cinquick();
        int t;
        cin>>t;
        while(t--) solve();
        return 0;
}