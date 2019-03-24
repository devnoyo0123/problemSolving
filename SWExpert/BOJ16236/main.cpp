#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int dRow[4] = {-1, 0, 1, 0};
int dCol[4] = {0, -1, 0, 1};

int num, ans;
int map[20][20];
bool check[20][20];

class Node {
public:
    int row;
    int col;
    int time; // 이동한 시칸
    int eat;  // 몇마리 잡은지 체크
    int size; // 상어 크기
    Node(int r, int c, int t, int e, int s) {
        this->row = r, this->col = c;
        this->time = t, this->eat = e;
        this->size = s;
    }

    bool operator<(const Node &node) const {
        if (this->time != node.time) {
            return this->time < node.time;
        } else {
            if (this->row != node.row) {
                return this->row < node.row;
            } else {

                return this->col < node.col;

            }
        }
    }
};

Node bShark(0, 0, 0, 0, 2);
vector<Node> list;
queue<Node> qu;

void BFS(Node &node) {


    while (true) {

        list.clear();
        memset(check, 0, sizeof(check));


        check[node.row][node.col] = true;
        qu.push(node);


        while (!qu.empty()) {
            Node temp = qu.front();
            qu.pop();

            int row = temp.row;
            int col = temp.col;
            int size = temp.size;
            int eat = temp.eat;
            int time = temp.time;

            for (int i = 0; i < 4; i++) {
                int nRow = row + dRow[i];
                int nCol = col + dCol[i];
                if (nRow < 0 || nRow == num || nCol < 0 || nCol == num) continue;
                if (map[nRow][nCol] > size) continue;
                if (check[nRow][nCol]) continue;

                check[nRow][nCol] = true;
                if (map[nRow][nCol] > 0 && map[nRow][nCol] < size) {

                    list.push_back(Node(nRow,nCol, time+1, eat+1, size));
                }else if (map[nRow][nCol] == 0 || map[nRow][nCol] == size){
                    qu.push(Node(nRow,nCol,time+1,eat,size));
                }
            }
        }

        if (list.size() == 0) {
            break;
        }

        sort(list.begin(), list.end());

        if( list[0].eat == list[0].size){
            list[0].eat = 0;
            list[0].size +=1;
        }

        map[list[0].row][list[0].col] = 0;
        ans += list[0].time;


        node.row = list[0].row;
        node.col = list[0].col;
        node.time = 0;
        node.eat = list[0].eat;
        node.size = list[0].size;

    }
}

int main() {

    cin >> num;

    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            cin >> map[i][j];
            if (map[i][j] == 9) {
                bShark.row = i;
                bShark.col = j;
                bShark.size = 2;
                map[i][j] = 0;
            }
        }
    }

    BFS(bShark);

    cout << ans << '\n';

    return 0;
}