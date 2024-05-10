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
    int n,k;
    cin>>n>>k;
    int a=n/2,b=n-n/2;
    int s=2,base=0;
    while(k>b){
        base+=b;
        k-=b;
        n=a;
        a=n/2;
        b=n-n/2;
        s+=2;
    }
    cout<<s*k+base<<endl;
}
int main()
{
        cinquick();
        int t;
        cin>>t;
        while(t--) solve();
        return 0;
}