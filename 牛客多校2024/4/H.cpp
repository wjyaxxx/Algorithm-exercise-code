#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
typedef long long LL;
const int N=1e5+10;
LL res[N];
//该自己造一个样例看一看，不然这样例太垃圾了
//我这个人我一旦发现了什么性质就一直往那想
//这题其实能注意到差值
void solve(){
    int n;
    cin>>n;
   
    if(n==1) cout<<0<<"\n";
    else{
        //LL d=1e16;
        LL maxv=0,minv=1e16;

        for(int i=0;i<n;i++) cin>>res[i],maxv=max(maxv,res[i]),minv=min(minv,res[i]);
        sort(res,res+n);
        int j=upper_bound(res,res+n,(maxv+minv)/2)-res;
        j--;
        //cout<<res[j]<<' '<<minv<<"\n";
        LL d=res[j]-minv;
        cout<<d<<"\n";
    }
}
int main()
{
    read_fast;
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}

