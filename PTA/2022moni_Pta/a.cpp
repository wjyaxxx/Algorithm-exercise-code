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
       while(n--){
        int a,high,w;
        cin>>a>>high>>w;
        if(a==1){
            if(high<130){
                cout<<"duo chi yu!"<<" ";
            }
            else if(high>130) cout<<"ni li hai!"<<' ';
            else cout<<"wan mei!"<<' ';

            if(w>27) cout<<"shao chi rou!"<<endl;
            else if(w<27) cout<<"duo chi rou!"<<endl;
            else cout<<"wan mei!"<<endl;
        }
        else{
        if(high<129){
                cout<<"duo chi yu!"<<" ";
            }
            else if(high>129) cout<<"ni li hai!"<<' ';
            else cout<<"wan mei!"<<' ';

            if(w>25) cout<<"shao chi rou!"<<endl;
            else if(w<25) cout<<"duo chi rou!"<<endl;
            else cout<<"wan mei!"<<endl;
       }
    }
       
        return 0;
}