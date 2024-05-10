#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int N=1010;
char str[N];
int n,m;

void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}

vector<int> add(vector<int>&a,vector<int>&b,string pta)
{
    vector<int> c;

    int sz=max(a.size(),b.size());
    int t=0;
    for(int i=0;i<sz;i++)
    {
        int v=(pta[i]-'0');
        if(v==0) v=10;
        if(i<a.size()) t+=a[i];
        if(i<b.size()) t+=b[i];
        c.push_back(t%v);
        t/=v; 
    }
    int v=(pta[sz]-'0');
    if(t) 
        c.push_back(t%v),t/=v;
    if(t) c.push_back(t);

    while(c.back()==0&&c.size()>1) c.pop_back();
    return c;
}
bool prime(int x)
{
    if(x==0) return false;
    if(x==1) return false;
    if(x==2) return true;
    for(int i=2;i*i<=x;i++)
        if(x%i==0)
            return false;
    return true;
}
bool check(int i)
{
    int res=0;
    for(int j=i;j<i+m;j++)
        res=res*10+(str[j]-'0');
        //cout<<res<<endl;
    return prime(res);
}
vector<int> div(vector<int> &a,int &b,int&r)
{
    vector<int> c;
    r=0;
    for(int i=a.size()-1;i>=0;i--)
    {
        r=r*10+a[i];
        c.push_back(r/b);
        r%=b;
    }
    reverse(c.begin(),c.end());
    while(c.back()==0&&c.size()>1) c.pop_back();
    reverse(c.begin(),c.end());
    return c;
}
signed main()
{ 
        cinquick();
       
       cin>>n>>m;
       
       cin>>str;
       for(int i=0;i+m<=n;i++)
       {
            if(check(i))
            {
                for(int j=i;j<i+m;j++)
                    cout<<str[j];
                    return 0;
            }
       }
        cout<<"404"<<endl;
        return 0;
}