#include <bits/stdc++.h>
using namespace std;
const int N=10010;
int q[N];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>q[i];
    
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            vector<int> ans;
            for(int k=i;k<=j;k++)
            {
                ans.push_back(q[k]);
            }
            sort(ans.begin(),ans.end());
            bool ok=false;
            for(int k=0;k<j-i;k++)
            {
                if(ans[k+1]-ans[k]!=1)
                {
                    ok=true;
                    break;
                }
            }
            if(ok==false){
                cout<<i<<' '<<j<<endl;
                sum++;
            }
        }
    }
    cout<<sum<<endl;
    // int ans=n;
    // for(int i=1;i<=n;i++)
    // {
    //     int mi=q[i],ma=q[i];
    //     for(int j=i+1;j<=n;j++)
    //     {
    //         if(abs(q[j]-mi)==1) ans++;
    //         else if(abs(q[j]-ma)==1) ans++;
    //         else break;
    //         ma=max(ma,q[j]);
    //         mi=min(mi,q[j]);
    //     }
    // }
    // cout<<ans<<endl;
    return 0;
}