#include <bits/stdc++.h>
using namespace std;
const int N=10010;
int ne[N],h[N],e[N],w[N],idx;
void add(int a,int b,int c)
{
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
int gcd(int x,int y)
{
    return y?gcd(y,x%y):x;
}
int lcm(int x,int y)
{
    return x*(y/gcd(x,y));
}
int dp[3000][3000];
int main()
{
        cinquick();
        for (int i = 1; i <= 2021; i ++ )
        for (int j = 1; j <= 2021; j ++ )
            if (i == j) dp[i][j] = 0;
            else dp[i][j] = 0x3f3f3f3f;

            
        for(int i=1;i<=2021;i++){
            for(int j=1;j<i;j++){
                if(abs(i-j)<=21){
                    int v=lcm(i,j);
                    dp[i][j]=v;
                    dp[j][i]=v;
                }
            }
        }

        // //foldy
        


        for(int i=1;i<=2021;i++)
            for(int j=1;j<=2021;j++)
                for(int k=1;k<=2021;k++)
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);

        cout<<dp[1][2021]<<endl;
        return 0;
}