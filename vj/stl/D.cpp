#include <bits/stdc++.h>
using namespace std;

void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
void solve()
{
    int n;
    cin>>n;
    queue<int> q;
    for(int i=1;i<=n;i++) q.push(i);
    while(q.size()>3){
        //先移除所有偶数
        int len=q.size();
        for(int i=1;i<=len;i++){
            int now=q.front();
            q.pop();
            if(i%2!=0) q.push(now);//都出，被冤枉的再次入队 
        }
        if(q.size()<=3) break;

        len=q.size();
        for(int i=1;i<=len;i++){
            int now=q.front();
            q.pop();
            if(i%3!=0) q.push(now);//都出，被冤枉的再次入队 
        }
    }
    

    while(q.size()){
        cout<<q.front()<<' ';
        q.pop();
    }
    cout<<endl;
}
int main()
{
        cinquick();
        int t;
        cin>>t;
        while(t--) solve();
        return 0;
}