#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int lim[11];
int main()
{
    read_fast
    lim[0]=1;
    for(int i=1;i<=10;i++) lim[i]=lim[i-1]*3;

    vector<int> ans;
    int n;
    cin>>n;
    int cnt=0;
    while(n ){
        int id=upper_bound(lim,lim+11,n)-lim;
        id--;
        n-=lim[id];
        ans.push_back(id);
        
    }
    cout<<ans.size()<<"\n";
    for(auto x:ans) cout<<x<<' ';
    return 0;
}