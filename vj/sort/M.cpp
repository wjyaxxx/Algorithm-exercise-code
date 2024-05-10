#include <bits/stdc++.h>
using namespace std;
int n;
const int N=1e5+5;
int q[N];
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
void solve()
{
    int n;
    cin>>n;
    int even=0,odd=0,x;
    bool ok=false;
    for(int i=1;i<=n;i++){
        cin>>x;
        if(x&1){
            if(x<odd){
                ok=true;
            }
            else odd=x;
        }
        else{
            if(x<even){
                ok=true;
            
            }
            else even=x;
        }
    }
    if(!ok)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
int main()
{
        cinquick();
        int t;
        cin>>t;
        while(t--) solve();
        return 0;
}