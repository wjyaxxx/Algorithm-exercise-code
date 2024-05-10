#include <bits/stdc++.h>
using namespace std;
const int N=1010;
int h[N],s,idx;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
void up(int u)
{
    while(u/2&&h[u>>1]>h[u])
    {
        swap(h[u],h[u>>1]);
        u>>=1;
    }
}

void down(int u)
{
    int t=u;
    if((u<<1)<=s&&h[t]>h[u<<1]) t=(u<<1);
    if((u<<1|1)<=s&&h[t]>h[u<<1|1]) t=(u<<1|1);
    if(u!=t)
    {
        swap(h[t],h[u]);
        down(t);
    }
}
// void find(int u,int x)
// {
//     if(h[u]==x) {
//         idx=u;
//         return ;
//     }
//         if(u<<1<=s) find(u<<1,x);
//         if((u<<1|1)<=s)  find(u<<1|1,x);
// }
int find(int x)
{
    for(int i=1;i<=s;i++)
    {
        if(h[i]==x) return i;
    }
    return 0;
}
int main()
{
        //cinquick();
        int n,m;
        cin>>n>>m;
        s=n;
       for(int i=1;i<=n;i++) cin>>h[i];
       string line;
       getline(cin,line);
       for(int i=1;i<=n;i++) up(i);
       string s;
       int x,y;
       while(m--)
       {
          cin>>x;
        cin>>s;
        if(s[0]=='a')       
        {
            cin>>y;
            getline(cin,s);
            
            if(find(x)/2==find(y)/2) puts("T");
            else puts("F");
        }
        else
        {
            cin>>s;
            cin>>s;
            if(s[0]=='r')   
            {
                if(find(x)==1) puts("T");
                else puts("F");
            }
            else if(s[0]=='p')  
            {
                cin>>s;
                cin>>y;
                if(find(x)==find(y)/2) puts("T");
                else puts("F");
            }
            else    
            {
                cin>>s;
                cin>>y;
                if(find(x)/2==find(y)) puts("T");
                else puts("F");
            }
        }

       }
        return 0;
}