#include <bits/stdc++.h>
using namespace std;
const int N=100;
int a[N];
int n,A;
int main()
{
        ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
       cin>>n>>A;
       for(int i=1;i<=n;i++) cin>>a[i];
       
       sort(a+1,a+1+n);
        int last=-1;
       for(int i=1;i<=n;i++){
            if(last==-1){
                cout<<a[i]+A<<"\n";
                last=a[i]+A;
            }else{
                cout<<max(last,a[i])+A<<"\n";
                last=max(last,a[i])+A;
            }
       }
        return 0;
}