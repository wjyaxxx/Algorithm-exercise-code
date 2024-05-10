#include <bits/stdc++.h>

#define x first 
#define y second 
using namespace std;
typedef pair<int,int> PII;
int n;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
int main()
{
        //cinquick();
        cin>>n;
        vector<PII> memge,ans;
        int h1,m1,s1,h2,m2,s2;
        for(int i=1;i<=n;i++)
        {
            scanf("%d:%d:%d - %d:%d:%d",&h1,&m1,&s1,&h2,&m2,&s2);
            int st=h1*3600+m1*60+s1,ed=h2*3600+m2*60+s2;
            memge.push_back({st,ed});
        }
        
        sort(memge.begin(),memge.end());
        int st=-1e9,ed=-1e9;
        for(auto m:memge)
        {
            if(ed<m.x){
                if(st!=-1e9) ans.push_back({st,ed});
                st=m.x,ed=m.y;
            }
            else ed=max(ed,m.y);
        }

        if(st!=-1e9) ans.push_back({st,ed});

        int edmax=23*3600+59*60+59;
        vector<PII> res;
        if(ans[0].x!=0) res.push_back({0,ans[0].x});
         st=ans[0].x,ed=ans[0].y;
        for(int i=1;i<ans.size();i++)
        {
            res.push_back({ed,ans[i].x});
            ed=ans[i].y;
        }
        if(ans.back().y!=edmax) res.push_back({ans.back().y,edmax});

        for(auto m:res)
        {
            int st=m.x,ed=m.y;
            int h1=st/3600,m1=(st-h1*3600)/60,s1=(st-h1*3600-m1*60);
             int h2=ed/3600,m2=(ed-h2*3600)/60,s2=(ed-h2*3600-m2*60);
             printf("%02d:%02d:%02d - %02d:%02d:%02d\n",h1,m1,s1,h2,m2,s2);
        }
        return 0;
}