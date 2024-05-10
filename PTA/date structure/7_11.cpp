#include <bits/stdc++.h>
using namespace std;
const int N=100010;
int q[N];
int sk[N];
int n,s,tt;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
int main()
{
        cinquick();
        cin>>n>>s;
        for(int i=1;i<=n;i++) cin>>q[i];

        map<int,int> a;
        
        for(int i=1;i<=n;i++) cin>>sk[i];

        for(int i=1;i<=n/s;i++)
        {
            for(int j=1;j<=s;j++)
            {

                a[q[j+(i-1)*s]]=sk[(s-j+1)+(i-1)*s];
            }
        }

        int k;
        cin>>k;
        while(k--)
        {
            int x;
            cin>>x;
            if(a.find(x)!=a.end())
            {
                cout<<a[x]<<endl;
            }
            else cout<<"Wrong Number"<<endl;
        }
        return 0;
}