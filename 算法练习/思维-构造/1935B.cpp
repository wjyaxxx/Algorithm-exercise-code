#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    
    vector<int> pre(n),suf(n);
    int mx=0;
    vector<int> cnt1(n),cnt2(n);
    for(int i=0;i<n;i++){
        cnt1[a[i]]++;
        while(cnt1[mx]) mx++;
        pre[i]=mx; 
    }
    mx=0;
    for(int i=n-1;i>=0;i--){
        cnt2[a[i]]++;
        while(cnt2[mx]) mx++;
        suf[i]=mx; 
    }

    for(int i=0;i<n-1;i++){
        if(pre[i]==suf[i+1]){
            cout<<2<<"\n";
            cout<<1<<' '<<i+1<<"\n";
            cout<<i+2<<" "<<n<<"\n";
            return ;
        }
    }
    cout<<-1<<"\n";
}   
int main()
{
    read_fast;
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}