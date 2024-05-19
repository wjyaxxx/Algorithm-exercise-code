#include <bits/stdc++.h>
using namespace std;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
typedef long long LL;
const int P=13331,N=2*1e5+10,mod1=2013265921,mod2=1004535809;
LL h1[N],p1[N],h2[N],p2[N];
char str[N];
int n,l1,r1,k;
pair<LL,LL> get_hash(int l,int r){
    LL res1=(h1[r] - h1[l - 1] * p1[r - l + 1]%mod1+mod1)%mod1;
    LL res2=(h2[r] - h2[l - 1] * p2[r - l + 1]%mod2+mod2)%mod2;
    return make_pair(res1,res2);
}
bool check(int x)
{
    int cnt=1;
    auto cmp_val=get_hash(1,x);
    for(int i=x+1;i+x-1<=n;i++){
        int l=i,r=i+x-1;
        if(get_hash(l,r)==cmp_val) {
            cnt++;
            i=i+x-1;
        }
    }
    return cnt>=k;
}
void solve()
{
    fill(h1,h1+N,0);
    fill(h2,h2+N,0);
    scanf("%d%d%d",&n,&l1,&r1);
    k=l1;
    scanf("%s",str+1);
    for (int i = 1; i <= n; i ++ )
    {
        h1[i] = (h1[i - 1] * P%mod1 + str[i])%mod1;
        h2[i] = (h2[i - 1] * P%mod2 + str[i])%mod2;
    }
    //二分答案
    l1=0,r1=n;
    while(l1<r1){
        int mid=(l1+r1+1)>>1;
        if(check(mid)) l1=mid;
        else r1=mid-1;
    }
    cout<<l1<<endl;
}
int main()
{
        //cinquick();
        //预处理一下p
        p1[0]=p2[0]=1;
        for(int i=1;i<N;i++){
            p1[i]=p1[i-1]*P%mod1;
            p2[i]=p2[i-1]*P%mod2;
        }
        int t;
        cin>>t;
        while(t--) solve();
        return 0;
}