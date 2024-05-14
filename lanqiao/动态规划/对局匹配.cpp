#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

//分组动规
//因为相差一个固定值k
//所以可以将给的数分成k组,每一个组的人是,发现每个组是相互独立的，则在每个组之间 不选相邻元素就行
const int N=1e5+10;
int cnt[N];
int n,k,maxv,ans;
int main()
{
    cin>>n>>k;
    int x;
    for(int i=1;i<=n;i++){
      scanf("%d",&x);
      cnt[x]++;
      maxv=max(maxv,x);
    }
    if(!k){
        for(int i=0;i<=N;i++) ans+=(cnt[i]!=0);
        cout<<ans<<endl;
        return 0;
    }
    for(int i=0;i<k;i++){
        vector<int> val;
        
        for(int j=i;j<=maxv;j+=k) val.push_back(cnt[j]);
        int sz=val.size();
        
        vector<int> dp(sz,0);//选到第i个人时，它能选择的方案数
        dp[0]=val[0];
        dp[1]=max(val[0],val[1]);
        for(int j=2;j<sz;j++){
           dp[j]=max(dp[j],dp[j-1]);
           if(j-2>=0) dp[j]=max(dp[j],dp[j-2]+val[j]);
        }

        
        ans+=dp[sz-1];
    }
    cout<<ans<<endl;
  return 0;
}