#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const int N=1e3+10;
int a[N];
int main()
{
    read_fast
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    
    int sum=0,ans=0;
    for(int i=1;i<=n;i++){
        if(sum+a[i]<=m) sum+=a[i];
        else{
            ans++;
            sum=a[i];
        }
    }
    
    cout<<ans<<"\n";
    return 0;
}