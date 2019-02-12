#include <iostream>

using namespace std;

#define MAX 10

int tc, n, ans;
int map[MAX][MAX];

bool check(int row, int col){
    // 대각선 체크

    int tmpRow = row;
    int tmpCol = col;

    while(tmpRow >= 0 && tmpCol >= 0){
        if(map[tmpRow][tmpCol]){
            return false;
        }

        tmpRow-=1;
        tmpCol-=1;
    }

    tmpRow = row;
    tmpCol = col;
    while(tmpRow >=0 && tmpCol < n){
        if(map[tmpRow][tmpCol]){
            return false;
        }

        tmpRow-=1;
        tmpCol+=1;
    }

    for(int i=0; i<n; i++){
        if( map[i][col]){
            return false;
        }
    }

    for(int i=0; i<n; i++){
        if( map[row][i]){
            return false;
        }
    }


    return true;
}

void solve(int row, int col){
    if( row == n){
        ans++;
        return;
    }

    if( col == n){
        col = 0;
        row += 1;
    }



    for(int i=0; i<n; i++){
        if( check(row, i)){
            // Queen 둔다.
            map[row][i] = 1;
            solve(row+1, i );
            map[row][i] = 0;
        }
    }




}


int main() {

    cin >> tc;
    for(int t = 1; t<=tc; t++){
        ans = 0;

        cin >> n;

        solve(0,0);


        cout<<"#"<<t<<" "<<ans<<'\n';
    }



    return 0;
}