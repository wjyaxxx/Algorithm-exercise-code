#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
typedef long long ll;
const int N=200;
ll f[N];

int main()
{
    //read_fast
    memset(f,-1,sizeof f);
    f[0]=1;
    int i;
    for( i=1;i<N && f[i-1]*(ll)i<=6227020800;i++) f[i]=f[i-1]*i;
    
    int n;
    while(cin>>n){
        if(n>=200){
            cout<<"Overflow!\n";
            continue;
        }
        if(n<0 && ((-n)&1)){
            cout<<"Overflow!\n";
            continue;
        }
        if(n<0 && ((-n)&1)==0){
            cout<<"Underflow!\n";
            continue;
        }
        if(f[n]<10000 && f[n]!=-1) cout<<"Underflow!\n";
        else if(f[n]==-1) cout<<"Overflow!\n";
        else cout<<f[n]<<"\n";
    }
    return 0;
}