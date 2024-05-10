#include <bits/stdc++.h>
using namespace std;
map<string,int> mp;
int idx;
const int N=11000,M=N*10;
int ne[M],e[M],h[M],id;
int s[M],f[M];
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
void add(int a,int b)
{
    e[id]=b,ne[id]=h[a],h[a]=id++;
}
int id_find(string x)
{
    if(mp.find(x)==mp.end())
    {
        mp[x]=idx++;
        return mp[x];
    }
    else return  mp[x];
}

int dfs(int pos) {
    int res= s[pos]; 
    //cout<<res<<' '<<pos<<endl;
    for (int i=h[pos];i!=-1;i=ne[i]) {
        
        int j=e[i];
        res +=dfs(j);
    }
    return res;
}
int main()
{
        cinquick();
        int n,m;
        cin>>n>>m;
        fill(h,h+M,-1);
        while(m--)
        {
            string a,b;
            cin>>a>>b;
            int ida=id_find(a),idb=id_find(b);
            //cout<<ida<<' '<<idb<<endl;
            if(a[0]<='9'&&a[0]>='0')
            {
                
                f[ida]=idb;
                s[idb]++;
            }
            else
            {
                //cout<<a<<' '<<b<<endl;
                   add(idb,ida); //b--->a (因为a是父节点)
            }
        }
       
        string op;
        while(cin>>op)
        {
            if(op=="E") break; 
            if(op=="T")
            {
                string a,b;
                cin>>a>>b;
                int i=id_find(a),j=id_find(b);
                //cout<<size[f[i]]<<' '<<size[j]<<endl;
               f[i]=j;
               s[j]++;
               
            }
            else
            {
                string a;
                cin>>a;
                int i=id_find(a);
                //cout<<i<<endl;
                if(i==1)
                    int ans=dfs(i);
               //cout<<ans<<endl;
            }
        }

        return 0;
}