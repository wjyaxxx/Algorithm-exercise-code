#include <bits/stdc++.h>
using namespace std;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
string a,b;
int main()
{
        cinquick();
        cin>>a>>b;
        if(a.size()==6 || b.size()==6) cout<<-1<<endl;
        else
            cout<<abs((int) a.size() - (int) b.size())+1<<"\n";
        return 0;
}