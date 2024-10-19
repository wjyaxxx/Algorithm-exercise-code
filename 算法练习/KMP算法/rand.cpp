#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int main()
{
    read_fast
    srand(time(0));
    int sz1=rand()%10+1;
    int sz2=rand()%1000+1;
    string s,t;
    //cout<<sz1<<' '<<sz2<<"\n";
    for(int i=1;i<=sz1;i++){
        t+=char((rand()%2)+'a');
    }
    for(int i=1;i<=sz2;i++){
        s+=char((rand()%2)+'a');
    }
    cout<<t<<"\n";
    cout<<s<<"\n";
    return 0;
}