#include <bits/stdc++.h>
using namespace std;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
typedef long long LL;
const int N=3*1e5+10,mod=1e8;
LL q[N];
int n;
LL res;
int main()
{
        cinquick();
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>q[i];
            res+=q[i];
        }
        
        res=res*(n-1);
        sort(q,q+n);
        
        for(int i=0;i<n;i++){
            int j=lower_bound(q,q+n,mod-q[i])-q;
            j=max(j,i+1);
            res-=(n-j)*(LL)mod;
        }
        cout<<res<<endl;

        return 0;
}