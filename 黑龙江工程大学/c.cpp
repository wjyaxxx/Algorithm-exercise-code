#include <bits/stdc++.h>

#define int long long
using namespace std;
int n;
int q[1010];
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
bool prime(long long x)
{
    for(long long i=2;i*i<=x;i++)
        if(x%i==0)
            return false;
    return true;
}
bool check(long long x)
{
    for(int i=1;i<=n;i++)
    {
        if(x%i==0){
        long long res=x/i;
            if(prime(res)) return true;
        }
    }
    return false;
}
void solve()
{
    
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>q[i];
        sum+=q[i];
    }
    for(int i=2;i<=sum;i++)
    {
        if(prime(i))
            res.push_back(i);
    }

    
}
signed main()
{
        cinquick();
        int t;
        cin>>t;
        while(t--) solve();
        return 0;
}