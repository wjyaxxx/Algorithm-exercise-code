#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
void solve()
{
    double l,x,y;
    cin>>l>>x>>y;
    double res1=(x*x+y*y)/(2*x);
    res1=max(res1,l/2);
    if(res1 <= l){
            cout<<"Yes\n";
            cout<<res1<<"\n";
            return ;
        }
    if(x>l){
        double res2=(x*x+y*y-l*l)/(2*(x-l));
        res2=max(res2,(double)0);
        if(res2<=l/2) {
            cout<<"Yes\n";
            cout<<res2<<"\n";
            return ;
        }
        else{
            cout<<"No\n";
            return ;
        }
    }
    else if(x<l){
        double res2=(x*x+y*y-l*l)/(2*(x-l));
        res2=min(res2,l/2);
        if(res2>=0){
            cout<<"Yes\n";
            cout<<res2<<"\n";
            return ;
        }
         else{
            cout<<"No\n";
            return ;
        }
    }else{
        if(x*x+y*y<=l*l) {
            cout<<"Yes\n";
            cout<<0<<"\n";
            return;
        }else {
            cout<<"No\n";
            return ;
        }
    }
    
}
int main()
{
    read_fast;
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}