#include <bits/stdc++.h>
using namespace std;
const int N=510;
int edge[N][N];
int sex[N],d[N];//d里面存储的是第i个人的异性最大距离
int n;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
void floyd()
{
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                edge[i][j]=min(edge[i][j],edge[i][k]+edge[k][j]);
            }
        }
    }
}
int main()
{
        //cinquick();
        cin>>n;
        for (int i = 1; i <= n; i++) // floyd初始化（初始时二者没有关系，设为inf）
        for (int j = 1; j <= n; j++)
            if (i != j)
                edge[i][j] = 1e9;
            else
                edge[i][j] = 0;

        char g[3];
        for(int i=1;i<=n;i++){
            cin>>g;
            if(strcmp(g,"F")==0) sex[i]=1;
            else sex[i]=2;
            int k;
            cin>>k;
            for(int j=1;j<=k;j++){
                int idx,dis;
                scanf("%d:%d",&idx,&dis);
                edge[i][idx]=dis;
            }
        }

        floyd();
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(sex[i]!=sex[j]){
                    //cout<<edge[j][i]<<endl;
                    d[i]=max(d[i],edge[j][i]);
                }

        int a=0x3f3f3f3f,b=a;

        for(int i=1;i<=n;i++){
            if(sex[i]==1) a=min(a,d[i]);
            else b=min(b,d[i]);
        }

        vector<int> men,women;

        for(int i=1;i<=n;i++)
        {
            if(sex[i]==1&&d[i]==a) women.push_back(i);
            if(sex[i]==2&&d[i]==b) men.push_back(i);
        }

        for(int i=0;i<women.size();i++)
            if(i==0) cout<<women[i];
            else cout<<' '<<women[i];
        puts("");

        for(int i=0;i<men.size();i++)
            if(i==0) cout<<men[i];
            else cout<<' '<<men[i];
        return 0;
}