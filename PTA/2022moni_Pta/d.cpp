#include <bits/stdc++.h>
using namespace std;
const int N=10010;
int  pr[N];
int cnt;
long long ans;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
bool prime(int x)
{
    if(x<2) return false;
    for(int i=2;i*i<=x;i++)
    {
        if(x%i==0) return false;
    }
    return true;
}
int main()
{
        cinquick();
        

        int m,n;
        cin>>m>>n;
        for(int i=m;i<=n;i++)
        {
            if(prime(i)){
                pr[cnt++]=i;
            }
        }
        for(int i=0;i<cnt;i++)
        {
            for(int j=i+1;j<cnt;j++){
                for(int k=j+1;k<cnt;k++)
                {
                    int a,b,c;
                    a=pr[i]*pr[j]+pr[k];
                    b=pr[i]*pr[k]+pr[j];
                    c=pr[k]*pr[j]+pr[i];
        
                    if(prime(a)&&prime(b)&&prime(c)) ans++;
                }
            }
        }
        cout<<ans<<endl;
        return 0;
}