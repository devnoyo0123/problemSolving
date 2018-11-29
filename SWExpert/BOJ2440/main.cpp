#include <cstdio>

int a;

int main(){

    scanf("%d", &a);

    for(int i=a; i>=0; i--){

        for(int j =1; j<=i; j++){

            printf("*");
        }

        printf("\n");
    }

}
