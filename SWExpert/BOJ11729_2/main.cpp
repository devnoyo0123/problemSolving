#include <iostream>

using namespace std;

const int MAX = 987654321;

pair<int, int> st1[MAX];

int top1;
int n1, cnt;


void go(int n, int from, int thru, int to){
    if( n == 1){
        cnt++;
        st1[top1].first = from;
        st1[top1].second = to;
        top1++;
        return;
    }

    go(n-1, from, to, thru);


    go(1, from, thru, to);


    go(n-1, thru, from, to);
}

int main() {

    cin >> n1;

    go(n1, 1, 2, 3);

    cout<<cnt<<"\n";

    while(top1>0){
        cout<<st1[top1-1].first<<" "<<st1[top1-1].second<<'\n';
        top1--;
    }

    return 0;
}