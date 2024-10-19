#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
struct node
{
    char name[50];
    int cnt,t;
    bool operator<(node a){
        if(cnt!=a.cnt)return cnt>a.cnt;
        return t<a.t;
    };
};
const int N=1e5+10;
node team[N];
int main()
{
    read_fast
    int n;
    cin>>n;
    
    for(int i=0;i<n;i++){
        cin>>team[i].name;
        int cnt=0,t=0;
        for(int j=1;j<=4;j++){
            int x,v;
            cin>>x>>v;
            if(v!=0) {
                cnt++;
                t+=v;
                t+=(x-1)*20;
            }
        }
        team[i].cnt=cnt;
        team[i].t=t;
    }
    sort(team,team+n);
    cout<<team[0].name<<' '<<team[0].cnt<<' '<<team[0].t<<"\n";
    return 0;
}