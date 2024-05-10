#include <bits/stdc++.h>
using namespace std;
const int K=20,N=1<<K;
int p[N];
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
int main()
{
        cinquick();
        int k;
        cin>>k;
        int n=1<<k;
        vector<int> a[k+1+1];
        for(int i=k;i>0;i--)
        {
            for(int j=1;j<=(1<<(i-1));j++) 
            {
                int x;
                cin>>x;
                a[i].push_back(x);
            }
        }
        cin>>p[1];
        

        return 0;
}