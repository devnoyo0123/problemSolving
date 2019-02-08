#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 500000;

int n1, m1;

int nums[MAX];

//binary
bool myBinarySearch(int left, int right, int num){
    if( left > right){
        return false;
    }

    int mid =  ( left + right ) /2;
    bool res = false;

    if( nums[mid] == num){
        res = true;
        return res;
    }else if( nums[mid] < num){
        return myBinarySearch(mid+1, right, num);
    }else if( nums[mid] > num){
        return myBinarySearch(left, mid-1, num);
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
        if( myBinarySearch(0, n1-1, a)){
            printf("1 ");
        }else{
            printf("0 ");
        }
    }

    return 0;
}