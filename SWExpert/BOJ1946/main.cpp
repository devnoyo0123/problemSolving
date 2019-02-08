#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int tc;
int n1;
int ans, max1;

bool cmp( const pair<int, int> &a, const pair<int, int> &b){
    if( (a.first + a.second) == (b.first + b.second)){
        if( a.second == b.second){
            // 합도 같고, 면접등수도 같으면
            // 서류가 높은 순으로
            return a.first < b.first;
        }else{
            return a.second < b.second;
        }
    }else{
        return (a.first + a.second) < (b.first + b.second);
    }
}

// 서류 기준
bool cmp1(const pair<int, int> &a, const pair<int, int> &b ){
    return a.first< b.first;
}

// 면접 기준
bool cmp2(const pair<int, int> &a, const pair<int, int> &b){
    return a.second < b.second;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>> tc;
    for(int t=1; t<=tc; t++){
        cin >> n1;
        ans = 0;
        //입력받기
        vector<pair<int, int> >v1(n1);
        for(int i =0; i< n1; i++){
            cin>> v1[i].first >> v1[i].second;
        }

        // 서류기준 오름차순 정렬
        sort(v1.begin(), v1.end(), cmp1);

        int cnt = 1;

        int size = v1.size();

        max1 = v1[0].second;
        // 서류기준으로 정렬하고 면접시간을 맥스값에 넣어주는 이유는
        // 서류, 면접 총합 최하 등수를 기준으로 그 사람보다 못한 친구들이 있으면 합격을 못한다는 얘기가 된다.
        // 그래서 최하 등수 아이보다 뭐라도 점수가 낮으면 합격하지 못한다.


        for(int i=0; i< size; i++){
            if( v1[i].second < max1){
                max1 = v1[i].second;
                cnt++; //합격
            }

        }

        if( ans < cnt){
            ans = cnt;
        }


        // 면접기준 정렬
        sort(v1.begin(), v1.end(), cmp2);
        cnt = 1;
        max1 = v1[0].first;

        for(int i=0; i< size; i++){
            if( v1[i].first < max1){
                max1 = v1[i].first;
                cnt++; //합격
            }
        }

        if( ans < cnt){
            ans = cnt;
        }


        cout<<ans<<'\n';

    }

    return 0;
}