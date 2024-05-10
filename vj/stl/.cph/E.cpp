#include <bits/stdc++.h>
using namespace std;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
struct node{
    int idx;//编号
    int pre_v;  
};
//本来就是大根堆
bool operator<(node a,node b){
    if(a.pre_v!=b.pre_v)
        return a.pre_v<b.pre_v;
    return a.idx>b.idx;
}

int main()
{
        cinquick();
        int n;
        while(cin>>n){
            int id=1;//当前病人的编号
            priority_queue<node> q[4];//四个医生
            for(int i=1;i<=n;i++){
                    string op;
            cin>>op;
            if(op=="IN"){
                int a,b;
                cin>>a>>b;
                q[a].push({id++,b});
            }
            else{
                 int a;
                 cin>>a;
                if(q[a].empty()) cout<<"EMPTY"<<endl;
                 else{
                    cout<<q[a].top().idx<<endl;
                    q[a].pop();
                 }
            }
            }
        }
        return 0;
}