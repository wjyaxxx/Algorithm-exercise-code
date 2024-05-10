#include <bits/stdc++.h>
using namespace std;
const int N=100010;
int sk[N],tt,q[N];
int n,m,k;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
int main()
{
        cinquick();
        cin>>n>>m>>k;
        for(int i=1;i<=k;i++){
            for(int j=1;j<=n;j++) cin>>q[j];
            int idx=1;
            bool ok=false;
            vector<int> ans;
            ans.push_back(0);
            while(1){
                if(idx>n) break;
                
                if(tt&&sk[tt]==ans.back()+1){
                    ans.push_back(sk[tt--]);
                }
                else if(idx<=n&&q[idx]==ans.back()+1){
                    ans.push_back(q[idx++]);
                }
                else{
                    if(tt>=m){
                        ok=true;
                        break;
                    }
                    else sk[++tt]=q[idx++];
                }

            }

        while(tt&&sk[tt]==ans.back()+1) ans.push_back(sk[tt--]);
        if(tt) ok=true;
        if(ok) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
        tt=0;
    }
    
        return 0;
}