#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using pii=pair<int,int>;
using ll=long long;
const int N=1e5+10;
int f[N][30];
ll w[N][30];
int main()
{
	
    read_fast
    int n,m;
    cin>>n>>m;
    vector<array<int,2>> a(n+2);
    for(int i=1;i<=n;i++){
        cin>>a[i][0]>>a[i][1];
    } 
    stack<int> sk;
    vector<int> r(n+1,n+1);
    for(int i=1;i<=n;i++){
        while(!sk.empty() && a[sk.top()][0]<a[i][0]){
            r[sk.top()]=i;
            sk.pop(); 
        }
        
        sk.push(i);
    }
    //for(int i=1;i<=n;i++) cout<<r[i]<<' ';
    for(int i=1;i<=n;i++) {
        f[i][0]=r[i];
        if(r[i]==n+1){
            w[i][0]=1e9;//表示直接跳到水池
        }else{
            w[i][0]=a[r[i]][1];
        }
    }
        
    
        for(int j=1;j<30;j++)
         for(int i=1;i<=n;i++){
            if(f[i][j-1]<=n){
                f[i][j]=f[f[i][j-1]][j-1];
                w[i][j]=w[i][j-1]+w[f[i][j-1]][j-1];
            }
            else {
                f[i][j]=n+1;
                w[i][j]=w[i][j-1]+w[f[i][j-1]][j-1];
            }
        }
    
    int st,v;
    
    while(m--){
        cin>>st>>v;
        int u=st;
        v-=a[st][1];
        if(v<=0) {
            cout<<u<<"\n";
            continue;
        }
        for(int i=29;i>=0;i--){
            if(v>=w[u][i]){
                //cerr<<v<<' '<<u<<' '<<w[u][i]<<"\n";
                v-=w[u][i];
                u=f[u][i];
            }
        }
        if(v==0) {
            cout<<u<<"\n";
            continue;
        }
        if(f[u][0]!=n+1)
        cout<<f[u][0]<<"\n";
        else cout<<0<<"\n";
    }

    return 0;
}



