#include <bits/stdc++.h>
using namespace std;
const int N=1100;
int h[N];//每个矩形的高
int n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>h[i];
    //单调栈(这里我们用stl库来写，当然还可以用数组写法，但是不推荐指针写法）

    stack<int> s;//建立一个栈
    int ans=0;
    for(int i=1;i<=n;i++){
        while(!s.empty()&&h[s.top()]>h[i]){
            //当栈顶元素比当前元素大，说明当前元素是栈顶元素右边第一个比他小的
            int idx=s.top();
            s.pop();
            //s中保持单调递增，则s弹出后，栈顶元素就是左边第一个比它小的
            int idxl;
            if(!s.empty()) idxl=s.top();
            else idxl=0;
            //cout<<idxl<<' '<<idx<<' '<<i<<endl;
            ans=max(ans,(i-idxl-1)*h[idx]);
        }
        s.push(i);
    }
    cout<<ans<<endl;
    return 0;
}