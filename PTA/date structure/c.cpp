#include <bits/stdc++.h>
using namespace std;
const int N=1010;
int h[N],size;
int n,m;
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
    int t = u;
    if (u * 2 <= n && h[u * 2] < h[t]) t = u * 2;
    if (u * 2 + 1 <= n && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
    if (u != t)
    {
        swap(u, t);
        down(t);
    }
}
int find(int u,int x)
{
    if(x==h[u]) return u;
    if(u<<1<=size) return find(u<<1,x);
    if((u<<1|1)<=size) return find(u<<1|1,x);
}
int main()
{
        //cinquick();
        
        cin>>n>>m;
       for(int i=1;i<=n;i++) cin>>h[i];
       
       string line;
       getline(cin,line);
       for(int i=(n>>1);i;i--) down(i);
        
        for(int i=1;i<=n;i++) cout<<h[i]<<' ';
        




    //    while(m--)
    //    {
    //       string a;
    //       getline(cin,a);
    //       if(a[6]=='a')
    //       {
    //             int x,y;
    //             sscanf(a.c_str(),"%d is a child of %d",&x,&y);
    //             int j=find(1,y);
    //             // if(h[j<<1]==x||h[j<<1|1]==x) printf("T\n");
    //             // else printf("F\n");

    //       }
    //       else if(a[6]==' ')
    //       {
    //             int x,y;
    //             sscanf(a.c_str(),"%d and %d are siblings",&x,&y);
    //             int i=find(1,x);
    //             int j=find(1,y);
    //             cout<<x<<' '<<y<<endl;
    //             cout<<h[i]<<' '<<h[j]<<endl;
    //             // if(h[i>>1]==h[j>>1]) printf("T\n");
    //             // else printf("F\n");
    //       }
    //       else if(a[6]=='t'&&a[13]=='t')
    //       {
    //             int x;
    //             sscanf(a.c_str(),"%d is the root",&x);
    //             if(h[1]==x) printf("T\n");
    //             else printf("F\n");
    //       }
    //       else
    //       {
    //             int x,y;
    //             sscanf(a.c_str(),"%d is the parent of %d",&x,&y);
    //             int i=find(1,y);
    //             if(h[i>>1]==x) printf("T\n");
    //             else printf("F\n");
    //       }

    //    }
        return 0;
}