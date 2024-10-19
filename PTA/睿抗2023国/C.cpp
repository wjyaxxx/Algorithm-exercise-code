#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int n,m,k;
typedef pair<int,pair<int,int>> PII;
const int N=1100;
int t[N];//面的时间
int lan[10010];
priority_queue<int,vector<int>,greater<int>> q1;//篮子地编号
priority_queue<PII,vector<PII>,greater<PII>> q2;//有订单的处理
int main()
{
    read_fast
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) cin>>t[i];
    
    //最开始全部是空篮子
    for(int i=1;i<=m;i++) q1.push(i);

    vector<pair<int,int>> ans;
    int x;
    int ed=0;
    for(int i=1;i<=k;i++){
        cin>>x;//这位顾客需要的面的种类
        if(q1.size()){
            //有空篮
            int id=q1.top();
            q1.pop();
            q2.push({t[x],{i,id}});
            cerr<<id<<"\n";
            lan[id]++;
        }//没有空篮了
        else{
            //取出已经煮好的面，给顾客
            auto t1=q2.top();
            q2.pop();
            int timeed=t1.first,pid=t1.second.first,lid=t1.second.second;
            cerr<<lid<<"\n";
            lan[lid]++;
            ans.push_back({timeed,pid});
            q2.push({timeed+t[x],{i,lid}});
        }

    }
    while(q2.size()){
            auto t1=q2.top();
            q2.pop();
            int timeed=t1.first,pid=t1.second.first,lid=t1.second.second;
            //lan[lid]++;
            ans.push_back({timeed,pid});

    }
    for(int i=0;i<ans.size();i++){
        if(i==0) cout<<ans[i].second<<':'<<ans[i].first;
        else cout<<' '<<ans[i].second<<':'<<ans[i].first;
    }
    cout<<"\n";
    for(int i=1;i<=m;i++) cout<<lan[i]<<' ';
    return 0;
}