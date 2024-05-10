#include <bits/stdc++.h>
using namespace std;
unordered_map<string,int> mp;
unordered_map<string,string> ans;
set<string> buzhengchang;
struct node{
    string name,id;
    int op;
    string time;
    int idx;
};
int d,day;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
bool cmp(node a,node b){
    if(a.time!=b.time) return a.time<b.time;
    return a.idx<b.idx;
}
bool check(string name)
{
    int cnt=0;
    for(int i=0;i<name.size();i++)
        if(name[i]>='0'&&name[i]<='9')
            cnt++;
    return (cnt==18);
}
int main()
{
        cinquick();
        cin>>d>>day;
        for(int i=1;i<=d;i++){
            int t,s;
            cin>>t>>s;
            node p[t];
            for(int j=0;j<t;j++){
                cin>>p[j].name>>p[j].id>>p[j].op>>p[j].time;
                p[j].idx=j;
            }
            sort(p,p+t,cmp);

            for(int j=0;j<t;j++){
                if(p[j].op==1) buzhengchang.insert(p[j].name);
                if(check(p[j].id)){
                        if(mp.find(p[j].name)==mp.end()||mp[p[j].name]<i){
                        {
                            
                            if(s){
                                cout<<p[j].name<<' '<<p[j].id<<endl;
                                mp[p[j].name]=i+day;
                                ans[p[j].name]=p[j].id;
                                s--;
                            }
                        }
                        
                    }
                }
            }
        }

        for(auto x:buzhengchang){
            cout<<x<<' '<<ans[x]<<endl;
        }
        return 0;
}