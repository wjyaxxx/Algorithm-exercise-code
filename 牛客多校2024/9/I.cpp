#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
string a,b;
int n;
int main()
{
    read_fast
    cin>>n;
    cin>>a>>b;
    a.insert(0," ");
    b.insert(0," ");
    //前三十位取出来
    string prea=a.substr(1,n/2);
    string sufa=a.substr(n/2+1,n/2);
    string preb=b.substr(1,n/2);
    string sufb=b.substr(n/2+1,n/2);
    
    return 0;
}