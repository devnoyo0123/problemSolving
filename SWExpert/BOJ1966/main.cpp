#include <iostream>
#include <vector>
#include <deque>
#include <cstring>


using namespace std;

int tc;
int max1;



int getMax(const deque<pair<int, int > > &priority){
    int tmp = 0;
    for (int i = 0; i < priority.size(); ++i) {
        if( tmp < priority[i].first){
            tmp = priority[i].first;
        }
    }
    return tmp;
}

int main() {

    cin >> tc;

    while(tc-- >0){
        max1 = 0; //우선순위 최대값
        int n, m;
        cin >> n >> m;
        deque<pair<int, int> > priority; // 우선순위, 인덱스
        for(int i=0; i<n; i++){
            int tmp;
            cin >> tmp;
            if( max1 < tmp){
                max1 = tmp;
            }
            priority.push_back({tmp,i});
        }

        int cnt =0;
        while(!priority.empty()) {
            pair<int, int> tmp = priority.front();
            if( priority.front().first < max1){
                priority.pop_front();
                priority.push_back({tmp.first, tmp.second});
            }else{
                ++cnt;
                if( tmp.second == m){
                    cout<<cnt<<'\n';
                    break;
                }
                priority.pop_front();
                max1 = getMax(priority);
            }
        }

    }

    return 0;
}