#include <bits/stdc++.h>
using namespace std;

int n,a,b;
typedef long long LL;
LL c(int a){
    return (LL)a*(a-1)/2;
}
void solve()
{
    cin>>n;
    cin>>a>>b;
    int odd=0;//奇数
    int x;
    for(int i=1;i<=n;i++){
        cin>>x;
        odd+=(x&1);
    }
    if(odd==0 || odd==n) {
        cout<<min((n-1)*a,n*(n-1)/2*a)<<"\n";
        return ;
    }
    if(a<=0 && b<=0){
        LL ans=(c(odd)+c(n-odd))*a+(LL)odd*(n-odd)*b;
        cout<<ans<<'\n';
    }
    else if(a<=0){
        LL ans=(c(odd)+c(n-odd))*a+b;
        cout<<ans<<"\n";
    }else if(b<=0){
        LL ans=(LL)odd*(n-odd)*b;
        cout<<ans<<"\n";
    }else{
        int sum;
        if(a>=b) sum=(n-1)*b;
            else sum=(n-2)*a+b;
        cout<<sum<<endl;
    }
}
int main()
{
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int t;
        cin>>t;
        while(t--) solve();
        return 0;
}

