#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int n,m;
const int N=1e3+10;
int t[N];
int ed[N];
int main()
{
    read_fast
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>t[i];
        ed[i]=-1e9;
    }
    
    int at,k;
    for(int j=0;j<m;j++){
        cin>>at>>k;
        int x;
        for(int i=1;i<=k;i++){
            cin>>x;
            if(t[x]!=-1&&at-ed[x]<t[x]){
                printf("Don't take %d at %d!\n",x,at);
            }else {
                ed[x]=at;
            }
        }
    }
    return 0;
}