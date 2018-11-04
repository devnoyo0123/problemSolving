#include <iostream>

const int MAX = 20;

using namespace std;

int map[MAX][MAX];
int choice[MAX];
int n, ans = 987654321;

int calc(){
    int linkTeam = 0;
    int startTeam = 0;
    int ret = 0;

    for (int i = 0; i < n; ++i) {
        if( choice[i] == 1){
            for (int j = 0; j < n; ++j) {
                if( i == j ){
                    continue;
                }

                if(choice[j] == 1){
                    linkTeam += map[i][j];

                }
            }
        }else if( choice[i] == 2){
            for (int j = 0; j < n; ++j) {
                if( i == j){
                    continue;
                }


                if( choice[j] == 2){
                    startTeam += map[i][j];

                }
            }
        }
    }

    ret = linkTeam - startTeam;
    if( ret < 0){
        ret *= -1;
    }

    return ret;
}

void solve(int link, int start, int inx){

    if( inx == n){
        int tmp = calc();
        if( ans > tmp){
            ans = tmp;
        }
        return;
    }

    if( link > n/2){
        return;
    }

    if( start > n/2){
        return;
    }

    choice[inx] = 1;
    solve(link+1, start, inx+1);
    choice[inx] = 2;
    solve(link, start+1, inx+1);
}

int main() {

    cin >> n;

    for (int i = 0; i < n ; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> map[i][j];
        }
    }

    solve(0,0,0);

    cout<<ans<<'\n';

    return 0;
}