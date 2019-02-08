#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 500000;

int n1, m1;

int nums[MAX];

int lower_bound(int left, int right, int num){
    if( right <= left){
        return right; // left든 right든 상관없음
    }else{
        int mid = (left + right)/2;
        if( nums[mid] < num) {
            return lower_bound(mid+1, right, num);
        }else{
            return lower_bound(left, mid, num);
        }
    }
}

int upper_bound(int left, int right, int num){
    if( right <= left ){
        return left;  // left든 right든 상관없음
    }else{
        int mid = (left + right)/2;
        if( nums[mid] <= num) {
            return upper_bound(mid+1, right, num);
        }else{
            return upper_bound(left, mid, num);
        }
    }
}

int main() {

    scanf("%d", &n1);
    for (int i = 0; i < n1; ++i) {
        scanf("%d", &nums[i]);
    }

    sort(nums, nums + n1);

    scanf("%d", &m1);

    int a;
    for (int j = 0; j < m1; ++j) {
        scanf("%d", &a);
        int lower = lower_bound(0, n1, a);
        int upper = upper_bound(0, n1, a);
        printf("%d ", upper-lower);
    }

    return 0;
}