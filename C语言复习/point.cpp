#include <bits/stdc++.h>
using namespace std;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}

#include <stdio.h>
int main()
{
 char *c[] = {"ENTER","NEW","POINT","FIRST"};
 char**cp[] = {c+3,c+2,c+1,c};
 char***cpp = cp;
 printf("%s\n", **++cpp);
 printf("%s\n", *--*++cpp+3);
 printf("%s\n", *cpp[-2]+3);
 printf("%s\n", cpp[-1][-1]+1);
 return 0; }