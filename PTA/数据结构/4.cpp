#include <bits/stdc++.h>
using namespace std;
#define read_fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int sumUpTo(int n) {
    return n * (n + 1) / 2;
}

int main() {
    read_fast;
    int n;
    cin >> n;
    int sum1 = n * n * (n * n + 1) / 2;
    int sum2 = sumUpTo(n);
    int totalSum = sum1 + sum2;
    cout << totalSum << endl;
    return 0;
}