#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
string s,p;
const int N=3e6+10;
int sk[N],cb;
int main()
{
    read_fast
    cin>>s>>p;
    string news=p+'#'+s;

    int n=news.size();
    vector<int> pi(n);
    for(int i=1;i<n;i++){
        int len=pi[i-1];
        while(len > 0 && news[i]!=news[len]) len=pi[len-1];
        if(news[i]==news[len])  pi[i]=len+1;
    }
    
    //将字符串入栈
    for(int i=p.size()+1,len=0;i<n;i++){
        if(!cb) len=0;
        else len=pi[sk[cb]];
        sk[++cb]=i;
        //cout<<i<<' '<<sk.top()<<"\n";
        while(len && news[i]!=news[len]) len=pi[len-1];
        if(news[i]==news[len]) pi[i]=len+1;
        if(pi[i]==p.size()) {
            int t=p.size();
            cb-=t;
        }
    }
    
    for(int i=1;i<=cb;i++) cout<<news[sk[i]];
    //cout<<tmp.size();
    return 0;
}