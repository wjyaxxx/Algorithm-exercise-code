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
        int n;
        while(cin>>n&&n){
            set<string> loser,all;
            for(int i=1;i<=n;i++){
                string a,b;
                cin>>a>>b;
                all.insert(a);
                all.insert(b);
                loser.insert(b);
            }
            if(all.size()-loser.size()==1) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
        return 0;
}