#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int n,m;
const int N= 100010;
struct node{
    int price,score;
}p[N],q[N];
bool operator<( node a,node b){
    if(a.score!=b.score)
        return a.score>b.score;
    
}


int main()
{
        //cinquick();
        while(~scanf("%d%d",&n,&m)){
            for(int i=1;i<=n;i++)scanf("%d%d",&p[i].price,&p[i].score);
            for(int i=1;i<=m;i++) scanf("%d%d",&q[i].price,&q[i].score);
            
            sort(p+1,p+1+n);
            sort(q+1,q+1+m);
            
            long long ans=0;
            multiset<int> s;
            bool ok=false;
            for(int i=1,j=1;i<=n;i++){
                while(q[j].score>=p[i].score&&j<=m) s.insert(q[j++].price);//这些都是精美度符合条件的
                multiset<int>::iterator it;
                it=s.lower_bound(p[i].price); 
                if(it!=s.end()){
                    ans+=*it;
                    s.erase(it);
                    
                }
                else {
                    ok=true;
                    break;
                }   
            }
            if(ok) printf("-1\n");
            else printf("%lld\n",ans);
        }
        return 0;
}