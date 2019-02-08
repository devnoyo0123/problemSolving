#include <iostream>
#include <cstring>

using namespace std;

int num, ans;
int w[10][10];
bool check[10];

void DFS(int startNode, int curNode,int depth, int val){

    if( depth >= num){
        if( w[curNode][startNode] > 0 && val + w[curNode][startNode] < ans){

            ans = val + w[curNode][startNode];
        }
        return;
    }



    for (int i = 0; i < num; ++i) {
        if( i == curNode || check[i] || w[curNode][i] == 0){
            continue;
        }

        if( val + w[curNode][i] > ans){
            continue;
        }

        check[i] = true;
        DFS(startNode, i, depth+1, val+w[curNode][i]);
        check[i] = false;

    }

}

int main() {

    cin >> num;
    ans = 987654321;

    for(int i=0; i<num; i++){
        for (int j = 0; j < num; ++j) {
            cin >> w[i][j];
        }
    }

    for (int k = 0; k < num; ++k) {
        memset(check, 0, sizeof(check));
        check[k] = true;
        DFS(k, k, 1, 0);
        check[k] = false;
    }

    cout<< ans<<'\n';



    return 0;
}