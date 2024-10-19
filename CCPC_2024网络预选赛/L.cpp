#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const int N=510;
char s[N][N];
int main()
{
    read_fast
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>s[i][j];

    int cnt=0;
    for(int i=1;i+1<=n;i++)
        for(int j=1;j+1<=m;j++){
            if(s[i][j]=='c' && s[i+1][j]=='p' && s[i][j+1]=='c' && s[i+1][j+1]=='c') cnt++;
        }

    cout<<cnt<<"\n";
    return 0;
}