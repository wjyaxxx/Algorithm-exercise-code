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
        cinquick();
        int n;
        cin>>n;
        vector<int> num(n);
        int st,ed;
        cin>>st;
        for(int i=1;i<n;i++){
            cin>>ed;
            num[i]=abs(st-ed);
            st=ed;
        }
        sort(num.begin()+1,num.end());
        
        for(int i=1;i<n;i++)
        {
            if(num[i]!=i) {
                cout<<"Not jolly"<<endl;
                return 0;
            }
        }
        cout<<"Jolly"<<endl;

      
        return 0;
}