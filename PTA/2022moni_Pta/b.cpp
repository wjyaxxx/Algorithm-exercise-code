#include <bits/stdc++.h>
using namespace std;
const int N=2*1e6+10;
char str[N];
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
int f(int x)
{
    int res=0;
    while(x)
    {
        res+=x%10;
        x/=10;
    }
    return res;
}
void solve()
{
    cin>>str;
    for(int i=0;str[i];i++)
    {
        if(str[i]>='a'&&str[i]<='z'){
            //cout<<(str[i]-str[i+1])<<endl;
            if(str[i+1]!='\0'&&(str[i]-str[i+1])!=1&&str[i+1]!=(str[i]-32)) {
                //cout<<i<<endl;
                cout<<"N"<<endl;
                return ;
            }
        }
        else if(str[i]>='A'&&str[i]<='Z'){
            if(str[i+1]!='\0'&&(str[i+1]-str[i])!=1&&str[i+1]!=(str[i]+32)){
                //cout<<i<<endl;
                cout<<"N"<<endl;
                return ;
            }
        }
    }
    cout<<"Y"<<endl;

}
int main()
{
        cinquick();
        int t;
        cin>>t;
        while(t--) solve();
        return 0;
}