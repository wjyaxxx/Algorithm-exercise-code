#include <bits/stdc++.h>
using namespace std;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
int main()
{
        cinquick();
        string s;
        cin>>s;
        int szs=s.size();
        int n;
        cin>>n;
        while(n--)
        {
            int st,ed;
            string a,b;
            cin>>st>>ed>>a>>b;
            string c=a+b;
            int sz=a.size();
            string x=s.substr(st-1,ed-st+1);
            s.erase(st-1,ed-st+1);
            auto p=s.find(c);
            if(p!=-1)
            {
                s.insert(p+sz,x);
            }
            else 
            {
                int szs=s.size();
                s.insert(szs,x);
            }
        }
        cout<<s<<endl;
        return 0;
}