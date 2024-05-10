#include <bits/stdc++.h>
using namespace std;
const int N=1000010;
int q[N],cnt[26];
char arr[N];
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
int main()
{
        //cinquick();
        int n,m;
        scanf("%d%d",&n,&m);
        scanf("%s",arr);

        for(int i=0;arr[i];i++)
        {
            cnt[arr[i]-'0']++;
            q[i]=cnt[arr[i]-'0'];
        }
        while(m--)
        {
            int x;
            scanf("%d",&x);
            x--;
            printf("%d\n",q[x]);
        }
        return 0;
}