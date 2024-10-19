#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const int N=2*1e5+10;
int pi[N];
int main()
{
    //read_fast
    string s;
  
    int n,q;
    cin>>n>>q;
    cin>>s;
    int ans=0;
    for(int i=0;i<n;i++){
        if(s[i]=='A' && s[i+1]=='B' && s[i+2]=='C') ans++,i+=2;
    }

    
     auto count=[&](int id){
        int res=0;
        
        if(s[id]=='A' && s[id+1]=='B' && s[id+2]=='C') res++;
        if(id && s[id-1]=='A' && s[id]=='B' && s[id+1]=='C') res++;
        if(id>=2 && s[id-2]=='A' && s[id-1]=='B' && s[id]=='C') res++;
        return res; 
    };
    
   
    
    while(q--){
        int id;
        char x;
        scanf("%d %c",&id,&x);
        id--;    
        ans-=count(id);
    
        //printf("%d\n",count(id));
        s[id]=x;
        ans+=count(id);    
         printf("%d\n",ans);
    }
    return 0;
}