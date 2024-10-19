#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const int N=1e5+10;
int jump[N][30];
typedef long long ll;
void solve(){
    
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> a(n+1);
    vector<ll> s(n+1);
    for(int i=1;i<=n;i++) cin>>a[i],s[i]=s[i-1]+a[i];

    for(int i=1;i<=n;i++){
        //a[id]<=k+a[i-1]
        int id=upper_bound(s.begin()+i,s.end(),s[i-1]+k)-s.begin();
        jump[i][0]=id;
    }


    //二进制优化
    for(int j=1;(1<<j)<=n;j++){
        for(int i=1;i<=n;i++){
            if(jump[i][j-1]<=n) jump[i][j]=jump[jump[i][j-1]][j-1];
            else jump[i][j]=n+1;
        }
    }

    int ans=0;
    for(int i=1;i<=n;i++){
        int id=i;
        for(int j=20;j>=0;j--){
            if((m>>j)&1) id=jump[id][j];
            if(id==n+1) break;
        }
        
        ans=max(id-i,ans);
    }
 
    cout<<ans<<"\n";
    // int res = 0;
    // for(int i = 1; i <= n; i++){
    //     int pos = i, mm = m;
    //     for(int j = 20; j >= 0; j--){
    //         if((1 << j) <= mm){
    //             mm -= (1 << j);
    //             pos = jump[pos][j]; 
    //         }
    //         if(pos == n+1) break; // 已经到了最后一个
    //     }
    //     res = max(res, pos-i);
    // }
    
    // cout << res << endl;


}
int main()
{
    read_fast;
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}