#include <bits/stdc++.h>
using namespace std;
long long cnt=0;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
void dfs(int u,int a,int b)//第i个人选
{
    if(u>7)
    {
        if(!a&&!b) cnt++;
        return ;
    }

    for(int i=0;i<=a;i++)
    {
        for(int j=0;j<=b;j++)
        {
            if(i+j>=2&&i+j<=5) dfs(u+1,a-i,b-j);
        }
    }
}
int main()
{
        cinquick();
        dfs(1,9,16);
        cout<<cnt<<endl;
        return 0;
}