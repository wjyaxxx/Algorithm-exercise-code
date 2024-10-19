#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//dp[i]表示到第i个位置时最长的前缀长度
/*
    状态转移、
    
    dp[i+s[k].size()]=max(dp[i],dp[i]+s[k].size())

    最好快速判断s[k]==p[i---i+s[k].size()](字符串哈希加速一下)


*/
const int N=2*1e5+10;
int dp[N];
vector<string> s;
string p="#";
int main()
{
    read_fast
    string x;
    while(cin>>x){
        if(x==".") break;
        s.push_back(x);
    }
    while(cin>>x){
        p+=x;
    }
    
    int n=p.size();
    dp[0]=-1;
    for(int i=0;i<n;i++){
        for(int k=0;k<s.size();k++){
            int len=s[k].size();
            if(i+len<n && p.substr(i+1,len)==s[k] &&(dp[i]>0 ||dp[i]==-1) ){ 
                if(dp[i]==-1) dp[i]=0;
                dp[i+len]=max(dp[i+len],max(dp[i],dp[i]+len));
                // if(i+len==7) cout<<dp[7]<<"\n";
                // if(i==5 && s[k]=="CA") cout<<i+len<<' '<<dp[i+len]<<"\n";
            }
        }
    }    
    
    int  ans=0;
    for(int i=1;i<n;i++) {
        ans=max(ans,dp[i]);
    }
    cout<<ans<<"\n"; 
    return 0;
}