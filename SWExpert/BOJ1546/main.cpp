#include <cstdio>


using namespace std;

const int MAX = 1000;

int n, max1 = 0;

int a[MAX];

double ans;


int main() {

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        if( max1 < a[i]){
            max1 = a[i];
        }

    }




    for (int j = 0; j < n; ++j) {
        double tmp;
        tmp = (double)a[j]/max1 * 100;
        ans += tmp;
    }

    printf("%lf", ans/n);


    return 0;
}