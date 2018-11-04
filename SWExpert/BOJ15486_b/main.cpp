#include <iostream>
#include <algorithm>
using namespace std;
int d[1500000+50];
int t[1500000];
int p[1500000];

//이건 정답이 0부터 n-1일까지 한거로 쳤으니 정답은 d[n]에 있음.
//1일부터 시작하는건데 0으로 시작점을 앞당겨서 전체가 하나씩 앞당겨짐.
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i<n; i++) {
        cin >> t[i] >> p[i];
    }
    for (int i=0; i<n; i++) {
        d[i+t[i]] = max(d[i+t[i]],d[i]+p[i]);
        d[i+1] = max(d[i+1],d[i]);
    }
    cout << d[n] << '\n';
    return 0;
}