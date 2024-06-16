#include <bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
int a[N],b[N];
int n,m;
int main()
{
        ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
       cin>>n>>m;
       
       for(int i=0;i<n;i++) cin>>a[i];
       for(int i=0;i<m;i++) cin>>b[i];
       sort(a,a+n);
       sort(b,b+m);

        bool ok=false;
        long long ans=0;
        int last=-1;
       for(int i=0;i<m;i++){
            
            int j=lower_bound(a+last+1,a+n,b[i])-a;
            if(j==n) {
                ok=true;
                break;
            }
            last=j;
            ans+=a[j];
           
       }
       ok?cout<<-1:cout<<ans;
        return 0;
}