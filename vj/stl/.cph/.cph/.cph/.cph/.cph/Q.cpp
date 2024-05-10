#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n;
LL p,ans;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
const int N=100010;
LL q[4][N];
set<LL> s;
//取模没有局部最优解，所以此题不能用dp，那就枚举两个拐点

int main()
{
        cinquick();
        cin>>n>>p;
        for(int i=1;i<=3;i++){
            for(int j=1;j<=n;j++) cin>>q[i][j],q[i][j]=(q[i][j]+q[i][j-1])%p;
        }

        for(int i=1;i<=n;i++){
            LL res=(q[1][i] - q[2][i - 1] + p) % p;
            s.insert(res);
            set<LL>::iterator it;
            LL cur=(q[2][i] - q[3][i - 1] + q[3][n] + p) % p;
            it=s.lower_bound(p-cur);
            if(it==s.begin())//全部都大于p
            {
                ans=max(ans,(*(--s.end())+cur)%p);
            }
            else{
                ans=max(ans,(*(--it)+cur)%p);
            }
        }
        cout<<ans<<endl;
        return 0;
}