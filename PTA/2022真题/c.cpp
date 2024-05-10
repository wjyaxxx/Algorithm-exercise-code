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
        //cinquick();
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        if(c>d){
            if(c>=b&&d<a){
                printf("%d-Y %d-Y\n",c,d);
                printf("qing %d zhao gu hao %d",1,2);
            }
            else if(c>=a&&d>=a){
                printf("%d-Y %d-Y\n",c,d);
                printf("huan ying ru guan");
            }
            else if(c<a&&d<a){
                printf("%d-N %d-N\n",c,d);
                printf("zhang da zai lai ba");
            }
            else{
                printf("%d-Y %d-N\n",c,d);
                printf("%d: huan ying ru guan",1);
            }
        }
        else {
            
             if(d>=b&&c<a){
                printf("%d-Y %d-Y\n",c,d);
                printf("qing %d zhao gu hao %d",2,1);
            }
            else if(d>=a&&c>=a){
                printf("%d-Y %d-Y\n",c,d);
                printf("huan ying ru guan");
            }
            else if(c<a&&d<a){
                printf("%d-N %d-N\n",c,d);
                printf("zhang da zai lai ba");
            }
            else{
                printf("%d-N %d-Y\n",c,d);
                printf("%d: huan ying ru guan",2);
            }
        }
        return 0;
}