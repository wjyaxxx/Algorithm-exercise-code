#include <bits/stdc++.h>
using namespace std;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
//让一个数尽可能的多的1，且不超过k即可

void solve()
{
    int n,k;
    cin>>n>>k;
    
    if(n==1) cout<<k<<endl;
    else{
        int cpy=k;
        vector<int> arr(n,0);
        int maxid;
        for(int i=0;i<31;i++){
            if((cpy>>i)&1){
                maxid=i;
            }
        }

        arr[0]=(1<<maxid)-1;
        arr[1]=k-arr[0];

        for(auto x:arr) cout<<x<<' ';
        cout<<endl;
    }
}
int main()
{
        cinquick();
        int t;
        cin>>t;
        while(t--) solve();
        return 0;
}