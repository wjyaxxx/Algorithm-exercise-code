#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const int N=1e6+10;
char s[N],tt;
bool check(char x){
        if(x<='z' && x>='a') return 1;
        if(x<='Z' &&  x>='A') return 1;
        return 0;
}
int main()
{
    //read_fast
    char x;
    int ok=0;

    while(~scanf("%c",&x)){
        if(check(x)){
            if(!ok){
                if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' || x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U') 
                {
                    s[tt++]=x;ok=1;
                }
                else {
                    ok=x;
                    //cout<<x<<' '<<ok<<"\n";
                }
            }
            else s[tt++]=x;
            
        }else{
            //发现单词末尾
            if(ok>1) s[tt++]=char(ok);
            if(ok){
                s[tt++]='a';
                s[tt++]='y';    
            }
            s[tt++]=x;
            for(int i=0;i<tt;i++) printf("%c",s[i]);
            tt=0;
            ok=0;
        }
    }

    //for(int i=0;i<tt;i++) printf("%c",s[i]);
    return 0;
}