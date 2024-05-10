#include <bits/stdc++.h>
using namespace std;
const int N=110;
int my[N][N],y[N][N];
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
int main()
{
        cinquick();

        int n,m;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>my[i][j];
        
        vector<pair<int ,int>> dif;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
                cin>>y[i][j];
                if(y[i][j]!=my[i][j])
                    dif.push_back({i,j});
            }

        if(dif.empty()) cout<<"NO"<<endl;
        else
        {
            for(auto x:dif)
            {
                printf("i=%d  j=%d\n",x.first,x.second);
            }
        }
        return 0;
}