#include <iostream>
#include <cstring>

using namespace std;

const  int MAX = 1000004;

int n;
int arr[MAX];
int temp[MAX];

int getPivot(int arr[], int left, int right){

    int end = right;
    int pivot = arr[right];
    int temp;

    while(left<right){
        // 오름차순 정렬
        // 피봇값 기준으로 왼쪽은 큰값이 있으면 바꾸기 위해서 멈추고
        // 피봇값 기준 오른쪽은 작은값이 있으면 바꾸기 위해서 멈춘다.
        while( arr[left] < pivot && left < right){
            left++;
        }

        while( arr[right] >= pivot && left < right){
            right--;
        }

        // 바꾸기
        if( left < right){
            temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
        }

    }

    temp = arr[left];
    arr[left] = arr[end]; // left와 right가 같은 위치에있으므로 어떤것도 상관없음
    arr[end] = temp;

    return left; // 고정된 피봇의 인덱스를 리턴해준다.
}

void myQSort(int arr[], int left, int right){
    // 피봇값을 기준으로 피봇보다 피봇보다 작은 값, 큰값들로 나누어 정렬하는 함수
    if( left < right) {
        int pivot = getPivot(arr, left, right);
        myQSort(arr, left, pivot - 1);
        myQSort(arr, pivot + 1, right);
    }

}

void merge(int arr[], int leftStart, int leftend, int rightStart, int rightEnd){

    int leftIdx = leftStart;
    int rightIdx = rightStart;

    int tempIdx = 0;

    memset(temp, 0, sizeof(temp));

    while(leftIdx <= leftend && rightIdx <= rightEnd){
        //오름차순 정렬
        if( arr[leftIdx] < arr[rightIdx]){
            temp[tempIdx] = arr[leftIdx];
            tempIdx++;
            leftIdx++;
        }else{
            temp[tempIdx] = arr[rightIdx];
            tempIdx++;
            rightIdx++;
        }
    }

    while(leftIdx <= leftend){
        temp[tempIdx] = arr[leftIdx];
        tempIdx++;
        leftIdx++;
    }

    while(rightIdx <= rightEnd){
        temp[tempIdx] = arr[rightIdx];
        tempIdx++;
        rightIdx++;
    }


    for(int i=0, j=leftStart; i< tempIdx; i++, j++){
        arr[j] = temp[i];
    }

}


void mergeSort(int arr[], int start, int end){
    if(start < end){
        int mid = (start + end)/2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, end);
        merge(arr, start, mid, mid+1, end);
    }
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    mergeSort(arr,0,n-1);

    for(int i=0; i<n; i++){
        cout << arr[i]<<'\n';
    }

    return 0;
}