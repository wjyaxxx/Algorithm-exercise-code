#include <bits/stdc++.h>
using namespace std;
int v,maxsize;
const int N=1010;
int a[N],b[N];
int ta,tb;
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
            int p;
            cin>>p;
            if(!ta)
            {
                a[++ta]=p;
            }
            else
            {
                int t=a[ta];
                if(p<t) a[++ta]=p;
                else{
                    if(!tb) b[++tb]=p;
                    else {
                        int bt=b[tb];
                        if(p>bt) b[++tb]=p;
                        else{
                            maxsize=max(maxsize,ta);
                            v++;
                            if(ta) ta=0;
                            while(b[tb]>p&&tb)
                            {
                                a[++ta]=b[tb];
                                tb--;
                            }
                            a[++ta]=p;
                        }
                    }
                }
            }
        }

        if (ta) {
        maxsize = max(ta, maxsize);
        v++;
    }
    if (tb) {
        maxsize = max(tb, maxsize);
        v++;
    }
    cout<<v<<' '<<maxsize<<endl;
        return 0;
}