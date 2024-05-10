#include <bits/stdc++.h>
using namespace std;
typedef pair<string,int> PII;
const int N=1e4+5;
PII pk[N]; 
int n;
string line,tmp,ans;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
bool check(char c)
{
    return (c=='?'||c=='!'||c==',');
}
void str_replace(string a,string b)
{
    if(ans.find(a)==-1) return ;
    
    int sz=a.size();
    int idx=ans.find(a);
    if(a=="I") cout<<ans[idx-1]<<1<<endl;
    if(idx-1>=0)
    {
        if(ans[idx-1]==' ') ;
        else if(ans[idx-1]=='?'||ans[idx-1]==','||ans[idx-1]=='!') ;
        else  return ;
    }
    
    if(idx+sz<ans.size())
    {
        if(ans[idx+sz]==' ') ;
        else if(ans[idx+sz]=='?'||ans[idx+sz]==','||ans[idx+sz]=='!') ;
        else  return ;
    }
    ans.replace(ans.find(a),a.size(),b);
}
int main()
{
        cinquick();
        cin>>n;
        
        getline(cin,tmp);
        while(n--)
        {
           getline(cin,line);
           cout<<line<<endl;
           while(line.back()==' ') line.pop_back();
             ans="";
            for(int i=0;line[i];i++)
            {
                if(i-1>=0&&line[i]==' '&&line[i-1]!=' '&&!check(line[i+1])&&line[i+1]!='\'') ans+=line[i];
                else if(line[i]>='A'&&line[i]<='Z'&&line[i]!='I') ans+=char(tolower(line[i]));
                else if(line[i]==' ') continue;
                else ans+=line[i]; 
            }
            //cout<<ans<<endl;
            str_replace("I","you");
            str_replace("can you","I can");
            str_replace("Can you","I can");
            str_replace("could you","I could");
            str_replace("Could you","I could");
            str_replace("me","you");
            str_replace("?","!");
            cout<<"AI: ";
            cout<<ans<<endl;
        }
        return 0;
}