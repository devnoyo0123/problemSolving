#include <iostream>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 21;

enum DIR{
    LEFT = 0,
    UP,
    RIGHT,
    DOWN
};

class Node{


public:
    int r,c,dir;

    Node(int row, int col, int curDir)
    {
        r = row, c = col, dir = curDir;
    }

};



int tc, val;
int ROW,COL;
bool flag;
int dlocation[][2] = {{0,-1},{1,0},{0,1},{-1,0}}; //r,c

char map[MAX][MAX];
bool check[MAX][MAX][4][16];


bool parser(Node &node){
    switch (map[node.r][node.c]){
        case '<':
            node.dir = LEFT;


            break;
        case 'v':
            node.dir = DOWN;


            break;
        case '>':
            node.dir = RIGHT;


            break;
        case '^':
            node.dir = UP;

            break;
        case '_':
            node.dir = val == 0 ? RIGHT : LEFT;
            break;
        case '|':
            node.dir = val == 0 ? DOWN : UP;
            break;
        case '?':
            return true;
        case '@':
            flag = true;
            break;
        case '.':
            break;
        case '+':

            val +=1;
            if( val > 15){
                val = 0;
            }
            break;
        case '-':
            val -=1;
            if( val < 0){
                val = 15;
            }
            break;
        default:

            val = map[node.r][node.c] - '0';
            break;
    }

    return false;
}



void solve(int row, int col, int dir){
    queue<Node> qu;
    Node newNode = Node(row,col,dir);
    if(parser(newNode)){
        for(int i=0; i<4; i++){


            int nRow = newNode.r + dlocation[i][0];
            int nCol = newNode.c + dlocation[i][1];

            if( nCol < 0 ){
                nCol = COL-1;
            }else if( nCol == COL){
                nCol = 0;
            }else if( nRow == ROW){
                nRow = 0;
            }else if( nRow < 0){
                nRow = ROW-1;
            }



            if(check[nRow][nCol][i][val])
                continue;

            Node nNode = Node(newNode);
            nNode.r = nRow;
            nNode.c = nCol;
            nNode.dir = i;
            check[nNode.r][nNode.c][nNode.dir][val] = 1;
            qu.push(nNode);
        }
    }else{
        switch (newNode.dir){
            case LEFT:
                newNode.c -=1;
                break;
            case UP:
                newNode.r -=1;
                break;
            case RIGHT:
                newNode.c +=1;
                break;
            case DOWN:
                newNode.r +=1;
                break;
        }


        if( newNode.c < 0 ){
            newNode.c = COL-1;
        }else if( newNode.c == COL){
            newNode.c = 0;
        }else if( newNode.r == ROW){
            newNode.r = 0;
        }else if( newNode.r < 0){
            newNode.r = ROW-1;
        }

        if(!check[newNode.r][newNode.c][newNode.dir][val]){
            Node nNode = Node(newNode);
            check[newNode.r][newNode.c][newNode.dir][val] = 1;
            qu.push(nNode);
        }

    }

    while(!qu.empty()){
        Node tmp = qu.front(); qu.pop();

        if(flag){
            return;
        }

        if(parser(tmp)){

            for(int i=0; i<4; i++){

                int nRow = tmp.r + dlocation[i][0];
                int nCol = tmp.c + dlocation[i][1];

                if( nCol < 0 ){
                    nCol = COL-1;
                }else if( nCol == COL){
                    nCol = 0;
                }else if( nRow == ROW){
                    nRow = 0;
                }else if( nRow < 0){
                    nRow = ROW-1;
                }

                if(check[nRow][nCol][i][val])
                    continue;

                Node nNode = Node(tmp);
                nNode.r = nRow;
                nNode.c = nCol;
                nNode.dir = i;
                check[nNode.r][nNode.c][nNode.dir][val] = 1;
                qu.push(nNode);
            }
        }else{
            switch (tmp.dir){
                case LEFT:
                    tmp.c -=1;
                    break;
                case UP:
                    tmp.r -=1;
                    break;
                case RIGHT:
                    tmp.c +=1;
                    break;
                case DOWN:
                    tmp.r +=1;
                    break;
            }


            if( tmp.c < 0 ){
                tmp.c = COL-1;
            }else if( tmp.c == COL){
                tmp.c = 0;
            }else if( tmp.r == ROW){
                tmp.r = 0;
            }else if( tmp.r < 0){
                tmp.r = ROW-1;
            }

            if(!check[tmp.r][tmp.c][tmp.dir][val]){
                Node nNode = Node(tmp);
                check[tmp.r][tmp.c][tmp.dir][val] = 1;
                qu.push(nNode);
            }


        }
    }




}


int main() {

    cin >> tc;

    for(int t = 1; t<=tc; t++){


        flag = false;
        val = 0;
        scanf("%d %d", &ROW, &COL);
        memset(map, 0, sizeof(map));
        memset(check, false, sizeof(check));


        for(int i = 0; i < ROW; i++){
            scanf("%s", map[i]);
        }


        solve(0,0,RIGHT);




        cout<<"#"<<t<<" "<< (flag ? "YES" : "NO") <<'\n';
    }


    return 0;
}