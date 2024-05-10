#include <bits/stdc++.h>
using namespace std;
int a,b,c,n,m;
const int N=110;
int q[N];
string str;

void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
bool check()
{
    bool ok_0=true,ok=true;
    int x;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        if(x==0) continue;
        else{
            ok_0=false;
            if(x!=q[i])
                ok=false;
        }
    }
    if(!ok) return false; 
    if(ok_0) return false;
    return true;
}
signed main()
{
        cinquick();
       
        cout<<"No Solution"<<endl;
        return 0;
}