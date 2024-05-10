#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int N=1100;
struct node
{
    string m;
    vector<PII> f; 
}a[N];
int n;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
int main()
{
        cinquick();
        cin>>n;
        string op;
        int k;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].m>>k;
            int id,v;
            for(int j=1;j<=k;j++){
                string s;
                cin>>s;
                sscanf(s.c_str(),"%d:%d",&id,&v);
                //cout<<id<<' '<<v<<endl;
                a[i].f.push_back({v,id});
            }
        }
        double ans=0,ans1=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i].m=="F")
            {
                int res=0;
                for(auto mp:a[i].f){
                    int v=mp.first,id=mp.second;
                    
                    if(a[id].m=="M"){
                        //cout<<v<<' '<<id<<endl;
                        res=max(res,v);
                    }
                }
                double resv=1.0/res;
                ans=max(ans,resv);
            }
            else{
                int res1=0;
                for(auto mp:a[i].f){
                    int v=mp.first,id=mp.second;
                    if(a[id].m=="F"){
                         cout<<v<<' '<<id<<endl;
                        res1=max(res1,v);
                    }
                }
                double resv=1.0/res1;
                ans1=max(ans1,resv);
            }
        }
        cout<<ans<<endl;
        vector<int> idf,idm;
        for(int i=1;i<=n;i++)
        {
            if(a[i].m=="F")
            {
                int res=0;
                for(auto mp:a[i].f){
                    int v=mp.first,id=mp.second;
                    if(a[id].m=="M"){
                        res=max(res,v);
                    }
                }
                double resv=1.0/res;
                if(resv==ans) idf.push_back(i);
            }
            else{
                int res1=0;
                for(auto mp:a[i].f){
                    int v=mp.first,id=mp.second;
                    if(a[id].m=="F"){
                        res1=max(res1,v);
                    }
                }
                double resv=1.0/res1;
                if(resv==ans1) idm.push_back(i);
            }
        }

        for(int i=0;i<idf.size();i++)
            if(i==0) cout<<idf[i];
            else cout<<' '<<idf[i];
        cout<<endl;
        for(int i=0;i<idm.size();i++)
            if(i==0) cout<<idm[i];
            else cout<<' '<<idm[i];
        return 0;
}