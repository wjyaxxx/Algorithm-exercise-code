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
        //cinquick();
        string x;
        int n,m,k;
        cin>>n>>x>>m>>k;
        if(k==n) printf("mei you mai %s de\n",x.c_str());
        else if(k==m)printf("kan dao le mai %s de\n",x.c_str());
        else printf("wang le zhao mai %s de\n",x.c_str());
        return 0;
}