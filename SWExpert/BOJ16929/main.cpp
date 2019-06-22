#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int dRow[] = {-1, 0, 1, 0};
int dCol[] = {0, 1, 0, -1};


int main() {

    int n, m;
    bool ok = false;

    cin >> n >> m;
    vector<string> a(n);
    vector<vector<int> > d(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    queue<pair<int, int> > q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            if (ok) {
                continue;
            }
            if (d[i][j] == -1) {
                q.push(make_pair(i,j));
                d[i][j] = 0;

                while (!q.empty()) {
                    pair<int, int> tmp = q.front();
                    q.pop();

                    for (int l = 0; l < 4; l++) {
                        int nR = tmp.first + dRow[l];
                        int nC = tmp.second + dCol[l];

                        if (0 <= nR && nR < n && 0 <= nC && nC < m) {

                            if (a[nR][nC] != a[tmp.first][tmp.second]) {
                                continue;
                            }

                            if(d[nR][nC] >= 0){
                                if(d[tmp.first][tmp.second] - d[nR][nC] >=4 ){
                                    ok = true;
                                }
                            }else{
                                d[nR][nC] = d[tmp.first][tmp.second] + 1;
                                q.push(make_pair(nR,nC));
                            }
                        }
                    }
                }
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<d[i][j];
        }
        cout<<'\n';
    }


    if (ok) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}