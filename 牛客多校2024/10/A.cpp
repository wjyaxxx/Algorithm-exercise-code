#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int main()
{
    read_fast
    string s;
    cin>>s;
    int  cnt=0,p=0;
    for(auto x:s){
        if(x=='Y') cnt++;
        else if(x=='-') p++;
    }
    //
    if(cnt>=4){
        cout<<1<<"\n";
    }
    else if(cnt+p<4) cout<<"-1\n";
    else cout<<0<<"\n";
    return 0;
}