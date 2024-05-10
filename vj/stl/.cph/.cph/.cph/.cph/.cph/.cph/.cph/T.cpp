#include <bits/stdc++.h>
using namespace std;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
const int N=2010;
bitset<N> g[N];
int n;
char m[N][N];
int main()
{
        cinquick();
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
            {
                cin>>m[i][j];
                if(m[i][j]=='1')
                    g[i][j]=1;
            }
            g[i][i]=1;
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++){
                if(g[i][j]){
                    g[i]|=g[j];
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(g[i][j]) ans++;
        cout<<ans<<endl;
        return 0;
}