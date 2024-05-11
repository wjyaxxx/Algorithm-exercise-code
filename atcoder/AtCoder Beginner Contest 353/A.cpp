#include <bits/stdc++.h>
using namespace std;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
const int N=110;
int q[N];
int n;
int main()
{
        cinquick();
        cin>>n;
        bool ok=false;
        for(int i=1;i<=n;i++){
            cin>>q[i];
        }
        for(int i=2;i<=n;i++){
            if(q[i]>q[1]){
                cout<<i<<endl;
                ok=true;
                break;
            }
        }
        if(!ok) cout<<"-1"<<endl;
        return 0;
}