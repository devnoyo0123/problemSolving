#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
struct Point {
    int x, y;
    Point() {
    }

    Point(int x, int y) : x(x), y(y) {
    }
    bool operator < (const Point &v) const {
        if (x == v.x) {
            return y < v.y; // x값이 같다면 y값이 기준으로 오름차순
        } else {
            return x < v.x; // x값 기준으로 오름차순 정렬 내림차순의 경우 부등호 방향 >
        }
    }
};
bool cmp(const Point &u, const Point &v) {
    return u.y < v.y;
}
int dist(Point p1, Point p2) {
    return (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y);
}
int brute_force(vector<Point> &a, int firstPos, int lastPos) {
    int ans = -1;
    for (int i=firstPos; i<=lastPos-1; i++) {
        for (int j=i+1; j<=lastPos; j++) {
            int d = dist(a[i], a[j]);
            if (ans == -1 || ans > d) {
                ans = d;
            }
        }
    }
    return ans;
}
int closest(vector<Point> &a, int firstPos, int lastPos) {
    int n = lastPos-firstPos+1;

    if (n <= 3) {
        return brute_force(a, firstPos, lastPos); // 점이 3개 이하일땐 그냥 구한다.
    }

    int mid = (firstPos+lastPos)/2;
    int left = closest(a, firstPos, mid);
    int right = closest(a, mid+1, lastPos);
    int ans = min(left, right);
    vector<Point> b;
    for (int i=firstPos; i<=lastPos; i++) {
        int d = a[i].x - a[mid].x; // mid를 기준으로 min(dL, dR)보다 거리가 작은 점이 있으면 b에
                // 추가해줘.
        if (d*d < ans) {
            b.push_back(a[i]);
        }
    }
    sort(b.begin(), b.end(), cmp); // y를 기준으로 오름차순
    int m = b.size();
    for (int i=0; i<m-1; i++) { // 선택정렬과 같은 알고리즘.
        for (int j=i+1; j<m; j++) {
            int y = b[j].y - b[i].y;
            if (y*y < ans) {
                int d = dist(b[i], b[j]);
                if (d < ans) {
                    ans = d;
                }
            } else {
                break;
            }
        }
    }
    return ans;
}
int main() {
    int n;
    scanf("%d",&n);
    vector<Point> a(n);
    for (int i=0; i<n; i++) {
        scanf("%d %d",&a[i].x,&a[i].y);
    }
    sort(a.begin(), a.end()); // Point는 클래스로 정의해놓음. 클래스 내에 < 연산자 오버로딩
    printf("%d\n",closest(a, 0, n-1)); //가장 가까운 두 점을 찾는 함수 호출
    return 0;
}

