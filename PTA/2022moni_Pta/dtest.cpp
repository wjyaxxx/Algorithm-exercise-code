#include<stdio.h>
using namespace std;

int isPrime(int n)
{
    if(n<2) return 0;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0) return 0;
    }
    return 1;
}
 
int main()
{
    int m,n,sum=0;
    scanf("%d %d",&m,&n);
    for(int i=m;i<=n;i++)
    {
        if(isPrime(i)) a[t++] = i;
    }
    for(int i=0;i<t;i++)
    {
        for(int j=i+1;j<t;j++)
        {
            for(int k=j+1;k<t;k++)
            {
                int p,q,r;
                p = a[i]*a[j]+a[k];
                q = a[i]*a[k]+a[j];
                r = a[j]*a[k]+a[i];
                if(isPrime(p)&&isPrime(q)&&isPrime(r))
                {
                     sum++;
                }
            }
        }
    }
    printf("%d",sum);
}