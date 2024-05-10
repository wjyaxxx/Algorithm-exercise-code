#include <bits/stdc++.h>
using namespace std;
const int N=1100;
int a[N],b[N],tta,ttb,cnta,maxcnt;
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
        int x;
        for(int i=1;i<=n;i++)
        {
            cin>>x;
            if((!tta&&!cnta)||x<a[tta]) a[++tta]=x;
            else if(!ttb||b[ttb]<x) b[++ttb]=x;
            else
            {
                cnta++;
                maxcnt=max(maxcnt,tta);
                tta=0;
                while(ttb&&b[ttb]>x)
                {
                    a[++tta]=b[ttb];
                    ttb--;
                }
                a[++tta]=x;
            } 
        }

        maxcnt=max(tta,maxcnt);
        maxcnt=max(ttb,maxcnt);
        if(tta) cnta++;
        if(ttb) cnta++;
        cout<<cnta<<' '<<maxcnt<<endl;
        return 0;
}