#include <bits/stdc++.h>
using namespace std;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
struct  node
{
    char date;
    node *l,*r;
    node(int val=0,node *lt=NULL,node*rt=NULL):date(val),l(lt),r(rt)
    {}
};
string in,pre;
string ans;
void bulid(int l,int r,int& rootid, node *&root)
{
   
    int k=0;
    while(in[k]!=pre[rootid]&&k<in.size())
        k++;
    if(k==in.size()) return ;
    
    root=new node;
    root->date=in[k];
    rootid++;
    //k就是根
    if(k>l) bulid(l,k-1,rootid,root->l);
    if(k<r) bulid(k+1,r,rootid,root->r);

}
void pos(node * root)
{
    if(root){
        pos(root->l);
        pos(root->r);
        ans+=root->date;
    }
}
int main()
{
        cinquick();
        cin>>in>>pre;
        int n=in.size();
        
        node * root;
        int t=0;
        bulid(0,n-1,t,root);
        pos(root);
        cout<<ans<<endl;
        return 0;
}