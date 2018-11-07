#include <iostream>
#include <vector>

using namespace std;



int T, tc, N; char cub[54], d[2];

int ch[2][21] = {

        { 13,8,3,18,14,9,4,0,19,15,10,5,1,20,16,11,6,2,17,12,7 },

        { 7,12,17,2,6,11,16,20,1,5,10,15,19,0,4,9,14,18,3,8,13 } };

int sur[6][21] = {

        { 20,19,18,27,8,7,6,11,28,5,4,3,10,29,2,1,0,9,45,46,47 },

        { 18,21,24,6,11,14,17,36,3,10,13,16,39,0,9,12,15,42,47,50,53 },

        { 6,7,8,11,18,19,20,27,14,21,22,23,30,17,24,25,26,33,36,37,38 },



        { 26,23,20,38,33,30,27,8,41,34,31,28,5,44,35,32,29,2,51,48,45 },

        { 24,25,26,17,36,37,38,33,16,39,40,41,34,15,42,43,44,35,53,52,51 },

        { 42,43,44,15,53,52,51,35,12,50,49,48,32,9,47,46,45,29,0,1,2 } };

char in[6] = { 'o','g','w','b','r','y' };

vector<pair<int, int>> v;



void rot(int a, int b) {

    char tmp[21];

    int cnt = -1;

    while ((++cnt) <= 20) tmp[cnt] = cub[sur[a][cnt]];

    cnt = -1;

    while ((++cnt) <= 20) cub[sur[a][cnt]] = tmp[ch[b][cnt]];

}



int main() {

    std::ios::sync_with_stdio(false); cin.tie(0);

    cin >> T;

    for (tc = 1; tc <= T; tc++) {

        cin >> N;v.clear();

        while (N--) {

            cin >> d[0] >> d[1];

            if (d[0] == 'U') d[0] = 2;

            else if (d[0] == 'D') d[0] = 5;

            else if (d[0] == 'F') d[0] = 4;

            else if (d[0] == 'B') d[0] = 0;

            else if (d[0] == 'L') d[0] = 1;

            else d[0] = 3;



            if (d[1] == '+') d[1] = 0;

            else d[1] = 1;

            v.push_back(make_pair(d[0], d[1]));

        }



        int i = -1;

        while ((++i) <= 54) cub[i] = in[i / 9];

        for (i = 0; i < v.size(); i++) rot(v[i].first, v[i].second);



        for (int i = 18; i <= 26; i++) {

            cout << cub[i];

            if ((i % 3) == 2) cout << '\n';

        }

    }

    return 0;

}