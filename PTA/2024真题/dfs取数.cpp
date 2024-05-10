#include <bits/stdc++.h>
using namespace std;
int col[5],row[5];
int l,n;
int ans;
void dfs(int x,int y)
{
    if(y>=n+1){
        y=1;
        x++;
    }
    if(x>=n+1){
        
        for(int j=1;j<=n;j++) 
            if(col[j]!=l||row[j]!=l)
                return ;
        ans++;
        return;
    }
    for(int i=0;i<=l;i++)
    {
        col[y]+=i;
        row[x]+=i;
        dfs(x,y+1);
        col[y]-=i;
        row[x]-=i;
    }
}
int  main()
{
    cin>>l>>n;
    dfs(1,1);
    cout<<ans<<endl;
    return 0;
}