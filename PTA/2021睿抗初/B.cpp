#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;
typedef pair<int, int> PLL;
typedef long long LL;

int n, s;
LL x, y;
map<PLL, vector<pair<LL, int>>> mp;

int main()
{
    scanf("%d", &n);
    int sum = 0, cnt = 0;

    for(int i = 0; i < n; i++)
    {
        scanf("%lld %lld %d", &x, &y, &s);
        sum += s;

        LL d = x * x + y * y;
        LL c = abs(__gcd(x, y));
        

        x /= c, y /= c;
        mp[{x, y}].push_back({d, s});
    }
    
    for(auto x : mp)
    {
        vector<pair<LL, int>> v = x.second;
        sort(v.begin(), v.end());

        for(int i = 0; i < v.size(); i++)
        {
            if(v[i].second != 1)
                cnt++;
            else
            {
                if((i + 1 < v.size() && v[i + 1].second != 1) || i + 1 == v.size())
                    cnt++;
            }
        }
    }

    printf("%d %d\n", sum , cnt);
    return 0;
}
