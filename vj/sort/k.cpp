#include <bits/stdc++.h>
using namespace std;
map<int,int> mp;
int n;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
int main()
{
        cinquick();
        cin>>n;
        while(n--)
        {
            int x;
            cin>>x;
            mp[x]++;
        }
        for(auto x:mp)
        {
            cout<<x.first<<' '<<x.second<<endl;
        }
        return 0;
}