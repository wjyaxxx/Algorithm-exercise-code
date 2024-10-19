#include <stdio.h>

const int N=10010;
int prime[N],cnt;
int num;
int ans;
bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

void getprime(){
    for(int i=2;i<=10000;i++){
        if(isPrime(i)) prime[cnt++]=i;
    }
}

void find(int num){
    
    for(int i=0;i<cnt;i++){
        int sum=0;
        for(int j=i;j<cnt;j++){
            sum+=prime[j];
            if(sum==num){
                ans++;
                break;
            }
        } 
    }
}
int main() {
    
    getprime();
    while (1) {
        scanf("%d", &num);
        if (num == 0) break;
        ans=0;
        find(num);
        printf("%d\n",ans);
        
    }
    return 0;
}