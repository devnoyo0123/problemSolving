#include <cstdio>
#include <cmath>

const int MAX = 10;

double a1[MAX+1];
double b1[MAX+1];
int testCase;
int num;
int cnt;

double myBinarySearch(double left, double right, double jum){

//    printf("left: %lf, right: %lf, jum: %lf\n", left, right, jum);
    double tempF = 0;
    for (int i = 0; i < num; ++i) {
        double dist = fabs(a1[i] - jum);

        if( a1[i] < jum ){
            tempF += b1[i] / (dist * dist);
        }else if( a1[i] > jum){
            tempF -= b1[i] / (dist * dist);
        }
    }

    if( fabs(right - left) < 1e-13 || cnt++ > 30){
        return jum;
    }

    if( tempF <= 0){
        return myBinarySearch(left, jum, (left+jum)/2);
    }else{
        return myBinarySearch(jum, right, (jum+right)/2);
    }
}

int main() {

    scanf("%d", &testCase);
    for (int i = 1; i <= testCase; ++i) {
        scanf("%d", &num);
        for (int j = 0; j < num ; ++j) {
            scanf("%lf", &a1[j]);
        }

        for (int j = 0; j < num; ++j) {
            scanf("%lf", &b1[j]);
        }

        printf("#%d ",i);
        for (int j = 0; j < num-1 ; ++j) {
            double ret = myBinarySearch(a1[j], a1[j+1], (a1[j]+a1[j+1])/2);
            printf("%.10lf ", ret);
        }
        printf("\n");
    }
    return 0;
}