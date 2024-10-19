#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int main()
{
    read_fast
    int a,b;
    cin>>a>>b;
    set<int> s;
    s.insert(2*a-b);
    s.insert(2*b-a);
    if(((a+b)&1)==0)
    s.insert((a+b)/2);
    cout<<s.size()<<"\n";
    return 0;
}