#include <bits/stdc++.h>
using namespace std;
const int N=110;
struct node
{
    string name;
    int cnt;
    double avg;
}q[N];
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
bool cmp(node a,node b)
{
    if(a.cnt!=b.cnt)return a.cnt>b.cnt;
    return a.avg<b.avg;
}
int main()
{
        cinquick();
        int  n;
        cin>>n;
        for(int i=1;i<=n;i++){
            string str;
            cin>>str;
            q[i].name=str;
            int k;
            cin>>k;
            set<int> s;
            int sum=0;
            for(int j=1;j<=k;j++){
                int x;
                cin>>x;
                sum++;
                s.insert(x);
            }
            
            double wjy=(sum*1.0)/s.size();
            q[i].cnt=s.size();
            q[i].avg=wjy;
           }
       sort(q+1,q+1+n,cmp);
       if(n>=3)
       {
            for(int i=1;i<=3;i++)
                if(i==1) cout<<q[i].name;
                else cout<<' '<<q[i].name;
       }
       else{
         for(int i=1;i<=n;i++)
                if(i==1) cout<<q[i].name;
                else cout<<' '<<q[i].name;
            for(int i=n+1;i<=3;i++){
                cout<<' '<<'-';
            }
        }
        return 0;
    
}