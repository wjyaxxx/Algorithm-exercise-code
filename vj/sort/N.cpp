#include <bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
string str;
typedef long long LL;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
void solve()
{
    cin>>str;
    str=str+str;
    LL sum=0,res=0;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='1') {
            sum++;
        }
        else if(str[i]=='0'){
            res=max(res,sum);
            sum=0;
        }
    }
    res=max(res,sum);
    if(res==str.size()) cout<<(res/2)*(res/2)<<endl;
    else{
        cout<<(res + 2) / 2 * ((res + 1) / 2)<<endl;
    }
}
int main()
{

        int t;
        cin>>t;
        while(t--) solve();
        return 0;
}