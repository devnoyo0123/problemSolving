#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 1000001;

int F, S, G, U, D, ans;
int dist[MAX];

void solve() {
    queue<int> Q;
    dist[S] = 0;
    Q.push(S);

    while (!Q.empty()) {
        int left;
        int right;
        int cur = Q.front();
        Q.pop();

        left = cur - D;
        if (left >= 1 && dist[left] < 0) {
            dist[left] = dist[cur] + 1;
            Q.push(left);

        }
        right = cur + U;
        if (right <= F && dist[right] < 0) {
            dist[right] = dist[cur] + 1;
            Q.push(right);
        }

    }

    if (dist[G] == -1) {
        ans = -1;
    } else {
        ans = dist[G];
    }


}

int main() {
    cin >> F >> S >> G >> U >> D;
    memset(dist, -1, sizeof(dist));
    solve();
    if (ans == -1) {
        cout << "use the stairs\n";
    } else {
        cout << ans << '\n';
    }

    return 0;
}