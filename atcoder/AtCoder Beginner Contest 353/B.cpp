#include <bits/stdc++.h>
using namespace std;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
const int N=110;
int q[N];
int n,k;
int main()
{
        cinquick();
        cin>>n>>k;
        for(int i=1;i<=n;i++) cin>>q[i],q[i]+=q[i-1];
        int cnt=0;
        for(int i=1,j=1;i<=n;i++){
            while(j<=n&&q[j]-q[i-1]<=k) j++;
            cnt++;
            i=j-1;
        }
        cout<<cnt<<endl;
        
       
        return 0;
}