#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int n;
const int N=1010;
int st[N][N];
bool check(int x,int y){
    return (x>0 && x<=n && y>0 && y<=n);
}
int main()
{
    read_fast
    cin>>n;
    int x,y;
    vector<array<int,2>> s;
    for(int i=1;i<=n*n;i++){
        cin>>x>>y;
        if(st[x][y]) {
            cout<<0;
            continue;
        }
        cout<<1; 
        for(auto [u,v]:s){
            int dx=x-u,dy=y-v;
            int d=__gcd(dx,dy);
            dx/=d,dy/=d;
            int k=x,j=y;
            while(check(k,j)){
                st[k][j]=1;
                k+=dx;
                j+=dy;   
            }
            k=x,j=y;
            while(check(k,j)){
                st[k][j]=1;
                k-=dx;
                j-=dy;
            }
        }
        s.push_back({x,y});
    }
    return 0;
}