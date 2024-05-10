#include <bits/stdc++.h>
using namespace std;
const int N=1000010;
bool st[N];
long long res;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
bool prime(int x)
{
    for(int i=2;i*i<=x;i++)
        if(x%i==0)
            return false;
    return true;
}
int f(int x)
{
    int sum=0;
    while(x)
    {
        sum+=x%10;
        x/=10;
    }
    return sum;
}
int main()
{
        cinquick();
        
        st[3]=true;
        for(int i=4;i<=N;i++)
        {
            if(prime(i)) st[i]=true;
        }
      
        for(int i=1;i<=1000000;i++)
        {
            if(st[i]&&f(i)==23) res++;
        }
        cout<<res<<endl;
        return 0;
}