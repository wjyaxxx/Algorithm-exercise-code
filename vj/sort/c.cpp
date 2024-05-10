#include <bits/stdc++.h>
using namespace std;
const int N=2010;
int q[N];
int n;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
int main()
{
        cinquick();
        cin>>n;
        for(int i=1;i<=n;i++) cin>>q[i];
        sort(q+1,q+1+n);
       
        puts("");
        if(n&1){
                cout<<q[(n+1)>>1]<<endl;
        }
        else{
                cout<<q[n>>1]<<endl;
        }
        return 0;
}