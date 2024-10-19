#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using vi=vector<int>;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vi> ma(n+1,vi(11));
    int a,d,k;
    for(int i=1;i<=m;i++){
        cin>>a>>d>>k;
        ma[a][d]=max(ma[a][d],k);
    }
    vector<int> p(n+1);
    for(int i=1;i<=n;i++) p[i]=i;
    auto find=[&p](auto self,int x)->int{
        if(x!=p[x]) p[x]=self(self,p[x]);
        return p[x];  
    };
    //从前往后更新即可
    for(int i=1;i<=n;i++){
        for(int j=0;j<=10;j++){
            if(ma[i][j] && i+j<=n){
                //说明可以跳
                p[find(find,i)]=find(find,i+j);
                //cout<<i<<' '<<i+j<<"\n";
                //将次数传递给后面
                ma[i+j][j]=max(ma[i+j][j],ma[i][j]-1);
            }
        }
    }

    set<int> s;
    for(int i=1;i<=n;i++){
        s.insert(find(find,i));
    }
    cout<<s.size()<<"\n";
}
int main()
{
    read_fast;
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}