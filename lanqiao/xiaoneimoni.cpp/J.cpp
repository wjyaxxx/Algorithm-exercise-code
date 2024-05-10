#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int mod=1000000007;
const int N=1000010;
int n,a,b,c;
int f[N];
int main()
{
        cin>>n>>a>>b>>c;
        f[0]=1;
        for(int i=a;i<b;i++) f[i]=f[i-a];
        for(int i=b;i<=c;i++) f[i]=(f[i-a]%mod+f[i-b]%mod)%mod;

        for(int i=c;i<=n;i++)
        {
            f[i]=((f[i-a]%mod+f[i-b]%mod)%mod+f[i-c]%mod)%mod;
        }
        cout<<f[n]<<endl;
        return 0;
}