#include <bits/stdc++.h>
using namespace std;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
unordered_map<string,string> name;
unordered_map<string,int> xing;
unordered_map<string,int> id;
unordered_map<string,string> sex;
int idx=1;
int p[11000];
int main()
{
        cinquick();
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            string a,b,g;
            cin>>a>>b;
            if(b.rfind("sson")!=-1){
                int idx=b.rfind("sson");
                 g=b.substr(idx,b.size()-idx);
                xing[a]=1;
                b=b.substr(0,idx);
            }
            else if(b.rfind("sdottir")!=-1){
                int idx=b.rfind("sdottir");
                 g=b.substr(idx,b.size()-idx);
                b=b.substr(0,idx);
                xing[a]=0;
            }
            else if(b.rfind("m")!=-1){
                int idx=b.rfind("m");
                 g=b.substr(idx,b.size()-idx);
                b=b.substr(0,idx);
                xing[a]=1;
            }
            else{
                int idx=b.rfind("f");
                 g=b.substr(idx,b.size()-idx);
                b=b.substr(0,idx);
                xing[a]=0;
            }
            
            id[a]=idx++;
            name[a]=b;
            sex[a]=g;
            //cout<<g<<endl;
        }
        for(int i=1;i<=n;i++) p[i]=i;

        for(auto x:name){

            int getid=id[x.first];//自己的id
            int getid1=id[x.second];//父亲的id
            if(sex[x.first]=="sson"||sex[x.first]=="sdottir")
                p[getid]=getid1;
        }
        int m;
        cin>>m;
        for(int i=1;i<=m;i++)
        {
            string m1,x1,m2,x2;
            cin>>m1>>x1>>m2>>x2;
            if(xing.find(m1)==xing.end()||xing.find(m2)==xing.end()) cout<<"NA"<<endl;
            else if(xing[m1]==xing[m2]) cout<<"Whatever"<<endl;
            else{
                
                int id1=id[m1],id2=id[m2];
                int cnt1=0,cnt2=0;
                set<int> s;
                while(id1!=p[id1]){
                    s.insert(id1);
                    id1=p[id1];
                }
                s.insert(id1);
                while(id2!=p[id2]&&s.find(id2)==s.end()){
                    id2=p[id2];
                }
                
                
                if(s.find(id2)==s.end()) {
                    //cout<<i<<' '<<id2<<endl;
                    cout<<"Yes"<<endl;
                }
                else{
                    int gong=id2;
                    id1=id[m1],id2=id[m2];
                    while(id1!=gong){
                    cnt1++;
                    id1=p[id1];
                    }
                    while(id2!=gong){
                        cnt2++;
                        id2=p[id2];
                    }
                    if(cnt1<=3||cnt2<=3) cout<<"No"<<endl;
                    else cout<<"Yes"<<endl;
                }
            }
        }
        
        return 0;
}