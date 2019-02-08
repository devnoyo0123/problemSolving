#include <iostream>
#include <string>
#include <vector>
#include <deque>

using namespace std;

bool checkArr(deque<int> dqu, vector<int> arr){
    int size = arr.size();
    for(int i=0; i<size; i++){
        if(dqu[i] != arr[i]){
            return false;
        }
    }
    return true;
}

bool solution(vector<int> arrA, vector<int> arrB) {
    bool answer = false;

    deque<int> dqu;
    int size = arrA.size();
    for(int i=0; i<size; i++){
        dqu.push_back(arrA[i]);
    }

    for(int i=0; i<size; i++){
        int tmp = dqu.back();  dqu.pop_back();
        dqu.push_front(tmp);
        if( checkArr(dqu, arrB)){
            answer = true;
            break;
        }
    }

    return answer;
}

int main() {

    vector<int> aA;
    vector<int> bB;
    aA.push_back(4);
    aA.push_back(3);
    aA.push_back(2);
    aA.push_back(1);

    bB.push_back(5);
    bB.push_back(4);
    bB.push_back(1);
    bB.push_back(2);

    bool res = solution(aA,bB);
    cout<< res<<'\n';

    return 0;
}



