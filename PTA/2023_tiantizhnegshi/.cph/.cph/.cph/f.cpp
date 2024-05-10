#include <bits/stdc++.h>
using namespace std;
const int N=5050;
struct school
{
    string team;
    int num,room,idx;
    bool ok;
}s[N];
struct f
{
    int num;
    string team;
}ans[N];

int n,c,cnt;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
bool cmp(school a,school b)
{
    return a.num>b.num;
}
int main()
{
        cinquick();
        cin>>n>>c;
        for(int i=1;i<=n;i++)
        {
            cin>>s[i].team>>s[i].num;
            s[i].room=s[i].num/c;
            s[i].num-=s[i].room*c;
            if(s[i].num==0) s[i].ok=true;
            s[i].idx=i;
            cnt+=s[i].room;
        }
        sort(s+1,s+1+n,cmp);

        for(int i=1;i<=n;i++)
        {
            int t=s[i].num;
            if(s[i].ok) continue;
            //cout<<t<<endl;
            cnt++;
            s[i].room++;
            s[i].ok=true;
            int v=c-t;
            
            for(int j=i;j<=n;j++)
            {
                int t1=s[j].num;
                if(s[j].ok) continue;
                if(v>=t1)
                {
                    v-=t1;
                    s[j].ok=true;
                    s[j].room++;
                }
            }
            //cout<<v<<endl;
        }

        for(int i=1;i<=n;i++)
        {
            ans[s[i].idx].team=s[i].team;
            ans[s[i].idx].num=s[i].room;
        }
        for(int i=1;i<=n;i++)
        {
            cout<<ans[i].team<<' '<<ans[i].num<<endl;
        }
        cout<<cnt<<endl;
        return 0;
}