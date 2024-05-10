#include <bits/stdc++.h>
using namespace std;
const int N=10010;
int q[N],ans[N];
int st[N];
int a,b;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
void f()
{
    for(int i=1;i<=N;i++)
    {
        int n=i;
        int sum=0;
        while(n)
        {
            int a=n%10;
            sum+=a*a;
            n/=10;
        }
        q[i]=sum;
    }
}
bool prime(int r)
{
    for(int i=2;i*i<=r;i++)
        if(r%i==0) return false;
    return true;
}
//检查是否有数等于m
bool check(int m)
{
    for(int i=a;i<=b;i++)
    {
        if(q[i]==m) return false;
    }
    return true;
}
int main()
{
        cinquick();
        f();//打表
        
        cin>>a>>b;
        vector<pair<int,int>> num;
        for(int i=a;i<=b;i++)
        {
            int cnt=0;
            fill(st,st+N,0);
            int j;
            for( j=i;j!=1&&!st[j];j=q[j])
            {
                cnt++;
                st[j]=true;  
            }
            if(j==1&&check(i)) num.push_back({i,cnt});
        }
        if(num.empty()) cout<<"SAD"<<endl;
        else
        {
            for(auto x:num)
            {
                int i=x.first,cnt=x.second;
                if(prime(i)) cnt*=2;
                cout<<i<<' '<<cnt<<endl;
            }
        }
        return 0;
}