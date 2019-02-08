#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

int checkSqaure(vector<vector<int>> check, int row, int col){
    int res = 0;

    int count = 0;
    for(int i=0; i<check.size(); i++){
        if(!check[row][i]){
            count++;
        }
    }

    if( count == check.size()){
        res++;
    }

    count =0;
    for(int i=0; i<check.size(); i++){
        if(!check[i][col]){
            count++;
        }
    }
    if( count == check.size()){
        res++;
    }

    count =0;
    int i=0, j=0;
    if( row - col == 0){

        while( i < check.size()){
            if( !check[i][j]){
                count++;
            }
            i++;
            j++;
        }
        if( count == check.size()){
            res++;
        }
    }

    count = 0;
    i=0, j=check.size()-1;
    if( row + col == check.size()-1){
        while( i < check.size()){
            if( !check[i][j]){
                count++;
            }
            i++;
            j--;
        }
        if( count == check.size()){
            res++;
        }
    }


    return res;
}

int solution(vector<vector<int>> board, vector<int> nums) {

    int size = board.size();
    vector<vector<int>> check(board);
    unordered_map<int, pair<int, int>> map;
    int answer = 0;

    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[i].size(); j++){
            map[board[i][j]] = {i, j};
        }
    }

    for(int i=0; i<nums.size(); i++) {
        pair<int, int> temp = map[nums[i]];
        check[temp.first][temp.second] = 0;

        if(checkSqaure(check, temp.first, temp.second)){
            answer++;
        }
    }

    return answer;
}

int main() {



    return 0;
}