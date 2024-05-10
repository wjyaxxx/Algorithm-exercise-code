#include <bits/stdc++.h>
using namespace std;
const int N=25;
string str[N];
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
bool cmp(string a,string b)
{
    return a+b>b+a;
}
int main()
{
        cinquick();
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>str[i];
        sort(str+1,str+1+n,cmp);
        for(int i=1;i<=n;i++) cout<<str[i];
         return 0;
}