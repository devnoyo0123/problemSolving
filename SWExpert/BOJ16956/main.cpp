#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dRow[]={-1,0,1,0};
int dCol[]={0,1,0,-1};

int R,C;

int main() {
    cin >> R >> C;
    vector<string> a(R);
    for(int i=0; i<R; i++){
        cin>>a[i];
    }
    bool ok = true;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if( a[i][j] == 'S'){
                for(int k= 0; k <4; k++){
                    int nR = i + dRow[k];
                    int nC = j + dCol[k];
                    if( nR >=0 && nR < R && nC >=0  && nC < C){
                        if( a[nR][nC] == 'W'){
                            ok = false;
                        }
                    }
                }
            }
        }
    }

    if(ok){
        cout<<"1"<<'\n';
        for(int i=0; i<R; i++){
            for(int j=0; j< C; j++){
                if( a[i][j] == '.'){
                    cout<<'D'<<' ';
                }else{
                    cout<<a[i][j]<<' ';
                }
            }
            cout<<'\n';
        }
    }else{
        cout<<"0";
    }
    return 0;
}