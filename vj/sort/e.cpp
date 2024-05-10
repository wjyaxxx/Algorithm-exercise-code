#include <bits/stdc++.h>
using namespace std;
const int N=110;
struct student
{
    string name;
    int cnt;
    int idx;
}q[N];
int n;

void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
bool cmp(student a,student b)
{
    if(a.cnt!=b.cnt)return a.cnt>b.cnt;
    return a.idx<b.idx;
}
int main()
{
        cinquick();
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>q[i].name;
            q[i].idx=i;
            int avg_score,class_score,cnt;
            string gan,xi;
            cin>>avg_score>>class_score>>gan>>xi>>cnt;
            if(avg_score>80&&cnt>=1)  q[i].cnt+=8000;
            if(avg_score>85&&class_score>80) q[i].cnt+=4000;
            if(avg_score>90) q[i].cnt+=2000;
            if(avg_score>85&&xi=="Y")
                q[i].cnt+=1000;
            if(class_score>80&&gan=="Y") q[i].cnt+=850;
        }

        sort(q+1,q+1+n,cmp);

        cout<<q[1].name<<endl;
        cout<<q[1].cnt<<endl;
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            sum+=q[i].cnt;
        }
        cout<<sum<<endl;
        return 0;
}