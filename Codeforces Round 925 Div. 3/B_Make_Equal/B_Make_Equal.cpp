#include <bits/stdc++.h>
using namespace std;
const int N=200010;
int a[N];
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
void solve(){
    int n;
    cin>>n;
    int sum=0;
    for(int i=0;i<n;i++){
         cin>>a[i];
         sum+=a[i];
    }
    int avg=sum/n;

    for(int i=0;i<n;i++) a[i]-=avg;
    int sum1=0,sum2=0;
    for(int i=0,j=0;i<n;i++)
    {
        if(a[i]<0)
        {
            sum2+=a[i];
            while(j<i) {
                sum1+=a[j];
                j++;
            }
            if(sum1+sum2<0)
            {
                cout<<"NO"<<endl;
                return ;
            }
            j=i+1;
        }
    }

    cout<<"YES"<<endl;
    
}
int main()
{
        cinquick();
        int t;
        cin>>t;
        while(t--) solve();
        return 0;
}