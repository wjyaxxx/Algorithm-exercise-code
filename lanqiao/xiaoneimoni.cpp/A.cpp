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
        int res=0;
        for(int i=1;i<=2023;i++)
        {
            if(2023%i==0) res++;
        }
        cout<<res<<endl;
        return 0;
}