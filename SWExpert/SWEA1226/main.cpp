#include <iostream>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

class Node{
public:
    int r,c;

    Node(){
        r = 0, c =0;
    }

    Node(int row, int col){
        r = row, c = col;
    }
};

char map[16][16];

int dlocation [][2] = {{0,-1},{-1,0},{0,1},{1,0}};
int temp;


void bfs(int row, int col){
    queue<Node> qu;
    Node newNode = Node(row, col);
    qu.push(newNode);

    while(!qu.empty()){
        Node temp = qu.front(); qu.pop();
        for(int i=0; i<4; i++){
            int nRow = temp.r + dlocation[i][0];
            int nCol = temp.c + dlocation[i][1];

            if( nRow < 0 || nRow == 16 || nCol <0 || nCol == 16){
                continue;
            }

            if( map[nRow][nCol] == '1' || map[nRow][nCol] == '2'){
                continue;
            }

            map[nRow][nCol] = '2';
            Node newNode = Node(nRow, nCol);
            qu.push(newNode);
        }
    }
}

int main() {
    Node start,end;
    string tmpStr = "";
    for(int t= 1; t<=10; t++){

        memset(map, 0, sizeof(map));

        cin >> temp;

        for(int i=0; i<16; i++){
            cin >>tmpStr;
            int length = tmpStr.size();
            for (int j = 0; j < length; ++j) {
                map[i][j] = tmpStr[j];
                int point = map[i][j];
                if( point == '2'){
                    start = Node(i,j);
                }else if( point == '3'){
                    end = Node(i,j);
                }
            }
        }

        bfs(start.r,start.c);
        if( map[end.r][end.c] == '2'){
            cout<<"#"<<t<<" "<<1<<'\n';
        }else{
            cout<<"#"<<t<<" "<<0<<'\n';
        }
    }

    return 0;
}