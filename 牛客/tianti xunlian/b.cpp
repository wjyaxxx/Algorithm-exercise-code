#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N],b[N];
bool st[N];
int n,m;
long long ans;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
int main()
{
        cinquick();
        cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>a[i];
        sort(a+1,a+1+n);
        
        for(int i=1;i<=m;i++){
            int x;
            cin>>x;
            int j=upper_bound(a+1,a+1+n,x)-a;
            
           if(!st[j]&&j<=n){
                ans++;
                st[j]=1;
               // cout<<j<<endl;
           }
           else if(st[j])
           {
                while(st[j]&&j<=n)
                {
                    j++;
                }
                if(j<=n){
                st[j]=1;
                ans++;
                }
           }
        }
        cout<<ans<<endl;
        return 0;
}