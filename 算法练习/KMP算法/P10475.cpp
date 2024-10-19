#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const int N=10010;
char str[N][80];
int n,m;
int main()
{
    read_fast
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>str[i][j];
    int res1=0;
    for(int j=0;j<n;j++){
        vector<int> pi(m);
        for(int i=1;i<m;i++){
            int len=pi[i-1];
            while(len && str[j][i]!=str[j][len]) len=pi[len-1];
            if(str[j][i]==str[j][len]) pi[i]=len+1;
        }
        res1=max(res1,m-pi[m-1]);
    }
    int res2=0;
    for(int j=0;j<m;j++){
        vector<int> f(n);
        for(int i=1;i<n;i++){
            int len=f[i-1];
            while(len && str[i][j]!=str[len][j]) len=f[len-1];
            if(str[i][j]==str[len][j]) f[i]=len+1;
        }
        res2=max(res2,(n-f[n-1]));
    }
    cout<<(long long)res1*res2<<"\n";
    return 0;
}