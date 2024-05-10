#include <bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int f[N],st[N];
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
void fuc()
{
    for(int i=1;i<=N;i++){
        int x=i,sum=0;
        while(x){
            sum+=(x%10)*(x%10);
            x/=10;
        }
        f[i]=sum;
    }
}
bool prime(int x){
    if(x<=1) return false;
    for(int i=2;i*i<=x;i++)
        if(x%i==0)
            return false;
    return true;
}
int main()
{
        cinquick();
        fuc();
        int a,b;
        cin>>a>>b;
        bool ok=false;
        map<int,int> mp;
        set<int> s;
        for(int i=a;i<=b;i++){
            fill(st,st+N,0);
            int x=i;
            int cnt=0;
            vector<int> res;
            while(!st[x]&&x!=1){
                st[x]=1;
                x=f[x];
                res.push_back(x);
                cnt++;
            }
            if(x==1){
                ok=true;
                mp[i]=cnt;
                for(auto z:res){
                    s.insert(z);
                }
            }
        }
        for(auto x:mp){
            if(s.find(x.first)==s.end()){
                cout<<x.first<<' ';
                if(prime(x.first)) cout<<x.second*2<<endl;
                else cout<<x.second<<endl;
            }
        }
        if(!ok) cout<<"SAD"<<endl;
        return 0;
}