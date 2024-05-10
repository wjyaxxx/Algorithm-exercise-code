#include <bits/stdc++.h>
using namespace std;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
int f(int x)
{
    int res=0;
    while(x){
        res+=x%10;
        x/=10;
    }
    return res;
}
int main()
{
        cinquick();
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            int h,w,g;
            cin>>g>>h>>w;
            if(g==1){
                if(h<130) cout<<"duo chi yu! ";
                else if(h>130) cout<<"ni li hai! ";
                else cout<<"wan mei! ";

                if(w>27) cout<<"shao chi rou!"<<endl;
                else if(w<27) cout<<"duo chi rou!"<<endl;
                else cout<<"wan mei!"<<endl;
            }
            else{
                if(h<129) cout<<"duo chi yu! ";
                else if(h>129) cout<<"ni li hai! ";
                else cout<<"wan mei! ";

                if(w>25) cout<<"shao chi rou!"<<endl;
                else if(w<25) cout<<"duo chi rou!"<<endl;
                else cout<<"wan mei!"<<endl;

            }
        }
        return 0;
}