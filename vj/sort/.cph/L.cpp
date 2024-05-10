#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int q[N];
int n,m;
int ans;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
int main()
{
        cinquick();
        cin>>n>>m;
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            int x;
            cin>>x;
            if(sum+x<=m){
                sum+=x;
            }
            else{
                sum=x;
                ans++;
            }
        }
        if(sum) ans++;
            cout<<ans<<endl;
        return 0;
}