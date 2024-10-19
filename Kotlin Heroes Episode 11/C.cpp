#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
void solve(){
    int  b,c,d;
    cin>>b>>c>>d;
    int te=(1ll<<61);
    
    if((te|b)-(te & c)==d){
        cout<<te<<"\n";
        return;
    }
    vector<int> ans(61);
    for(int i=60;i>=0;i--){
        int wb=(b>>i)&1ll,wc=(c>>i)&1ll,wd=(d>>i)&1ll;
        //cout<<wb<<' '<<wc<<' '<<wd<<"\n";
        if(wd){
            //wb|wa 为1 wc&wa 为0
            if(!wb && wc){
                cout<<-1<<"\n";
                return;
            }
            if(!wb) ans[i]=1;
            else ans[i]=0;
        }else{
            //分为1-1 和0-0
            if(!wc){
                //则只能是0-0
                if(!wb) ans[i]=0;
                else{
                    cout<<-1<<"\n";
                    return ;
                }
            }else ans[i]=1;
        }
    } 
    
    int res=0;
    for(int i=0;i<=60;i++){
        if(ans[i]) res|=(1ll<<i);
    }   
    cout<<res<<"\n";
}
signed main()
{
    read_fast;
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}