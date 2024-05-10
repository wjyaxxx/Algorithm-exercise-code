#include <bits/stdc++.h>
using namespace std;
int k,n;
const int N=110,N1=1e5+5;
int p[N],b[N],ans[N1];//p表示质数，b表示第i个数乘到了哪里，ans表示答案
int main()
{
    cin>>k>>n;
    for(int i=1;i<=k;i++) cin>>p[i];
    ans[0]=1;
   for(int i=1;i<=n;i++)
   {
       int res=INT_MAX;
       for(int j=0;j<i;j++)
       {
           for(int c=1;c<=k;c++)
           {
               if(p[c]*ans[j]>ans[i-1]){
                    res=min(res,p[c]*ans[j]);
               }
           }
       }
       cout<<res<<endl;
       ans[i]=res;
   }
   cout<<ans[n]<<endl;
    return 0;
}