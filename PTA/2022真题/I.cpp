#include <bits/stdc++.h>
using namespace std;
const int N=1100;
int sk[N],tt;//盒子
int a[N];
vector<int> ans[100];
int cnt;
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
        for(int i=1;i<=n;i++) cin>>a[i];
        int i=1;
        while(true){
            if(ans[cnt].size()==k) cnt++;
            if(i>n&&!tt) break;
            
            if(ans[cnt].empty()){
                if(tt){
                    
                    ans[cnt].push_back(sk[tt--]);
                }
                else if(i<=n){
                    ans[cnt].push_back(a[i++]);
                }
            }
            else{
                if(tt&&sk[tt]<=ans[cnt].back()){

                    ans[cnt].push_back(sk[tt--]);
                }
                else if(i<=n&&a[i]<=ans[cnt].back()){
                    ans[cnt].push_back(a[i++]);
                }
                else{
                    if(tt+1<=m&&i<=n){
                        sk[++tt]=a[i++];
                    }
                    else{
                        cnt++;
                    }
                }
            }
        }

        for(int i=0;i<=cnt;i++){
		for(int j=0;j<ans[i].size();j++){
			cout<<ans[i][j];
			if(j!=ans[i].size()-1) cout<<" ";
			else cout<<endl;
		}
        }
        return 0;
}