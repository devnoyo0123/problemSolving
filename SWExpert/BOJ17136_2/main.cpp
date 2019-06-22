#include <iostream>

using namespace std;
const int MAX = 10;

int a[MAX][MAX];
int jonge[6] = {0,5,5,5,5,5};

int go(int pos){
    if( pos == MAX*MAX){
        for(int i=0; i<MAX; i++){
            for(int j=0; j<MAX; j++){
                if( a[i][j] == 1){
                    return -1;
                }
            }
        }
        return 0;
    }

    int row = pos/MAX;
    int col = pos%MAX;

    if( a[row][col] == 0){
        return go(pos+1);
    }

    int ans = -1;

    for(int k=5; k>0; k--){
        if( jonge[k] > 0){
            bool ok = true; //색종이 붙였다고 가정

            if( row + k -1 <MAX && col + k -1 <MAX){
                for(int i=row; i<row + k; i++){
                    for(int j=col; j <col + k; j++){
                        if( a[i][j] == 0){
                            //0이면 색종이 못붙이니까
                            ok = false;
                            break;
                        }
                    }

                }
                if(ok){
                    for(int i = row; i< row + k; i++){
                        for(int j=col; j< col + k; j++) {
                            a[i][j] = 0;
                        }
                    }

                    jonge[k] -=1;
                    int res = go(pos+1);

                    if( res != -1){
                        if( ans == -1 || ans > res + 1 ){
                            ans = res + 1;
                        }
                    }

                    jonge[k] +=1;
                    for(int i = row; i< row + k; i++){
                        for(int j=col; j< col + k; j++) {
                            a[i][j] = 1;
                        }
                    }
                }
            }
        }
    }

    return ans;
}

int main() {

    for(int i=0; i<MAX; i++){
        for(int j=0; j< MAX; j++){
            cin>> a[i][j];
        }
    }

    cout<< go(0);
    return 0;
}