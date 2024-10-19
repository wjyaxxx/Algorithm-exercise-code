#include <bits/stdc++.h>
using namespace std;
#define read_fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int main() {
    read_fast;
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int m = a[0];
    int c = a[0];
    int s = 0;
    int e = 0;
    int t = 0;
    for (int i = 1; i < n; i++) {
        if (c + a[i] < a[i]) {
            c = a[i];
            t = i;
        } else {
            c += a[i];
        }
        if (c > m) {
            m = c;
            s = t;
            e = i;
        }
    }
    if (m < 0) {
        m = 0;
        s = -1;
        e = -1;
    }
    cout << m << endl;
    cout << s << " " << e << endl;
    return 0;
}