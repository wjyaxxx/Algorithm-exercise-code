#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int main()
{
    read_fast
    int n;
    cin>>n;
    vector<int> a(n);
    int ans=0;
    for(int i=0;i<n;i++) cin>>a[i],ans^=a[i];
    if(ans){
        for(int i=0;i<n;i++){
            int na=a[i]^ans;
            if(na<a[i]){
                cout<<a[i]-na<<' '<<i+1<<"\n";
                a[i]=na;
                break;
            }
        }
        for(auto x:a) cout<<x<<' ';
    }else{
        cout<<"lose\n";
    }
    
    return 0;
}