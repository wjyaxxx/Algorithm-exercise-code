#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int n,m;
priority_queue<int> q;
int main()
{
    read_fast
    cin>>n>>m;
   
    int x,maxv=0;
    for(int i=1;i<=n;i++){
        cin>>x;
        q.push(x);
        maxv=max(maxv,x);
    }
    if(m==1){
         cout<<maxv<<"\n";
         return 0;
    }
    int ans=maxv;
    int cnt=0;
    while(q.size()){
        //cout<<cnt+q.top()<<"\n";
       int t=q.top();
       q.pop();
       t/=m;
       if(t) q.push(t);
       cnt++;
        if(!q.empty() && cnt+q.top()<=ans){
            ans=cnt+q.top();
       }
    }
    cout<<ans<<"\n";
    return 0;
}