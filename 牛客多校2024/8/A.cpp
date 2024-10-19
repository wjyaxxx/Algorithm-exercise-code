#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const int N=1e5+10;
int st[N];
int n;
void solve()
{
    cin>>n;
    vector<int> a(n);
    fill(st,st+N,0);
    for(int i=0;i<n;i++) cin>>a[i],st[a[i]]=1;
    int ans=0;
    //没有意识到枚举d，然后直接检查d
    for(int i=1;i<N;i++){
        int g=0;
        for(int j=i;j<N;j+=i){
            if(st[j]){
                g=__gcd(g,j);
            }
        }
        if(g==i) ans++;
    }
    if((ans-n) &1) cout<<"dXqwq\n";
    else cout<<"Haitang\n";
    /*
        新产生的gcd的倍数必须存在于数组中，从小到大枚举d就行
        
    
    
    */
}
int main()
{
    read_fast;
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}