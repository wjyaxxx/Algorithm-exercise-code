#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
void solve()
{
    vector<int> a(33);
    for(int i=1;i<=32;i++) cin>>a[i];
    int x=a[1];
    sort(a.begin()+1,a.end(),greater<int>());
    int id=1;
    while(a[id]!=x) id++;
    

    
    
    
    if(id==1){
        cout<<1<<"\n";
        return ;
    }
    if(id<=(32-27)){
        cout<<2<<"\n";
        return ;
    }
    if(id<=(32-13)){
        cout<<4<<"\n";
        return ;
    }
    if(id<=(32-6)){
        cout<<8<<"\n";
        return ;
    }
    if(id<=(32-2)) {
        cout<<16<<"\n";
        return ;
    }
    cout<<32<<"\n";
    
}
int main()
{
    read_fast;
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}