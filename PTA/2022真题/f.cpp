#include <bits/stdc++.h>
using namespace std;
 string a,b;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
string f(string a)
{
    string res="";
    for (int i = 1; i <a.size(); i++) {
    if (((a[i]-'0')% 2) == ((a[i-1]-'0') % 2)) {
        res+= max(a[i], a[i-1]);
        }
    }
    return res;
}
int main()
{
        cinquick();
       cin>>a>>b;
       a=f(a);
       b=f(b);
       if(a==b){
        cout<<a<<endl;
       }
       else{
        cout<<a<<endl<<b<<endl;
       }
        return 0;
}