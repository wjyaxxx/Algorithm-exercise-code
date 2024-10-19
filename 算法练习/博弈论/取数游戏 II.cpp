#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int main()
{
    read_fast
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    //先从第一个点出发
    if(a[0]){
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!a[i]) break;
            cnt++;
        }
        if(cnt & 1){
            cout<<"YES\n";
            return 0;
        }
    }
    if(a[n-1]){
        int cnt=0;
        for(int i=n-1;i>=0;i--){
            if(!a[i]) break;
            cnt++;
        }
        if(cnt & 1){
            cout<<"YES\n";
            return 0;
        }
    }
    cout<<"NO\n";
    return 0;
}