#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int n;
string s;
const int N=1e6+10;
int pi[N];
int main()
{
    read_fast
    cin>>n>>s;
    //初始值，一个数字肯定是只有一个前缀函数
    for(int i=1;i<n;i++){
        int len=pi[i-1];//到第i-1时的最长公共子串的长度
        while(len>0 &&s[i]!=s[len]) len=pi[len-1];
        if(s[i]==s[len]) pi[i]=len+1;
    }
    cout<<n-pi[n-1]<<"\n";
    return 0;
}