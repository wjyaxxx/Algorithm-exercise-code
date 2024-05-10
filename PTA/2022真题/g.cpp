#include <bits/stdc++.h>
using namespace std;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
int main()
{
        cinquick();
        int n,m,q;
        cin>>n>>m>>q;
        vector<bool> str(n+1);
        vector<bool> stc(m+1);
        while(q--)
        {
            int op,x;
            cin>>op>>x;
            if(op==0){
                str[x]=1;
            }
            else{
                stc[x]=1;
            }
        }
        int cntr=0,cntc=0;
        for(int i=1;i<=n;i++)
            if(str[i]) cntr++;
        for(int j=1;j<=m;j++)
            if(stc[j]) cntc++;
        cout<<(n-cntr)*(m-cntc)<<endl;
        return 0;
}