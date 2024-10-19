#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n;
const int N=1e7;
int prime[N],cnt;
bool st[N];
int minp[N];
void get_prime(int n){
    for(int i=2;i<=n;i++){
        if(!st[i]) {
            prime[cnt++]=i;
            minp[i]=i;
        }
        for(int j=0;prime[j]<=n/i;j++){
            st[prime[j]*i]=true;
            minp[prime[j]*i]=prime[j];
            if(i%prime[j]==0) break;
        }
    }
}

int main()
{
        
        cin>>n;
        get_prime(n);
        
        printf("f(%d)=",n);
        vector<LL> f(n+1,1);
        for(int i=2;i<=n;i++){
            f[i]=(n+1-i);
            
        }
        for(int i=n;i>=2;i--){
            if(i==minp[i]) continue;
            f[minp[i]]+=f[i];
            f[i/minp[i]]+=f[i];
        }
        for(int j=0;j<cnt;j++){
            int p=prime[j];
            LL sum=f[prime[j]];
            if(sum==1) printf("%d",p);
            else printf("%d^%lld",p,sum);
            if(j==cnt-1) printf("\n");
            else printf("*");
        }
        return 0;
}