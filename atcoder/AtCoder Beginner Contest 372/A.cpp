#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int main()
{
    read_fast
    string s;
    cin>>s;
    string ns;
    for(auto & x:s){
        if(x!='.') ns+=x;
    }
    cout<<ns<<"\n";
    return 0;
}