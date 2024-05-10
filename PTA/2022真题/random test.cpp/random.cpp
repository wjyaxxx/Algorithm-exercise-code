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
        default_random_engine e;
        e.seed(time(0));
        uniform_int_distribution<int> u(0,10);

        cout<<20<<' '<<6<<' '<<8<<endl;
        for(int i=1;i<=20;i++){
            cout<<u(e)<<' ';
        }
        
        return 0;
}