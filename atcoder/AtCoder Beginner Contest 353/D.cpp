#include <bits/stdc++.h>
using namespace std;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
typedef long long LL;
const int N=2*1e5+10,mod=998244353;
LL q[N],k[N],sum1[N],sum2[N];
int n;
int f(int x)
{
    int res=0;
    while(x){
        res++;
        x/=10;
    }
    return res;
}

int main()
{
        cinquick();
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>q[i];
            int kn=f(q[i]);
            int res=1;
            for(int j=1;j<=kn;j++){
                res=res*10%mod;
            }
            k[i]=res;
            
            k[i]=(k[i-1]+k[i])%mod;
            sum1[i]=(sum1[i-1]+q[i]*(i-1)%mod)%mod;
        }
        
        for(int i=1;i<=n;i++){
            sum2[i]=(q[i]*((k[n]-k[i]+mod)%mod)%mod+sum2[i-1])%mod;
        }
        
        
        cout<<(sum1[n]+sum2[n])%mod<<endl;
        return 0;
}