#include <bits/stdc++.h>
using namespace std;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
/*
    dp[i][j]表示在s的前i个中是否包含t的前j个字符
    
    第i个字符不是j
    dp[i][j]|=dp[i-1][j]

    第i个字符是j

    dp[i][j]=true
*/
string s,t;
int ans;
int main()
{
        cinquick();
        cin>>s>>t;
        int j=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==t[j]){

                ans++;
                j++;
            }
        }
        cout<<ans<<endl;
        return 0;
}