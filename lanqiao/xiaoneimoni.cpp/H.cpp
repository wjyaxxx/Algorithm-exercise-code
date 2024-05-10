#include <cstdio>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
const int N=1010;
int a[N];

int main()
{
      int n;
      cin>>n;
      for(int i=0;i<n;i++) scanf("%d",&a[i]);

        int maxv=0,minv=1e8;
        for(int i=1;i<n-1;i++)
        {
            if(a[i]<a[i-1]&&a[i]<a[i+1])
                maxv=max(maxv,a[i]);
            if(a[i]>a[i-1]&&a[i]>a[i+1])
                minv=min(minv,a[i]);
        }

        printf("%d %d\n",maxv,minv);

    return 0;
}