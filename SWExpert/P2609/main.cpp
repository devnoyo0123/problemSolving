#include <cstdio>

int a,b,g;
long long l;

int gcd(int a, int b){
    if( b == 0){
        return a;
    }else{
        return gcd(b, a%b);
    }
}

int main() {
    scanf("%d %d",&a, &b);
    g = gcd(a,b);
    l = (a * b)/g;
    printf("%d\n", g);
    printf("%ld\n", l);
    return 0;
}