#include <bits/stdc++.h>
using namespace std;
const int N=1010;
int a[N];
char b[N];
int ta,tb;
void ap(int x)
{
    a[++ta]=x;
}
void bp(char x)
{
    b[++tb]=x;
}
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
int main()
{
        cinquick();
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            int x;
            cin>>x;
            ap(x);
        }
        for(int i=1;i<n;i++)
        {
            char x;
            cin>>x;
            bp(x);
        }
        int ans=0;
        while(ta&&tb)
        {
            int  x,y;
            x=a[ta--];
            y=a[ta--];
            char op;
            op=b[tb--];
            int res;
            if(op=='*') res=x*y;
            else if(op=='+') res=x+y;
            else if(op=='-') res=y-x;
            else{
                if(!x)
                {
                    printf("ERROR: %d/0\n",y);
                    return 0;
                }
                else{
                    res=y/x;
                }
            }
            ap(res);
            res=0;
        }
        cout<<a[ta]<<endl;
        return 0;
}