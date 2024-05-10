#include <bits/stdc++.h>
using namespace std;
int n,c;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
int main()
{
        cinquick();
        cin>>n>>c;
        priority_queue<int> q;
        int res=0;//先把该安排的需要的教室数
        for(int i=1;i<=n;i++)
        {
            string str;
            cin>>str;
            int x;
            cin>>x;
            int num=(x+c-1)/c;
            res+=(x/c);
            cout<<str<<' '<<num<<endl;
            if(x%c) q.push(x%c);
        }
          vector<int> vec;
          //先把大的排号，贪心想，如果先排小的会产生大的空不好排
    while (!q.empty()) {
        int t = q.top();
        
        q.pop();
        bool flag = false;
        for (int i = 0; i < vec.size(); i++) {
             if (c- vec[i] >= t) {
                flag = true;
                vec[i] += t;
                break;
            }
        }
        if (!flag) {
            vec.push_back(t);
            res++;
        }
    }
    cout << res;
        return 0;
}