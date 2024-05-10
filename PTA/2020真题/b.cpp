#include <bits/stdc++.h>
using namespace std;
const int N=1e4;
char sk1[N];
int sk2[N],tt1,tt2;
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
            sk2[++tt2]=x;
        }
        for(int j=1;j<n;j++){
            char op;
            cin>>op;
            sk1[++tt1]=op;
        }
        while(tt1){
            char op=sk1[tt1--];
            int a=sk2[tt2--],b=sk2[tt2--];
            if(op=='+') sk2[++tt2]=(a+b);
            else if(op=='-') sk2[++tt2]=(b-a);
            else if(op=='*') sk2[++tt2]=(b*a);
            else{
                if(a==0){
                    printf("ERROR: %d/0\n",b);
                    return 0;
                }
                sk2[++tt2]=(b/a);
            }
        }

        cout<<sk2[tt2]<<endl;
        return 0;
}