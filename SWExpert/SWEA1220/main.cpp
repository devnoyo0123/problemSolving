#include <iostream>
#include <cstring>
#include <deque>

enum WAY1{
    N = 1,
    S = 2
};

using namespace std;

const int MAX = 100;

int n;

int map[MAX][MAX];
int ans = 0;
int tc;

void solve(){

    for (int i = 0; i < n; ++i) {
        //열 반복
        deque<int> dQ;
        for (int j = 0; j < n; ++j) {
            if( map[j][i] > 0){
                dQ.push_back(map[j][i]);
            }
        }


        while(!dQ.empty()){
            int front = dQ.front();
            if( front == N){
                break;
            }else{
                dQ.pop_front();
            }
        }

        while(!dQ.empty()){
            int back = dQ.back();
            if( back == S){
                break;
            }else{
                dQ.pop_back();
            }
        }

        int size = (int)dQ.size();
        int tmp[MAX] = {0,};
        int inx = 0;
        while(!dQ.empty()){
            tmp[inx++] = dQ.front();
            dQ.pop_front();
        }

//        cout<<"size:"<<size<<"\n";
//        for (int k = 0; k < size; ++k) {
//            cout<<"tmp["<<k<<"]"<<": "<<tmp[k]<<" ";
//        }
//        cout<<"\n";

        for (int i1 = 0; i1+1 < size; ++i1) {
            if( tmp[i1] == N && tmp[i1+ 1] == S){
                ans +=1;
            }
        }

    }
}


int main() {


    for (int t = 1; t <=10 ; ++t) {

        cin >> n;
        ans = 0;
        memset(map, 0, sizeof(map));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> map[i][j];
            }
        }

        solve();

        cout << "#" <<t<<" " << ans << '\n';
    }

    return 0;
}


