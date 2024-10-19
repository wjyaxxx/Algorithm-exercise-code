#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const int N=100<<1;
int f[N][N],g[N][N];
int n;
int main()
{
    //read_fast
    cin>>n;
    vector<int> a(2*n+1);
    for(int i=1;i<=n;i++) cin>>a[i],a[i+n]=a[i];
    
    memset(f,0x3f,sizeof f);
    memset(g,-0x3f,sizeof g);
    for(int i=1;i<=2*n;i++) f[i][i]=g[i][i]=0;
    for(int i=1;i<=2*n;i++){
        a[i]+=a[i-1];
    }
    for(int len=2;len<=n;len++)
        for(int l=1;l+len-1<=2*n;l++){
            int r=l+len-1;
            for(int k=l;k<r;k++){
                f[l][r]=min(f[l][r],f[l][k]+f[k+1][r]+a[r]-a[l-1]);
                g[l][r]=max(g[l][r],g[l][k]+g[k+1][r]+a[r]-a[l-1]);
            }
        }
    // for(int l=1;l<=2*n;l++){
    //     for(int j=1;j<=2*n;j++)
    //         printf("%10d ",f[l][j]);
    //     cout<<"\n";
    // }
    int minv=INT_MAX,maxv=INT_MIN;
    
    for(int i=1;i<=n;i++){
        
        minv=min(minv,f[i][i+n-1]);
        maxv=max(maxv,g[i][i+n-1]);

    }
    cout<<minv<<"\n";
    cout<<maxv<<"\n";
   
    return 0;
}