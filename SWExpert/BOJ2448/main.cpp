#include <cstdio>

using namespace std;

int n;
char arr[3072][6144];

void go(int height, int row, int col){
    if( height == 3){
        arr[row][col] = '*';
        arr[row+1][col-1] = '*';
        arr[row+1][col+1] = '*';
        for(int i=col-2; i<=col+2; i++){
            arr[row+2][i] = '*';
        }
        return;
    }

    int next = height/2;
    go(next, row, col);
    go(next, row + next, col - next );
    go(next, row + next, col + next );
}

int main() {

    scanf("%d", &n);

    for(int i=0; i<n; i++){
        for(int j=0; j< n+n; j++){
            arr[i][j] = ' ';
        }

    }

    go(n, 0, n-1);

    for(int i=0; i<n; i++){
        for(int j=0; j< n+n-1; j++){
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}