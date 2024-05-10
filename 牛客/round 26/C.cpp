#include <bits/stdc++.h>
using namespace std;
long long ans;
int st[1010];
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
        for(int i=a.size()-1;i>0;i--)
        {
            if(a[i]<='Z'&&a[i]>='A'&&!st[i])
            {
                st[i-1]=true;
                ans++;
            }
        }
        cout<<ans<<endl;
        return 0;
}