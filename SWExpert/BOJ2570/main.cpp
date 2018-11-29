#include <iostream>

using namespace std;

const int MAX = 100;

int N,M;

int ans, ans1, ans2;

bool check[MAX*2+1];
bool check2[MAX*2+1];
int map[MAX][MAX]; // 패딩을 위해서 상하좌우 배열크기 조절


void black(int row, int col, int cnt){
    if( row == N+1){
        if( ans2 < cnt){
            ans2 = cnt;
        }
        return;
    }

    if( col >= N+1){
        row+=1;
        if( row % 2 == 0){
            col = 0;
        }else{
            col = 1;
        }
    }

    if( map[row][col] == 0 && !check[row+col] && !check2[MAX-(row-col)]){
        check[row+col] = true; // 비숍두기
        check2[MAX-(row-col)] = true;
        black(row, col+2, cnt+1);
        check[row+col] = false; // 비숍두기
        check2[MAX-(row-col)] = false;
    }

    black(row,col+2, cnt);

}

void white(int row, int col, int cnt){
    if( row == N+1){
        if( ans1 < cnt){
            ans1 = cnt;
        }
        return;
    }

    if( col >= N+1){
        row+=1;
        if( row % 2 == 0){
            col = 1;
        }else{
            col = 0;
        }
    }

    if( map[row][col] == 0 && !check[row+col] && !check2[MAX-(row-col)]){
        check[row+col] = true;
        check2[MAX-(row-col)] = true;
        white(row, col+2, cnt+1);
        check[row+col] = false;
        check2[MAX-(row-col)] = false;
    }

    white(row,col+2, cnt);

}


int main() {

    cin >> N >> M;

    for (int i = 0; i < M; ++i) {
        int a,b;
        cin >> a >> b;
        map[a][b] = -1;  // 장애물도 패딩과 같게 둠.
    }

    white(0,0,0);


    black(0,1,0);


    cout<< ans1+ ans2<<'\n';

    return 0;
}