#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
void solve()
{
    int n;
    cin>>n;
    vector<int>a(n),b(n);
    
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    
    int ans=0,sum=0,cnt=0;
    for(int i=0;i<n;i++){
        if(a[i]>b[i]){
            ans++;
            sum-=b[i];
        }
        else if(a[i]<b[i]){
            sum+=a[i];
        }else{
            cnt++;
        }
    }
    ans+=(cnt+1)/2;
    cout<<ans<<"\n";
    
  
}
int main()
{
    read_fast;
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}