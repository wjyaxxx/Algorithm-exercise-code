#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
void print(vector<int> &a){
    cout<<"[ ";
    for(auto x:a) cout<<x<<' ';
    cout<<"]\n";
}

vector<int> pre,suf;
typedef long long LL;
const int N=1e6+10,P=137,mod=1e9+7,z=998244353;
LL f1[N],f2[N],pw[N];
// void hashval(string s,ULL h[]){
//     p[0]=1;
//     for(int i=1;i<=s.size();i++){
//         h[i]=h[i-1]*P+s[i-1];
//         p[i]=p[i-1]*P;
//     }
// }
// // 计算子串 str[l ~ r] 的哈希值
// ULL get(int l, int r,ULL h[])
// {
//     return h[r] - h[l - 1] * p[r - l + 1];
// }
int main()
{
    read_fast
    
    int slen,tlen;
    cin>>slen>>tlen;
    string s,t;
    cin>>s>>t;
    for(int i=0,j=0;i<tlen;i++){
        while(j<slen && s[j]!=t[i]) j++;
        pre.push_back(j);
        j++;
    }
    for(int i=0,j=slen-1;i<tlen;i++){
        while(j>=0 && s[j]!=t[i]) j--;
        suf.push_back(j);
        j--;
    }
    //print(pre);
    //dp
    
    int l=pre[tlen-1]+1,r=suf[tlen-1]-1,len=r-l+1;
    //cout<<"l= "<<l<<' '<<"r= "<<r<<"\n";
    //cout<<len<<"\n";
   LL  ans=0;
    if(l <= r){
        vector<LL> dp(len+1);
        vector<int> last(26);
        dp[0]=1;
        for(int i=1;i<=len;i++){
            int idx=i+l-1;
            
            // if(!last[s[idx]-'a']){           
            //     dp[i]=(dp[i-1]*2%mod+1)%mod;
            // }
            // else{
            //     dp[i]=(dp[i-1]*2-dp[last[s[idx]-'a']-1])%mod;
            // }
            dp[i]=dp[i - 1] * 2 %mod;
            if(last[s[idx]-'a']) dp[i]=(dp[i]+mod-dp[last[s[idx]-'a']-1])%mod;
            last[s[idx]-'a']=i;
        }
        ans+=dp[len];
        
    }
   //cout<<ans<<"\n";
    //回文字串
   for(int i=pw[0]=1;i<=tlen;i++) pw[i]=pw[i-1]*P%z;
    for(int i=tlen;i;i--){
        f1[i]=(f1[i+1]+t[i-1]*pw[tlen-i])%z;
        f2[i]=(f2[i+1]*P+t[i-1])%z;
    }
    
    for(int i=1;i<=tlen;i++) if(f1[i]==f2[i]){
        if(i>=2 && pre[i-2]<suf[tlen-1]) ans=(ans+1)%mod;
        else if(i==1 && suf[tlen-1]>-1) ans=(ans+1)%mod;
    }
    
    cout<<ans%mod<<"\n";
    return 0;
}
