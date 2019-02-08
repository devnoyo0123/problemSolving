#include <iostream>
#include <vector>

using namespace std;

const int MAX = 50;

vector<pair<int,int> > points;
vector<int> sum;

int map[MAX][MAX];
bool check[MAX][MAX];
int N,L,R,ans;

int dLcation[][2]={{-1,0},{0,1},{1,0},{0,-1}};

void DFS(int row, int col){

    if( check[row][col]){
        return;
    }

    for(int i=0; i<4; i++){
        int nRow = dLcation[i][0];
        int nCol = dLcation[i][1];

        if( nRow >=0 && nRow < N && nCol >= 0 && nCol <N){
            if(!check[nRow][nCol]) {
                int diff = map[row][col] - map[nRow][nCol];
                if (diff < 0) {
                    diff = -diff;
                }

                if (L <= diff && diff <= R) {
                    check[nRow][nCol] = true;
                    sum.push_back(map[nRow][nCol]);
                    points.push_back({nRow,nCol});
                    DFS(nRow, nCol);
                }
            }
        }

    }
}

int main() {

    cin >> N >> L >> R;



    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> map[i][j];
        }
    }

    while(true){
        memset(check, 0, sizeof(check));
        int i,j;
        for (i = 0; i < N; ++i) {
            for (j = 0; j < N; ++j) {
                if(!check[i][j]){
                    check[i][j] = true;
                    points.push_back({i,j});
                    sum.push_back(map[i][j]);
                    DFS(i,j);
                }

                if( sum.size() == 1){
                    cout<<ans<<'\n';
                    return 0;
                }else{
                    int tempSum = 0;
                    for(int i=0; i<sum.size(); i++){
                        tempSum += sum[i];
                    }
                    int avg = tempSum/sum.size();
                    for (int j = 0; j < points.size(); ++j) {
                        int row = points[j].first;
                        int col = points[j].second;

                        map[row][col] = avg;
                    }

                    if( sum.size() > 1){
                        ans++;
                    }

                    for (int k = 0; k < N; ++k) {
                        for (int l = 0; l < N; ++l) {
                            cout<<map[k][l]<<" ";
                        }
                        cout<<'\n';
                    }

                    sum.clear();
                    points.clear();

                }

            }
        }



    }


}