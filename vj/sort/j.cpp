#include <bits/stdc++.h>
using namespace std;
const int N=310;
struct node
{
    int idx,a,b,c,score;

} q[N];
int n;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
bool cmp(node A,node B)
{
    if(A.score!=B.score) return A.score>B.score;
    if(A.a!=B.a) return A.a>B.a;
    return A.idx<B.idx;
}
int main()
{
        cinquick();
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            
            cin>>q[i].a>>q[i].b>>q[i].c;
            q[i].score=(q[i].a+q[i].b+q[i].c);
            q[i].idx=i;
        }
        sort(q+1,q+1+n,cmp);
        for(int i=1;i<=5;i++)
        {
            cout<<q[i].idx<<' '<<q[i].score<<endl;
        }
        return 0;
}