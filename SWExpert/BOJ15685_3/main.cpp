#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool c[101][101];
int dx[] = {0,-1,0,1}; //row 동쪽방향을 기준으로 0 북 1 서 2 남 3
int dy[] = {1,0,-1,0};
vector<int> curve(int x, int y, int dir, int gen) {
    vector<int> ans = {dir};
    for (int g=1; g<=gen; g++) {
        vector<int> temp(ans);
        reverse(temp.begin(), temp.end()); // 현재 방향을 다 뒤집어주는거죠.
        for (int &i : temp) {
            i = (i+1)%4; //  시계방향으로 90도 회전하면 됌.
        }
        ans.insert(ans.end(), temp.begin(), temp.end()); //원래 세대에 뒤에 정답을 추가해서
    }
    return ans;
}
int main() {
    int n;
    cin >> n;
    while (n--) {
        int x, y, dir, gen;
        cin >> y >> x >> dir >> gen;
        vector<int> dirs = curve(x,y,dir,gen);
        c[x][y] = true;
        for (int d : dirs) {
            x += dx[d];
            y += dy[d];
            c[x][y] = true;
        }
    }
    int ans = 0;
    for (int i=0; i<=99; i++) {
        for (int j=0; j<=99; j++) {
            if (c[i][j] && c[i][j+1] && c[i+1][j] && c[i+1][j+1]) {
                ans += 1;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}