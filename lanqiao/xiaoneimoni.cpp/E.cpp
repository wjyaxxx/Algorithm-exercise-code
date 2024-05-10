#include <bits/stdc++.h>
using namespace std;
const int N=110;
typedef long long LL;
int n,m;
int q[N][N];
LL res;
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
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>q[i][j];
                q[i][j]+=q[i-1][j]+q[i][j-1]-q[i-1][j-1];
            }
        }

        for(int i=1;i+4<=n;i++)
        {
            for(int j=1;j+4<=m;j++)
            {
                LL sum=(LL)q[i+4][j+4]-q[i-1][j+4]-q[i+4][j-1]+q[i-1][j-1];
                res=max(res,sum);
            }
        }
        cout<<res<<endl;
        return 0;
}