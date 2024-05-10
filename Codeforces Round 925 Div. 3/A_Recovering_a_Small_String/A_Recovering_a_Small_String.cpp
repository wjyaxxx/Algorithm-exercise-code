#include <bits/stdc++.h>
using namespace std;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
void solve()
{
    int n;
    cin>>n;
    if(3<=n&&n<=28)
    {
       printf("aa%c\n",n-2-1+'a');
    }
    else if(n>=28&n<53)
    {
        printf("a%cz\n",n-27-1+'a');
    }
    else{
        printf("%czz\n",n-52-1+'a');
    }
}
int main()
{
        int t;
        cin>>t;
        while(t--) solve();
        return 0;
}