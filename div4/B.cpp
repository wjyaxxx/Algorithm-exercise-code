#include <bits/stdc++.h>
using namespace std;
char q[100][100];
int n;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
bool check(int x,int y)
{
    int i=x,j=y;
    while(q[i][y]=='1'&&i<n) i++;
    while(q[x][j]=='1'&&j<n) j++;
    int dx=i-x,dy=j-y;
    if(dx==dy) return true;
    return false;
}
void solve()
{
    
    cin>>n;
    for(int i=0;i<n;i++) cin>>q[i];
    bool ok=false;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(q[i][j]=='1')
            {
                ok=true;
                if(check(i,j)) cout<<"SQUARE"<<endl;
                else cout<<"TRIANGLE"<<endl;
                break;
            }
        }
        if(ok) break;
    }
}
int main()
{
        cinquick();
        int t;
        cin>>t;
        while(t--) solve();
        return 0;
}