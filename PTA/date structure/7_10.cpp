#include <bits/stdc++.h>
using namespace std;
char a[105][10005];
int b[105];
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
int main()
{
        cinquick();
    int n,m,s,x;
    scanf("%d %d %d",&n,&m,&s);
    for(int i=1;i<=n;i++){
        scanf("%s",&a[i]);
    }
    
    stack<char>st;
    while(1){
        scanf("%d",&x);
        if(x==-1) break;
        if(x==0){
            if(!st.empty()){
                printf("%c",st.top());
                st.pop();
            }
        }
        else {      	
            if(b[x]<m){
                if(st.size()>=s){
                   printf("%c",st.top());
                   st.pop();
                }
                st.push(a[x][b[x]++]);
            }
        }
    }
        return 0;
}