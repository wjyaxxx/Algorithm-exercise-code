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
        string str,tmp;
        getline(cin,tmp);
       for(int i=1;i<=n;i++){
        getline(cin,str);
        int idx1=str.find(','),idx2=str.find('.');
        if(idx1<3){
            cout<<"Skipped"<<endl;
            continue;
        }
        string s1=str.substr(idx1-3,3),s2=str.substr(idx2-3,3);
        if(s1=="ong"&&s2=="ong"){
            int idx3;
            int cnt=0;
            for(int j=str.size()-1;j>=0;j--){
                if(str[j]==' ') cnt++;
                if(cnt==3){
                    idx3=j;
                    break;
                }
            }
            int sz=str.size();
            str.replace(idx3+1,sz-1-idx3,"qiao ben zhong.");
            cout<<str<<endl;
        }
        else{
            cout<<"Skipped"<<endl;
        }
       }

        
        return 0;
}