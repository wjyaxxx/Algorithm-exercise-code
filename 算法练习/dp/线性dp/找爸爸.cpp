#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int book[4][4];
const int N=3010,inf=0x3f3f3f3f;
int dp[3010][3010][3];
char s1[N],s2[N];
int main()
{
    //read_fast
    map<char,int> mp;
    mp['A']=0;
    mp['T']=1;
    mp['G']=2;
    mp['C']=3;
    scanf("%s%s",s1+1,s2+1);
    
    int ls1=strlen(s1+1),ls2=strlen(s2+1);
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            cin>>book[i][j];

    int a,b;
    cin>>a>>b;
    //解决小规模的问题
    dp[0][0][1]=dp[0][0][2]=-inf;
    for(int i=1;i<=ls1;i++){
        dp[i][0][0]=dp[i][0][1]=-inf;
        dp[i][0][2]=-a-b*(i-1);
    }

    for(int i=1;i<=ls2;i++){
        dp[0][i][0]=dp[0][i][2]=-inf;
        dp[0][i][1]=-a-b*(i-1);
    }

    for(int i=1;i<=ls1;i++){
        for(int j=1;j<=ls2;j++){
            int v=book[mp[s1[i]]][mp[s2[j]]];
            dp[i][j][0]=max(dp[i-1][j-1][0],max(dp[i-1][j-1][1],dp[i-1][j-1][2]))+v;
            dp[i][j][1]=max(dp[i][j-1][0]-a,max(dp[i][j-1][1]-b,dp[i][j-1][2]-a));
            dp[i][j][2]=max(dp[i-1][j][0]-a,max(dp[i-1][j][1]-a,dp[i-1][j][2]-b));
        }
    }
    cout<<*max_element(dp[ls1][ls2],dp[ls1][ls2]+3)<<"\n";
    return 0;
}