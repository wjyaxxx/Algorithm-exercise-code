#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9+7;
long long int qow( long long int a, long long int b ) {
    long long int ans = 1;
    while( b ) {
        if( b&1 ) {
            ans = ans*a%mod;
        }
        a = a*a%mod;
        b /= 2;
    }
    return ans;
}
int main()
{
    int m,x=1,sum=1,k,p;
    long long int n;
    string str;
    int i,j;
    cin>>n>>k>>p;
    if( k == 1 ) 
            cout << (n-1)*n/2*p+n << endl;
    else {
            long long int ans=(1+p*qow(k-1,mod-2)%mod)%mod*((qow(k,n)-1+mod)%mod)%mod*qow(k-1,mod-2)%mod;
            ans=(ans-p*qow(k-1,mod-2)%mod*n%mod+mod)%mod;
            cout << ans << endl;
        }
    return 0;
}