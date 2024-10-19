#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n;
const int N=1e7;
int prime[N],cnt;
bool st[N];

void get_prime(int n){
    for(int i=2;i<=n;i++){
        if(!st[i]) prime[cnt++]=i;
        for(int j=0;prime[j]<=n/i;j++){
            st[prime[j]*i]=true;
            if(i%prime[j]==0) break;
        }
    }
}
int main()
{
        
        cin>>n;
        get_prime(n);
        printf("f(%d)=",n);
        for(int j=0;j<cnt;j++){
            int p=prime[j];
            LL sum=0;
            for(LL d=p;d<=n;d*=p){
                int st=n+1-d;
                int ed=n+1-n/d*d;
                sum+=(LL)(st+ed)*(n/d)/2;
            }
            if(sum==1) printf("%d",p);
            else printf("%d^%lld",p,sum);
            if(j==cnt-1) printf("\n");
            else printf("*");
        }
        return 0;
}