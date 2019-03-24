#include <iostream>

using namespace std;

int N;

int data1[100];
int giho[4];

int max1 = -987654321;
int min1 = 987654321;

void go(int plus, int minus, int mul, int div, int curidx, int result){

    if( curidx >= N){
        if( max1 < result){
            max1 = result;
        }

        if( min1 > result){
            min1 = result;
        }
        return;
    }

    if( plus > 0){
        go(plus-1, minus, mul, div, curidx+1, result + data1[curidx]);
    }

    if( minus > 0){
        go(plus, minus-1, mul, div, curidx+1, result - data1[curidx]);

    }

    if( mul > 0){
        go(plus, minus, mul-1, div, curidx+1, result * data1[curidx]);

    }

    if( div > 0){
        go(plus, minus, mul, div-1, curidx+1, result / data1[curidx]);

    }

}

int main() {

    cin >> N;

    for(int i=0; i< N; i++){
        cin >> data1[i];
    }


    for(int i=0; i<4; i++){
        cin >> giho[i];
    }

    go(giho[0],giho[1],giho[2],giho[3], 1, data1[0]);

    cout<< max1<<'\n';
    cout<< min1;


    return 0;
}