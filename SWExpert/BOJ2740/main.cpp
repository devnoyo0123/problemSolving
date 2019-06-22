#include <iostream>

using namespace std;

const int MAX = 100;

int a[MAX][MAX], b[MAX][MAX], c[MAX][MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,k;

    cin >> n >> m;

    for(int i = 0; i< n; i++){
        for(int j=0; j<m; j++){
            cin >> a[i][j];
        }
    }

    cin >> m >> k;
    for(int i=0; i<m; i++){
        for(int j=0; j<k;j++){
            cin >> b[i][j];
        }
    }


    for(int i=0; i<n; i++){
        for(int j=0; j<k; j++){

            for(int k = 0; k<m; k++){
                c[i][j] += a[i][k] * b[k][j];
            }
            cout<<c[i][j]<<" ";

        }
        cout<<'\n';
    }



    return 0;
}