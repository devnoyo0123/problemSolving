#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Node {
public:
    int x, y, sz;

    Node(int _x, int _y, int _sz) {
        x = _x;
        y = _y;
        sz = _sz;
    }
};

const int MAX = 100;

bool c[MAX][MAX];


int main() {

    int n, m;

    cin >> n >> m;
    vector<Node> list;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        string tmp = "";
        cin >> tmp;
        a[i] = tmp;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '*') {
                for (int k = 1; ; k++) {
                    if (i - k < 0 || i + k >= n) break;
                    if (j - k < 0 || j + k >= m) break;
                    if (a[i-k][j] == '*'
                        && a[i+k][j] == '*'
                        && a[i][j-k] == '*'
                        && a[i][j+k] == '*') {
                        list.push_back(Node(i+1,j+1,k));
                        c[i][j] = c[i-k][j] = c[i+k][j] = c[i][j-k] = c[i][j+k] = true;

                    }else{
                        break;
                    }
                }
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if( a[i][j] =='*' && !c[i][j]){
                cout<<-1;
                return 0;
            }
        }
    }


    cout<< list.size()<<'\n';
    for(int i=0; i<list.size(); i++){
        cout<< list[i].x <<" "<< list[i].y <<" "<< list[i].sz<<'\n';
    }


    return 0;
}