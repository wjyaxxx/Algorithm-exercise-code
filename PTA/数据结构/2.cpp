#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int main()
{
    read_fast
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    int maxv=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        maxv=max(maxv,a[i]*m);
    }
    cout<<maxv<<"\n";
    return 0;
}