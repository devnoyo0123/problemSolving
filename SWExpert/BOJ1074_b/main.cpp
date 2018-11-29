#include <iostream>

using namespace std;

int power2(int k) {
    return (1 << k);
}

int go(int n, int x, int y) {
    if (n == 1) {
        if (x == 0 && y == 0) {
            return 0;
        } else if (x == 0 && y == 1) {
            return 1;
        } else if (x == 1 && y == 0) {
            return 2;
        } else if (x == 1 && y == 1) {
            return 3;
        }
    } else {
        if (x < power2(n - 1)) { // 4등분한 row보다 작으면
            if (y < power2(n - 1)) { // 4등분한 col보다 작으면
                return go(n - 1, x, y); // 작은 4등분의 0번위치로 분할정복.
            } else {
                // 각각의 4등분한 사각형의 왼쪽 상단을 0,0으로 상대적 위치로 바꾸기 위해 r,c값을 변경한다. 앞에 0번의 4각형 개수를 다 더해준다.
                return go(n - 1, x, y - power2(n - 1)) + power2(2 * n - 2); // 작은 4등분의 1번 위치로 분할정복.
            }
        } else {
            if (y < power2(n - 1)) {
                return go(n - 1, x - power2(n - 1), y) + power2(2 * n - 2) * 2;
            } else {
                return go(n - 1, x - power2(n - 1), y - power2(n - 1)) + power2(2 * n - 2) * 3;
            }
        }
    }
}

int main() {
    int n, x, y;

    cin >> n >> x >> y;

    cout << go(n, x, y) << '\n';

    return 0;
}