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
        int q[4];
        for(int i=0;i<4;i++) cin>>q[i];
        sort(q,q+4);

        printf("%d %d %d",q[3]-q[2],q[3]-q[1],q[3]-q[0]);
        return 0;
}