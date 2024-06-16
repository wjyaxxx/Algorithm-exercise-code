#include <bits/stdc++.h>
using namespace std;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}

void solve()
{
    int l,r;
    cin>>l>>r;
    for(int i=30;i>=0;i--){
        int res=1<<i;
        if(res<=r){
            cout<<i<<endl;
            break;
        }
    }
}
int main()
{
        cinquick();
        int t;
        cin>>t;
        while(t--) solve();
        return 0;
}