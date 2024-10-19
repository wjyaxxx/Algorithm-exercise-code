#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
map<int,int> mp;
string s;
int maxv=0,minv=0;
int sign=1;
int main()
{
    read_fast
    cin>>s;
    int l=0,r=s.size()-1;
    while(l<=r){
        int x=0,y=0;//x读取数量，y读取面值
        while(l<=r && s[l]!='d'&& s[l]!='+' &&s[l]!='-')
            x=x*10+(s[l++]-'0');
        
        if(s[l]=='d'){
            if(x==0) x=1;
            l++;//跳过d
            
            while(l<=r && s[l]!='d'&& s[l]!='+' &&s[l]!='-')
                y=y*10+(s[l++]-'0');
            
            mp[y]+=x;
            //判断上一个指令的符号
            if(sign==1){
                maxv+=x*y;
                minv+=x;
            }
            else{
                maxv-=x;
                minv-=x*y;
            }
        }else{
            //只是一个数字
            maxv+=sign*x;
            minv+=sign*x;
        }

        s[l]=='+'?sign=1:sign=-1;
        l++;
    }
    for(auto [x,y]:mp) cout<<x<<' '<<y<<"\n";

    cout<<minv<<' '<<maxv<<"\n";
    return 0;
}