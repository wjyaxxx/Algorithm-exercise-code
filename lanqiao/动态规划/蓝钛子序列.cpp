#include <bits/stdc++.h>
using namespace std;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
typedef unsigned long long ULL;
string a,b;
const int P=13331;
vector<ULL> get_hash(string s)
{
    int n=s.size();
    vector<ULL> h(n+1);
    vector<ULL> p(n+1);
    p[0] = 1;
    for (int i = 1; i <= n; i ++ )
    {
        h[i] = h[i - 1] * P + s[i-1];
        p[i] = p[i - 1] * P;
    }
    vector<ULL> q; 
    for(int i=0;i<n;i++){
        if(s[i]>='A'&&s[i]<='Z'){
            int j=i+1;
            while(s[j]<='z'&&s[j]>='a'&&j<n) j++;
            j--;
            ULL val=h[j+1]-h[i]*p[j-i+1];
            q.push_back(val);
            i=j;
        }
    }
    return q;
}
int dp[1100][1100];
int main()
{
        cinquick();
        cin>>a>>b;
        auto A=get_hash(a);
        auto B=get_hash(b);
        
        //动态规划了
        for(int i=1;i<=A.size();i++){
            for(int j=1;j<=B.size();j++){
                if(A[i-1]==B[j-1]) {
                    dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
                    
                }
                dp[i][j]=max(dp[i][j],max(dp[i-1][j],dp[i][j-1]));
            } 
        }
        cout<<dp[A.size()][B.size()]<<endl;
        return 0;
}