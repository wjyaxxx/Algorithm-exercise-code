#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

const int  maxn = 5010;
typedef long long LL;
LL mod;
LL c[maxn][maxn];
LL qmi(LL a, LL k, LL p)
{
    LL res = 1;
    while (k)
    {
        if (k & 1) res = (LL)res * a % p;
        a = (LL)a * a % p;
        k >>= 1;
    }
    return res;
}
                                                        


int main()
{
    read_fast
    LL  n,m,q;
    cin>>n>>m>>q;
    mod=q;
    c[0][0]=1;
    
   for(int i = 0; i <maxn; i ++ )
        for(int j = 0; j <= i; j ++ )
            if(!j)  c[i][j] = 1;
            else    c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % q;

    
    LL ans=0;
   
    for(int k=1;k<=n;k++){
        LL res=c[n][k]*qmi(2,(n-k)*(m-1),q)%q;
        LL z=qmi(2,k,q);
        res=(res*qmi(z-1,m-1,q))%q;
        ans=(ans+res)%q;  
    }    
    cout<<ans<<"\n";
    
    return 0;
}
