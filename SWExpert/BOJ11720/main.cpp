#include<cstdio>

int main(){
    int n, num, sum =0;
    scanf("%d", &n);
    while(n--){
        scanf("%1d", &num);
        sum += num;
    }
    printf("%d\n",sum);
    return 0;
}