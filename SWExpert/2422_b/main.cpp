#include <iostream>

using namespace std;

const int NMAX = 201;


int n, m;
bool check[NMAX][NMAX];
int main() {

    cin >> n >> m;


    int a, b;
    for (int j = 1; j <= m; ++j) {
        cin >> a >> b;
        check[a][b] = true;
        check[b][a] = true;
    }


    int ans = 0;
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {

                if(!(k < i && i < j)){
                    continue;
                }

                if( k == i || i == j || k == j){
                    continue;
                }

                if( check[k][i] || check[i][j] || check[k][j]){
                    continue;
                }
//                cout<<k << " "<< i << " " << j <<'\n';
                ans++;
            }
        }
    }

    cout<<ans<<'\n';

    return 0;
}