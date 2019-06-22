#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 100;

int H, W, N;
int r[MAX], c[MAX];
int ans;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int main() {

    cin >> H >> W >> N;

    for(int i=0; i<N; i++){
        cin >> r[i] >> c[i];
    }

    for(int i=0; i<N; i++){
        int r1 = r[i],  c1 = c[i];
        for(int j=i+1; j<N; j++){
            int r2 = r[j] , c2 = c[j];
            for(int i1 = 0; i1<2; i1++){
                for(int i2= 0; i2< 2; i2++){
                    if( r1 + r2 <= H && max(c1,c2)<=W){
                        int temp = r1*c1+ r2*c2;
                        if( ans < temp) ans = temp;
                    }

                    if( r1 + r2 <= W && max(c1,c2)<=H){
                        int temp = r1*c1+ r2*c2;
                        if( ans < temp) ans = temp;
                    }
                    swap(r2,c2);
                }
                swap(r1,c1);

            }
        }
    }

    cout<< ans<<'\n';

    return 0;
}