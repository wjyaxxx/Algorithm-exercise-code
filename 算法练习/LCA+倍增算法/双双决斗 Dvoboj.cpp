#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const int N=2*1e5+10;
int n,m;
int f[N][10];
int dfs(int l,int k){
    if(k<=8){
        return f[l][k];
    }

    return abs(dfs(l,k-1)-dfs(l+(1<<(k-1)),k-1));
}
int main()
{
    read_fast
    cin>>n>>m;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        f[i][0]=a[i];
    }
    for(int j=1;j<=8;j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            f[i][j]=abs(f[i][j-1]-f[i+(1<<(j-1))][j-1]);
        }
    }

    int op;
    while(m--){
        cin>>op;
        if(op==2){
            int l,k;
            cin>>l>>k;
            cout<<dfs(l,k)<<"\n";

        }else{
            int id,v;
            cin>>id>>v;
            //暴力修改，分块求解
            f[id][0]=v;
            for(int j=1;j<=8;j++){
                for(int i=max(1,id-256);i+(1<<j)-1<=n && i<=id;i++){
                    f[i][j]=abs(f[i][j-1]-f[i+(1<<(j-1))][j-1]);
                }
            }
        }
    }    
    return 0;
}