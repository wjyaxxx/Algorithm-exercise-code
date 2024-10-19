#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
struct node{
    int a[4]={0};

};

node b;
int main()
{
    int r,c,n;
    cin>>r>>c>>n;
    b.a[3]=4;
    for(auto x:b.a){
        cout<<x<<"\n";
    }
    //上方的少了r
    LL up_de=(LL)(c-1)*c/2+(LL)c*(r-c);
    //下方
    LL down_de=(LL) (r+1-c)*(r+2-c)/2+(LL)(n+c-2*r-1)*(r+1-c);
    
    //总数
    LL cnt=(LL)n*(n+1)*(n+2)/24;
    cout<<cnt<<endl;
    return 0;
}