#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int> q[N];
int cun[110],tt=1;
int n,m;
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
        for(int i=1;i<=n;i++){
            int k;
            cin>>k;
            for(int j=1;j<=k;j++){
                int x;
                cin>>x;
                q[i].push_back(x);
            }
        }
        int now=1;
        int op,j;
        for(int i=1;i<=m;i++)
        {
            cin>>op>>j;

            if(op==0)
                now=q[now][j-1];
            else if(op==1){
                cout<<now<<endl;
                cun[j]=now;
            }
            else{
                now=cun[j];
            }
        }
        cout<<now<<endl;
        return 0;
}