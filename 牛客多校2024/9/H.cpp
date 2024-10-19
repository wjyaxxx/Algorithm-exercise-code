#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int n,x,y;
int main()
{
    read_fast
    cin>>n>>x>>y;
    string s;
    cin>>s;
    //0 为上下方向(y)，1为左右方向(x)
    vector<array<int,2>> a(n+1,{0,0});
    
    for(int i=1;i<=n;i++){
        a[i]=a[i-1];
        if(s[i-1]=='W') a[i][0]++;
        else if(s[i-1]=='S') a[i][0]--;
        else if(s[i-1]=='D') a[i][1]++;
        else a[i][1]--;
        //cerr<<a[i][0]<<' '<<a[i][1]<<"\n";
    }
    //cout<<a[5][0]-a[3][0]<<' '<<a[5][1]-a[3][1]<<"\n";
    map<array<int,2>,int> mp;
    long long ans=0;
    //遍历l
    for(int i=n;i>=0;i--){
        mp[a[i]]=i;
        if(mp.count({a[i][0]+y,a[i][1]+x})){
            int r=mp[{a[i][0]+y,a[i][1]+x}];
            r=max(r,i+1);
            ans+=(n-r+1);
        }
    }
    cout<<ans<<"\n";
    return 0;
}