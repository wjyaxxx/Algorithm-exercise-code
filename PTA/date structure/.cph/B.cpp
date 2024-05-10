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
        set<int> s;
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            int x;
            cin>>x;
            if(s.upper_bound(x)!=s.end())
            {
                s.erase(s.upper_bound(x));
                s.insert(x);
            }
            else s.insert(x);
        }
        cout<<s.size()<<endl;
        return 0;
}