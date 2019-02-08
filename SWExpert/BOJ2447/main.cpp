#include <iostream>

using namespace std;

enum COLOR{
    STAR,
    BLANK
};

int n;

char arr[2187+10][2187+10];

void go(int size, int stRow, int stCol, int endRow, int endCol, int color){

    if( size <= 3){

        if( color == STAR){
            for(int i=stRow; i<endRow; i++){
                for(int j=stCol; j<endCol; j++){
                    if( i % 3 == 1 && j % 3 ==1){
                        arr[i][j] = ' ';
                    }else{
                        arr[i][j] = '*';
                    }
                }
            }
        }else{
            for(int i=stRow; i<endRow; i++){
                for(int j=stCol; j<endCol; j++){

                    arr[i][j] = ' ';

                }
            }
        }


        return;
    }

    int next = size/3;



    go(next, stRow, stCol, endRow - next*2, endCol- next*2 ,color);
    go(next, stRow, stCol+ next, endRow - next*2, endCol- next,color);
    go(next, stRow, stCol+ next*2, endRow - next*2, endCol,color);

    go(next, stRow+ next, stCol, endRow - next, endCol- next*2,color);
    go(next, stRow+ next, stCol+ next, endRow - next, endCol- next,BLANK);
    go(next, stRow+ next, stCol+ next*2, endRow - next, endCol,color);

    go(next, stRow+ next*2, stCol, endRow, endCol- next*2,color);
    go(next, stRow+ next*2, stCol+ next, endRow, endCol- next,color);
    go(next, stRow+ next*2, stCol+ next*2, endRow, endCol,color);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    go(n,0,0,n,n,STAR);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<arr[i][j];
        }
        cout<<'\n';
    }

    return 0;
}