#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
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
        string str,tmp;
        getline(cin,tmp);
        vector<pair<int,int>> memge;
        for(int i=1;i<=n;i++)
        {
            getline(cin,str);
            int h1,m1,s1,h2,m2,s2;
            sscanf(str.c_str(),"%d:%d:%d - %d:%d:%d",&h1,&m1,&s1,&h2,&m2,&s2);
            int st=h1*3600+m1*60+s1;
            int ed=h2*3600+m2*60+s2;
            memge.push_back({st,ed});
        }
        sort(memge.begin(),memge.end());
        vector<pair<int,int>> ans;
        int ed=-1e9,st=-1e9;
        for(auto x:memge)
        {
            if(ed<x.first)
            {
                if(st!=-1e9) ans.push_back({st,ed});
                st=x.first,ed=x.second;
            }
            else ed=max(ed,x.second);
        }
        if (st != -2e9) ans.push_back({st, ed});
        vector<pair<int ,int>> res;
        if(ans[0].first>0) res.push_back({0,ans[0].first});

        st=ans[0].first,ed=ans[0].second;
        for(int i=1;i<ans.size();i++)
        {
            int nw=ans[i].first,nd=ans[i].second;
            res.push_back({ed,nw});
            st=nw;
            ed=nd;
        }
        int fin=23*3600+59*60+59;
        if(ed!=fin) res.push_back({ed,fin});

        for(auto x:res)
        {
            int nw=x.first,nd=x.second;
            int h1,m1,s1,h2,m2,s2;
            h1=nw/3600;
            nw-=h1*3600;
            m1=nw/60;
            nw-=m1*60;
            s1=nw;
            h2=nd/3600;
            nd-=h2*3600;
            m2=nd/60;
            nd-=m2*60;
            s2=nd;
            printf("%02d:%02d:%02d - %02d:%02d:%02d\n",h1,m1,s1,h2,m2,s2);
        }
        return 0;
}