#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int n,m;
char s[510][510];
int main()
{
    read_fast
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>(s[i]+1);
    int x,y,dx,dy;
    for(int i=1;i<=n;i++){
        bool ok=false;
        for(int j=1;j<=m;j++){
            if(s[i][j]=='x'){
                int y=j,x=i;
                while(y<=m && s[i][y]=='x') y++;
                while(x<=n && s[x][j]=='x') x++;
                dx=x-i,dy=y-j;
                ok=true;
                break;
            }
        }
        if(ok) break;
    }
    //cout<<dx<<' '<<dy<<"\n";
    int d=__gcd(dx,dy);
    dx/=d,dy/=d;
    for(int i=1;i<=dx;i++){
        for(int j=1;j<=dy;j++){
            cout<<'x';
        }
        cout<<"\n";
    }
    return 0;
}