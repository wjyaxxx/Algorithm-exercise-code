#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
int cmp(char a,char b) 
{
    if(tolower(a)!=tolower(b))//tolower 是将大写字母转化为小写字母.
    return tolower(a)<tolower(b);
    else
    return a<b;
}
unordered_map<int,bool> mp;
int main()
{
        cinquick();
       multiset<int> s;
        int n;
        cin>>n;
        while(n--){
            string op;
            int x;
            cin>>op>>x;
            if(op=="add") {
                s.insert(x);
                cout<<s.count(x)<<endl;
                mp[x]=1;
            }
            else if(op=="del"){
                cout<<s.count(x)<<endl;
                s.erase(x);
            }
            else{
                if(mp.find(x)==mp.end()) cout<<0<<' '<<0<<endl;
                else{
                    cout<<1<<' ';
                    cout<<s.count(x)<<endl;
                }
            }
        }
        return 0;
}

    
