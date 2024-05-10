#include <bits/stdc++.h>
using namespace std;
int ans[7];
int st[7][7];
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
int main()
{
        cinquick();
        for(int i=1;i<=6;i++){
            cin>>ans[i];
            st[i][ans[i]]=1;
        }
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=6;j++){
                for(int v=6;v>0;v--){
                    if(!st[j][v]) {
                        st[j][v]=1;
                        ans[j]=v;
                        break;
                    }
                }
            }
        }
        for(int i=1;i<=6;i++)
            if(i==1) cout<<ans[i];
            else cout<<' '<<ans[i];

        return 0;
}