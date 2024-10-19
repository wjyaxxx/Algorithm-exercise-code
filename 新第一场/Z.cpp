#include<stdio.h>
#include <vector>
#include <iostream>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
void print(vector<double> & a,int pre,int  suf){
    for(int i=pre;i<=suf;i++)
        if(i!=suf)
        printf("%.2lf ",a[i]);
        else printf("%.2lf\n",a[i]);
        //cout<<"\n";
   
}
int main()
{
    //read_fast
    int n,m;
 	
    while(scanf("%d %d",&n,&m)!=EOF){
        
        vector<double> cls(m);
        vector<double> a(n+1);
        vector<vector<double>> s(n+1,vector<double>(m));
        
        for(int i=1;i<=n;i++){
            double avg=0;
            double x;
            for(int j=0;j<m;j++){
                cin>>x;
                s[i][j]=x;
                avg+=x;
                cls[j]+=x;
            }
            avg/=m;
            a[i]=avg;
        }
        for(int j=0;j<m;j++) cls[j]/=n;
        int  cnt=0;
        for(int i=1;i<=n;i++){
            bool ok=false;
            for(int j=0;j<m;j++){
                
                if(s[i][j]<cls[j]){
                    ok=true;
                    break;
                }
            }
            
            if(!ok) cnt++;
        }
        print(a,1,n);
        print(cls,0,m-1);
        cout<<cnt<<"\n";
        cout<<"\n";
    }
    return 0;
}

