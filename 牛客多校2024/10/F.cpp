#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
typedef pair<int,pair<int,int>> PPI;
typedef pair<int,int> PII;
map<PII,int> mp;
vector<PII> s;
int n;
int main()
{
    read_fast
    cin>>n;
    int x,y;
    for(int i=1;i<=n*n;i++){
        cin>>x>>y;
        bool ok=false;
        vector<PII> f;
        for(auto [u,v]:s){
            int dx=x-u,dy=y-v;
            if(!dx) {
                int b=0*y-x
                if(!mp.count({0,1})) f.push_back({0,1});
                else{
                   //if(i==5) cout<<dx<<' '<<dy<<"\n";
                    ok=true;
                    break;
                }
            }
            else if(!dy) {
               if(!mp.count({1,0})) f.push_back({1,0});
               else{
                //if(i==5) cout<<dx<<' '<<dy<<"\n";
                    ok=true;
                    break;
               }
            }
            else{
                
                int d=__gcd(dx,dy);
                dx/=d,dy/=d;
                if(dy<0){
                    dy=-dy;
                    dx=-dx;
                }
                if(!mp.count({dx,dy})) f.push_back({dx,dy});
                else{
                    //if(i==5) cout<<dx<<' '<<dy<<"\n";
                    ok=true;
                    break;
                }
            }
        }
        if(ok){
            //cout<<0;
        }
        else{
            //cout<<1;
            for(auto x:f) mp[x]=1;
            s.push_back({x,y});
        }
    }
    return 0;
}