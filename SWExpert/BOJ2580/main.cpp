#include <iostream>
#include <vector>

using namespace std;

int map[10][10];

bool flag;
vector<pair<int, int> > list;
vector<bool> check;

bool checkSquare(int row, int col, int num) {

    int tempRow = (row / 3) * 3;
    int tempCol = (col / 3) * 3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (map[i + tempRow][j + tempCol] == num) {
                return true;
            }
        }
    }
    return false;
}

bool colCheck(int col, int num) {

    for (int i = 0; i < 9; i++) {
        if (map[i][col] == num) {
            return true;
        }
    }
    return false;
}

bool rowCheck(int row, int num) {

    for (int i = 0; i < 9; i++) {
        if (map[row][i] == num) {
            return true;
        }
    }
    return false;
}

void go() {

    if(check[list.size()-1]){

        flag = true;

        return;
    }

    for (int k = 0; k < list.size(); ++k) {

        if( check[k]){
            continue;
        }

        int row = list[k].first;
        int col = list[k].second;


        for (int i = 1; i < 10; i++) {


            if (rowCheck(row, i))
                continue;
            if (colCheck(col, i))
                continue;
            if (checkSquare(row, col, i)) {
                continue;
            }

            check[k] = true;
            map[row][col] = i;

            go();

            if(flag){
                return;
            }

            map[row][col] = 0;
            check[k] = false;
        }


    }

}

int main() {

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> map[i][j];
            if (map[i][j] == 0) {
                list.push_back({i, j});
            }
        }
    }

    check.resize(list.size());

    go();

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << map[i][j] << " ";
        }
        cout << '\n';
    }


    return 0;
}