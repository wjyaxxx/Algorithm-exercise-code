#include <bits/stdc++.h>
using namespace std;
const int N=1000010;
char a[N];
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
        scanf("%s",a);
        int ans=0;
        for(int i=0;a[i];i++)
        {
            int idx=i;
            while(a[i]<=a[i+1]) i++;
            ans=max(ans,i-idx+1);
        }
        cout<<ans<<endl;
        return 0;
}