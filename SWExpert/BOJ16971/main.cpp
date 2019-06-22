#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;

const int MAX = 1000;

int a[MAX][MAX];
int cnt[MAX][MAX]; // a[i][j]가 배열에 몇번 세어졌는지 저장

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void swapRow(int r1, int r2){
    for(int i = 0; i<m; i++){
        swap(a[r1][i], a[r2][i]);
    }
}

void swapCol(int c1, int c2){
    for(int i = 0; i<m; i++){
        swap(a[i][c1], a[i][c2]);
    }
}

int calc(){
    int sum = 0;
    for(int i=0; i<n-1; i++){
        for(int j=0; j<m-1; j++){
            sum += a[i][j] + a[i+1][j] + a[i][j+1] + a[i+1][j+1];
        }
    }
    return sum;
}

int main() {

    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> a[i][j];
        }
    }

    vector<int> sumRow(n,0);
    vector<int> sumCol(m,0);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            sumRow[i] += a[i][j];
            sumCol[j] += a[i][j];
        }
    }

    int ans = calc();

    int minRow = -1;
    for(int i=1; i<n-1; i++){
        sumRow[i] = sumRow[i]*4;
        sumRow[i] -= 2*(a[i][0]+a[i][m-1]);
        if( minRow == -1 || sumRow[i] < sumRow[minRow]){
            minRow = i;
        }
    }

    int minCol = -1;
    for(int i=1; i<m-1; i++){
        sumCol[i] = sumCol[i]*4;
        sumCol[i] -= 2*(a[0][i]+a[n-1][i]);
        if( minCol == -1 || sumCol[i] < sumCol[minCol]){
            minCol = i;
        }
    }

    if(minRow != -1){
        swapRow(0, minRow);
        int cur = calc();
        if( cur > ans) ans = cur;
        swapRow(0, minRow);
        swapRow(n-1, minRow);
        cur = calc();
        if( cur > ans) ans = cur;
        swapRow(n-1, minRow);
    }

    if(minCol != -1){
        swapCol(0, minCol);
        int cur = calc();
        if( cur > ans) ans = cur;
        swapCol(0, minCol);
        swapCol(n-1, minCol);
        cur = calc();
        if( cur > ans) ans = cur;
        swapCol(n-1, minCol);
    }

    cout<<ans<<'\n';

    return 0;
}