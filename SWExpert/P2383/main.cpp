#include <iostream>

using namespace std;

const int NMAX = 11;
const int PMAX = 11;

int N, TC, ans;

struct Person {
    int No;
    int row;
    int col;
    int stairNo;
    int dist;

};

struct Stair {

    int row;
    int col;
    int curPersonNo[3][2];

};

Person p[PMAX];
Stair s[2];

int pSize = 1;
int sSize = 1;

void getDist(int inx){
    if( p[inx].stairNo == 1){
        int temp1 = abs( p[inx].row - s[1].row );
        int temp2 = abs( p[inx].col - s[1].col );
        int dist = temp1+temp2;
        p[inx].dist = dist;
    }else if( p[inx].stairNo == 2){
        int temp1 = abs( p[inx].row - s[2].row );
        int temp2 = abs( p[inx].col - s[2].col );
        int dist = temp1+temp2;
        p[inx].dist = dist;
    }
}

void simulate(){
    for (int i = 1; i <=  pSize; ++i) {
        getDist(i);
    }

    sort(p, p+pSize);
    for (int j = 1; j <= pSize; ++j) {
        cout<<p[j].dist<<" ";
    }
    cout<<"\n";
}

void go(int inx, int Size){


    if( inx > Size){
        simulate();
        return;
    }

    go(inx + 1, p[inx].stairNo = 1);
    go(inx + 1, p[inx].stairNo = 2);


}

int main() {

    cin >> TC;
    for (int T = 1; T <= TC; ++T) {
        cin >> N;
        pSize = 0;
        sSize = 0;
        ans = 0;

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                int tmp = 0;
                cin >> tmp;
                if (tmp == 1) {
                    Person tmpp;
                    tmpp.row = i;
                    tmpp.col = j;
                    tmpp.No = pSize;
                    tmpp.stairNo = 0;
                    tmpp.dist = 0;

                    p[pSize++] = tmpp;
                } else if (tmp > 1) {
                    Stair tmps;
                    tmps.row = i;
                    tmps.col = j;

                    s[sSize++] = tmps;
                }
            }
        }

        go(1, pSize);

        cout<<"#"<<T<<" "<<ans<<"\n";

    }
    return 0;
}