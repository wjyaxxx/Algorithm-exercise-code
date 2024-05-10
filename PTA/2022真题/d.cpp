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
        int a,b;
        cin>>a>>b;
        int res=1;
        for(int i=1;i<=(a+b);i++)
            res=res*i;
        cout<<res<<endl;
        return 0;
}