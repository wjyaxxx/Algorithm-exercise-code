#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}

unordered_map<LL,pair<int,int>> num;
int q[1010];
int n;
int main()
{
        cinquick();
        cin>>n;
        for(int i=1;i<=n;i++) cin>>q[i];
        for(int i=1;i<=n;i++) {
            for(int j=i+1;j<=n;j++){
                num[q[i]+q[j]]={i,j};
            }
        }

        //i<j
        //a<b
        bool ok=false;
        for(int a=1;a<=n;a++){
            for(int b=a+1;b<=n;b++){
                int res=q[a]+q[b];
                if(num.find(-res)!=num.end()){
                    int c=num[-res].first;
                    int d=num[-res].second;
                    if(c!=a&&c!=b&&d!=a&&d!=b){
                        
                        ok=true;
                        break;
                    }
                }
            }
        }
        if(ok) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
        return 0;
}