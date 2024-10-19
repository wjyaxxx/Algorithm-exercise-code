#include <bits/stdc++.h>
using namespace std;
int n;
string str;
int main()
{
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin>>n>>str;
        
        int cnt=0;
        for(auto x:str){
            cnt+=(x=='0');
        }
        if(n==cnt||cnt==0){
            cout<<0;
            return 0;
        }
        if(2*cnt!=int(str.size())) cout<<1;
        else{
            if((int) str.size()==2) cout<<-1;
            else cout<<2;
        }
        return 0;
}