#include <bits/stdc++.h>
using namespace std;
const int N=110;
int q[N];
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
int main()
{
        cinquick();
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>q[i];
        int t;
        cin>>t;
        while(t--)
        {
            int cnt=0;
            bool ok=false;
            for(int i=1;i<=n;i++)
            {
                int x;
                cin>>x;
                if(x==0) cnt++;
                else
                {
                    if(x!=q[i]) ok=true;
                }
            }
            if(cnt==n||ok) cout<<"Ai Ya"<<endl;
            else cout<<"Da Jiang!!!"<<endl;
        }
        return 0;
}