#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=110;
int q[N][N];
LL ans,sum;
int n,m,x;
int cnt[2][N];//0为行，1为列
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
int main()
{
        cinquick();
        cin>>n>>m>>x;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                {
                    cin>>q[i][j];
                    sum+=q[i][j];
                    ans^=q[i][j];
                }

        for(int i=1;i<=n;i++)
        {
            int res=0;
            for(int j=1;j<=m;j++)
            {
                res^=q[i][j];
            }
            q[0][i]=res;
        }
        for(int j=1;j<=m;j++)
        {
            int res=0;
            for(int i=1;i<=n;i++)
            {
                res^=q[i][j];
            }
            q[1][j]=res;
        }
        if(sum!=x)
        {
            cout<<"wrong answer"<<endl;
            return 0;
        }
        else
        {
            ans=q[0][1];
            bool ok=false;
            for(int i=2;i<=n;i++)
                if(ans!=q[0][i])
                    ok=true;
            for(int j=1;j<=m;j++)
                if(ans!=q[1][j])
                    ok=true;
            ok==false?cout<<"accepted"<<endl:cout<<"wrong answer"<<endl;
        }
        return 0;
}