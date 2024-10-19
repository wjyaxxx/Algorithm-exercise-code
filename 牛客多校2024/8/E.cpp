#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define all(x) (x).begin(),(x).end()
typedef long long ll;
ll f(ll x){
    ll sum=0;
    while(x){
        sum+=x%10;
        x/=10;
    }
    return sum;
}
typedef pair<ll,int> Pll;

vector<Pll> factdiv;

//快速分解质因数模板

using ull=unsigned long long;
ull modmul(ull a, ull b, ull M) {
ll ret = a * b - M * ull(1.L / M * a * b);
return ret + M * (ret < 0) - M * (ret >= (ll)M);
}
ull modpow(ull b, ull e, ull mod) {
ull ans = 1;
for (; e; b = modmul(b, b, mod), e /= 2)
if (e & 1) ans = modmul(ans, b, mod);
return ans;
}

bool isPrime(ull n) {
if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
    s = __builtin_ctzll(n-1), d = n >> s;
for (ull a : A) {   // ^ count trailing zeroes
ull p = modpow(a%n, d, n), i = s;
while (p != 1 && p != n - 1 && a % n && i--)
p = modmul(p, p, n);
if (p != n-1 && i != s) return 0;
}
return 1;
}
 
ull pollard(ull n) {
auto f = [n](ull x) { return modmul(x, x, n) + 1; };
ull x = 0, y = 0, t = 30, prd = 2, i = 1, q;
while (t++ % 40 || __gcd(prd, n) == 1) {
if (x == y) x = ++i, y = f(x);
if ((q = modmul(prd, max(x,y) - min(x,y), n))) prd = q;
x = f(x), y = f(f(y));
}
return __gcd(prd, n);
}
vector<ull> factor(ull n) {
if (n == 1) return {};
if (isPrime(n)) return {n};
ull x = pollard(n);
auto l = factor(x), r = factor(n / x);
l.insert(l.end(), all(r));
return l;
}
//
unordered_set<ll> s;
void dfs(int u,ll fact){
    if(u >= factdiv.size()){
        s.insert(fact);
        return ;
    }
    
    int cnt=factdiv[u].second;
    for(int i=0;i<=cnt;i++){
        ll res=1;
        for(int j = 1;j<=i;j++) res*=factdiv[u].first;
        dfs(u+1,fact*res);
    } 
    
}
void print(int i,int k){
    cout<<"("<<i<<','<<k<<')'<<"\n";
}
unordered_set<ll> s1;

void solve()
{
    ll n;
    cin>>n;
    ll ans=0;
    s1.clear();
    for(int i=1;i<min(n,110ll);i++){
        factdiv.clear();
        
        auto divn=factor(n-i);
        
        map<ull,int> mp;
        for(auto x:divn) mp[x]++;
        for(auto [x,y] : mp){
            factdiv.push_back({x,y});
        }
        s.clear();
        dfs(0,1ll);
        for(auto x:s){
            if(f(x)==i && n%x== i) {
                //print(x,n-i);
                s1.insert(x);
            }
        }
        //cout<<"\n----------------\n";
    }
   cout<<s1.size()<<"\n";
}
int main()
{
    read_fast;
    int t;
    cin>>t;
    while(t--) solve();
    
    return 0;
}