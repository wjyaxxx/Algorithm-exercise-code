#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    sort(a.begin(),a.end());
    if(a[0]!=a[1]) cout<<"YES\n";
    else{
        for(int i=1;i<n;i++)
            if(a[i]%a[0]!=0){
                cout<<"YES\n";
                return ;
            }
        cout<<"NO\n";
    }
}
int main()
{
    read_fast;
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}