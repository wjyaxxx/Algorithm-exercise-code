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
        unordered_map<string,string>mp;
        string a,b;
        for(int i=1;i<=3;i++)
        {
            cin>>a>>b;
            mp[b]=a;
        }

        int n;
        cin>>n;
        while(n--)
        {
            string str;
            cin>>str;
            if(mp.find(str)==mp.end()) cout<<"Fake"<<endl;
            else cout<<mp[str]<<endl;
        }
        return 0;
}