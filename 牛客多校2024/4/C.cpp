#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int n;
const int N=1e6+10;
int a[N];
bool st[N];
void solve(){
    
    cin>>n;
    fill(a+1,a+1+n,0);
    fill(st+1,st+1+n,0);
    for(int i=1;i<=n;i++) cin>>a[i];
    int ans=0,cnt2=0;
    for(int i=1;i<=n;i++){
        if(st[i])  continue;
            int j=i,cnt=1;
            st[j]=1;
            while(!st[a[j]]){
                cnt++;
                j=a[j];
                st[j]=true;
            }
            //两个2可以拼一个4
            ans+=(cnt/3);
            cnt%=3;
            if(cnt==2) cnt2++;
    }
    cout<<ans+(cnt2+1)/2<<"\n";
}
int main()
{
    read_fast;
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}