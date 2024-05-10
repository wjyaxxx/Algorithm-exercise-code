#include <bits/stdc++.h>
using namespace std;
int n;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
void solve()
{
    string str;
    getline(cin,str);
    stringstream s;
    s<<str;
    string x;
    while(s>>x){
        reverse(x.begin(),x.end());
        cout<<x<<' ';
    }
    printf("\n");

}
int main()
{
        //cinquick();
        cin>>n;
        getchar();
        while(n--) solve();
        return 0;
}