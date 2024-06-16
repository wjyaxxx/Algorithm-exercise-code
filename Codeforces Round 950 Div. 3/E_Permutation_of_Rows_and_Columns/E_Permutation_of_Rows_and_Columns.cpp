#include <bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
void solve()
{
    int n,m;
    cin>>n>>m;
   
    vector<vector<int>> a(n,vector<int>(m));
    vector<vector<int>> b(n,vector<int>(m));
    vector<int> r(n*m),c(n*m);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            a[i][j]--;
            
             r[a[i][j]]=i;
             c[a[i][j]]=j;
        }
    }

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            cin>>b[i][j];
            b[i][j]--;
        }

    for(int i=0;i<n;i++){
        int ridx=r[b[i][0]];
        swap(a[i],a[ridx]);
        for(int j=0;j<m;j++){
            r[a[i][j]]=i;
            r[a[ridx][j]]=ridx;
        }
    }
    for(int j=0;j<m;j++){
        int cidx=c[b[0][j]];
        for(int i=0;i<n;i++){
            swap(a[i][j],a[i][cidx]);
            c[a[i][j]]=j;
            c[a[i][cidx]]=cidx;
        }
    }

    if(a==b) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
int main()
{
        ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
        int t;
        cin>>t;
        while(t--) solve();
        return 0;
}