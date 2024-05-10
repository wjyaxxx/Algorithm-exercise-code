#include <map>
#include <cstdio>
#include <iostream>
using namespace std;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
map<int,int> mp; 
int main()
{
        //cinquick();
        int op;
        map<int,int>::iterator it;
        while(scanf("%d",&op)!=EOF&&op){
           
            if(op==1){
                int id,v;
                scanf("%d%d",&id,&v);
                mp[v]=id;
            }
            else if(op==2){
                if(mp.empty()) printf("%d\n",0);
                else{
                    it=mp.end();
                    it--;
                    printf("%d\n",(*it).second);
                    mp.erase(it);
                }
            }
            else{
                if(mp.empty()) printf("%d\n",0);
                else {
                    it=mp.begin();
                    printf("%d\n",(*it).second);
                    mp.erase(it);
                }
            }
        }
        return 0;
}