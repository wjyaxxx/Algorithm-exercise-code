#include <bits/stdc++.h>
using namespace std;
string myname="wangjiyi";
int n;
string s;

int main()
{
    cin>>n>>s;
    
    if(s=="yourname") s=myname;
    
    string cpys=s;
    for(int j=1;j<=n;j++){
        string res="";
        for(auto x:s){
            if(x<='Z'&&x>='A'){
                res+=((x-'A')+1)%26+'A';
            }else if(x>='a'&&x<='z'){
                res+=((x-'a')+25)%26+'a';
            }
            else res+=x;
        }
        int l=-1,r=0;
        int ca=0,cb=0;
        string res1="";
        int cnt=0;

        
        while(l<int(res.size())&&r<int(res.size())){
            while(r<res.size()&&res[r]>='a'&&res[r]<='z'){
                r++;
                ca++;
            }
                for(int i=l+1;i<=r-1;i++)
                    if(ca>=3) res1+=((res[i]-'a')+'A');
                    else res1+=res[i];
            ca=0;
            l=r-1;
            while(r<res.size()&&res[r]>='A'&&res[r]<='Z'){
                r++;
                cb++;
            }
                for(int i=l+1;i<=r-1;i++)
                    if(cb>=3) res1+=((res[i]-'A')+'a');
                    else res1+=res[i];
            cb=0;
            l=r-1;
            while(r<res.size()&&res[r]>='0'&&res[r]<='9'){
                
                res1+=res[r];
                r++;
            }
            l=r-1;
        }
         s=res1;
    }
    cout<<cpys<<"\n";
    cout<<s<<"\n";
    return 0;
}