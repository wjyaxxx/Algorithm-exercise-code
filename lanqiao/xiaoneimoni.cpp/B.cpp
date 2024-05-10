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
        for(int l=0;l<=100;l++)
        {
            for(int r=l;r<=100;r++)
            {
                if(r-l>=10) res++;
            }
        }
        cout<<res<<endl;
        return 0;
}