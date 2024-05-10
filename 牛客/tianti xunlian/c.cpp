#include <bits/stdc++.h>
using namespace std;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
int main()
{
        //cinquick();
        int n;
        cin>>n;
        double sum=0,alls=0;
        for(int i=1;i<=n;i++)
        {
            int op;
            double s,x1,p1,x2,p2,x3,p3;
            scanf("%d %lf %lf %lf %lf %lf %lf",&op,&s,&x1,&p1,&x2,&p2,&x3,&p3);
            cout<<s<<endl;
            alls+=s;
            if(op==2) continue;
            double cheng=x1*p1+x2*p2+x3*p3;
            int chen=int(cheng);
            if(cheng-chen<0.5) sum+=chen;
            else sum+=chen+1;
        }
        //cout<<alls<<endl;
        sum=sum/alls;
        //printf("%.2f\n",sum);
        return 0;
}