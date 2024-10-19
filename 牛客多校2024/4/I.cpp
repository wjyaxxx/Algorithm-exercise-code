#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
typedef long long LL;

int n,m;
const int N=1e6+10;
map<int,int> mp[N];
//时间复杂度没有算清楚,太模板化了，双指针的本质就是移动一个点，另外一个点随这个点移动而移动
int main()
{
    read_fast
    int n,m;
    cin>>n>>m;
    
    int u,v;
    for(int i=1;i<=m;i++){
        cin>>u>>v;
        mp[v][u]=1;
    }

    int ans=0,last=1;
    for(int r=1;r<=n;r++){
        int l=r-1;
        while(l&&mp[r][l]) l--;
        l++;
        last=max(last,l);
        ans+=(r-last+1);
    }
    cout<<ans<<" ";
    return 0;
}