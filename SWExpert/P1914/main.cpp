#include <iostream>
#include <vector>


using namespace std;

int N;
int cnt;
bool flag;
int fromArr[20];
int toArr[20];

//from 에서 to로 thru기둥을 이용해서 from 탑에 있는 num개의 원판을 이동시킬것이다.
void hanoi(int from, int to, int thru, int num) {

    if( num == 1){
        if (N<=20) {
            fromArr[cnt] = from;
            toArr[cnt] = to;
        }
        cnt += 1;

        return;
    } else {

        //from 에서 thru로 num-1개의 원판을 to로 옮긴다.


        hanoi(from, thru, to, num-1);
        //from 에서 to로 n-1개의 원판을 옮긴다.


        hanoi(from, to, thru, 1);
        //thru에서 to로 n-1개의 원판을 옮긴다.

        hanoi(thru, to, from, num-1);

    }


}

int main() {

    cin >> N;

    hanoi(1, 3, 2, N);

    cout << cnt << "\n";
    for (int i = 0; i <cnt; ++i) {
        cout << fromArr[i] << " " << toArr[i] << "\n";
    }

    return 0;
}