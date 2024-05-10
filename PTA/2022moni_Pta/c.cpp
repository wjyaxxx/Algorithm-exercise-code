#include <bits/stdc++.h>
using namespace std;
int n,k,x;
const int N=110;
int q[N][N];
typedef long long LL;
LL sum;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
int main()
{
        cinquick();
        cin>>n>>k>>x;
        int cnt=0;

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                cin>>q[i][j];
        }
        for(int j=2;j<=n;j+=2)
        {
            cnt++;
            if(cnt==k+1) cnt=1;
            for(int i=n-cnt;i>=1;i--){
                q[i+cnt][j]=q[i][j];
            }
            for(int i=1;i<=cnt;i++)
            {
                q[i][j]=x;
            }
        }

        for(int i=1;i<=n;i++)
        {
            sum=0;
            for(int j=1;j<=n;j++)   
                sum+=q[i][j];
            if(i==1) cout<<sum;
            else cout<<' '<<sum;
        }
        return 0;
}