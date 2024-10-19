#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
void solve()
{
    int n;
    cin>>n;
    vector<int> num(n);
    for(int i=0;i<n;i++) cin>>num[i];
    vector<int> b(n-1);
    for(int i=0;i<n-1;i++){
        b[i]=__gcd(num[i],num[i+1]);
    }

    int bad=0;
    for(int i=0;i<n-2;i++){
        bad+=(b[i]>b[i+1]);
    }
    bool  ans=false;
    if(bad-(b[0]>b[1])==0) ans=true;
    if(bad-(b[n-3]>b[n-2])==0) ans=true;

    //删中间
    for(int i=1;i<n-1;i++){
        int cbad=bad;
        int g=__gcd(num[i-1],num[i+1]);
        cbad-=(b[i]<b[i-1]);
        if(i-1>0){
            cbad-=(b[i-1]<b[i-2]);
            cbad+=(g<b[i-2]);
        }
        if(i+1<n-1){
            cbad-=b[i+1]<b[i];
            cbad+=b[i+1]<g;
        }
        if(cbad==0) ans=1;
    }
    if(ans) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
int main()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
        int t;
        cin>>t;
        while(t--) solve();
        return 0;
}