#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const int N=3e5+10;
int f[N];
int main()
{
    read_fast
    int m,s,t;
    cin>>m>>s>>t;
    int s1=0;
    for(int i=1;i<=t;i++){
        if(m>=10){
            f[i]=f[i-1]+60;
            m-=10;
        }else{
            f[i]=f[i-1];
            m+=4;
        }
    }
    
    for(int i=1;i<=t;i++){
        //这个时刻一定在两个闪现之间，即后程才为走路
        if(f[i]<f[i-1]+17){
            f[i]=f[i-1]+17;
        }
        if(f[i]>=s){
            cout<<"Yes\n";
            cout<<i<<"\n";
            return 0;
        }
    }
    cout<<"No\n";
    cout<<f[t]<<"\n";
    

    return 0;
}