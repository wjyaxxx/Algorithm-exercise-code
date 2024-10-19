#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int main()
{
    read_fast
    int n;
    cin>>n;
    vector<int> a(n+1);

    for(int i=1;i<=n;i++) cin>>a[i];


    
    long long ans=0;
    for(int l=1,r=1;l<=n;l++){
        while(r<=n && (l==r || r==l+1 || a[r]-a[r-1]==a[r-1]-a[r-2])) r++;
        //cout<<l<<' '<<r<<"\n";
        ans+=(r-l);
    }
    cout<<ans<<"\n";
    return 0;
}