#include <iostream>
#include <cstring>;
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

const int N=3;
char g[N][N];
int st[N][N];
bool check(char c)
{
    int j;
    for(int i = 0; i < N; i++) {
        
        for(j = 0; j < N && g[i][j] == c; j++);
        if(j == N)
                return true;
        for(j = 0; j < N && g[j][i] == c; j++);
        if(j == N)
            return true;
    }
 
    for(j = 0; j < N && g[j][j] == c; j++);
    if(j == N)
        return true;
    for(j = 0; j < N && g[j][N - 1 - j] == c; j++);
    if(j == N)
        return true;
    return false;
}

void solve()
{
    memset(st,0,sizeof st);
    int cnt1=0,cnt2=0;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++){
            cin>>g[i][j];
            if(g[i][j]=='X') cnt1++;
            if(g[i][j]=='O') cnt2++;
        }

    if(cnt1-cnt2>1 || cnt1 <cnt2){
        cout<<"no\n";
        return ;
    }
    if(check('X')&& cnt1!=cnt2+1){
        cout<<"no\n";
        return ;
    }
    if(check('O') && cnt1!=cnt2){
        cout<<"no\n";
        return ;
    }
    cout<<"yes\n";
    return ;
}
int main()
{
    read_fast;
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}