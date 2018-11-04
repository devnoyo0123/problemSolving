#include <iostream>

using namespace std;

int n;

int main() {

    cin >> n;
    int a = n-1;
    int b = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= a; ++j) {
            printf(" ");
        }
        a--;
        for (int k = 1; k <=b ; ++k) {
            printf("*");
        }
        b++;
        printf("\n");
    }
    return 0;
}