#include <bits/stdc++.h>
using namespace std;
stack<double> res;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
double read(string x){
    double res=0;
    for(auto c:x){
        res=res*10+(c-'0');
    }
    return res;
}
int main()
{
        cinquick();
        string str;
        while(getline(cin,str)){
            if(str=="0") break;
            stringstream s;
            s<<str;
            string op;
            while(s>>op){
                if(op=="*"||op=="/"){
                    string m;
                    s>>m;
                    double b=read(m);
                    double a=res.top();
                    res.pop();
                    double res1;
                    if(op=="*") res1=a*b;
                    else res1=a/b;
                    res.push(res1);
                }
                else if(op=="+") s1.push(op);
                else res.push(read(op));
            }
            
    }

        return 0;
}