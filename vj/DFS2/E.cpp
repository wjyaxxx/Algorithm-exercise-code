#include <bits/stdc++.h>
using namespace std;
const int N=50;
int n,g;
int min=0;
bool st[N];
int a[N][N];
int m[N],h[N];
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}

int main()
{
        cinquick();
        cin>>n;
        
        for(int i=0;i<n;i++) cin>>m[i];

        
        cin>>g;
        for(int i=1;i<=g;i++)
        {
            for(int j=0;j<n;j++) cin>>a[i][j];
        }
        
        dfs(1,0);
        
        return 0;
}