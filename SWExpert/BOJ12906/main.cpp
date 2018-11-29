// 흠 하노이 탑 처럼 뭔가.. 막연한 두려움이 있어서 문제 풀이가 막힘..


#include <iostream>
#include <map>
#include <queue>
#include <array>

using namespace std;


int main() {
    //array 클래스

    array<string,3> s;
    for (int i=0; i<3; i++) {
        int cnt;
        cin >> cnt;
        if (cnt > 0) {
            cin >> s[i];
        } else {
            s[i] = "";
        }
    }
    int cnt[3] = {0, 0, 0};
    for (int i=0; i<3; i++) {
        for (int j=0; j<s[i].length(); j++) {
            cnt[s[i][j]-'A'] += 1;
        }
    }
    map<array<string,3>, int> d;
    queue<array<string,3>> q;
    q.push(s);
    d[s] = 0;
    while (!q.empty()) {
        auto now = q.front();
        q.pop();
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                if (i == j) continue;
                if (now[i].length() == 0) continue;
                array<string,3> next(now);
                next[j].push_back(next[i].back()); // 맨 위에 있는 원판을 옮기고
                next[i].pop_back(); // 옮긴, 맨위의 있는 원판을 원래 막대에서 제거하고
                if (d.count(next) == 0) { // 기존 맵에 없던 새로운 상태면 추가하라는 의미인데?
                    d[next] = d[now] + 1;
                    q.push(next);
                }
            }
        }
    }

    // 이 부분 고민좀..
    array<string,3> ans;
    for (int i=0; i<3; i++) {
        for (int j=0; j<cnt[i]; j++) {
            ans[i] += (char)('A' + i); // A,B,C의 개수가 같으면 되는거라고??
        }
    }
    cout << d[ans] << '\n';
    return 0;
}