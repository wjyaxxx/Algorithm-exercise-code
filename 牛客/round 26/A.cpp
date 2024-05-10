#include <bits/stdc++.h>
using namespace std;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
int main()
{
        cinquick();
        string a;
        cin>>a;
        int sza=a.size();
        string b=a.substr(0,sza-3);
        cout<<b<<endl;
        return 0;
}