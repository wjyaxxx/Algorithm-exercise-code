#include <cstdio>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int N=1010;
char a[N][N];
long long ans,res;
int n,m;
bool exc(int i,int j)
{
    if(i<0||i>=n) return false;
    if(j<0||j>=m) return false;
    return true;
}
int check(int i,int j)
{
    int x1=i,y1=j;
    int x2=i,y2=j;
    int x3=i,y3=j;
    int sep=0;
    while(exc(x1,y1)&&exc(x2,y2)&&exc(x3,y3)&&a[x1][y1]==a[i][j]&&a[x1][y1]==a[x2][y2]&&a[x2][y2]==a[x3][y3])
    {
        x1--,y1--;
        x2--,y2++;
        x3++;
        sep++;
    }
    return sep-1;
}
int main()
{
      
      cin>>n>>m;
      for(int i=0;i<n;i++) scanf("%s",a[i]);

      for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            res=check(i,j);
            ans=max(res,ans);
        }
        cout<<ans<<endl;
        return 0;
}