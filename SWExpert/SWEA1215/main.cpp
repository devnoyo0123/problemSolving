#include <iostream>
#include <string>

using namespace std;

int ans, maxlength;

string map[8];

/*
 * type.first = 0 가로
 * type.first = 1 세로
 *
 * type.second = 0 짝수
 * type.second = 1 홀수
 * */
void palin(pair<int, int> &type, int row, int col) {

    int left, right, up, down,length;


    if( type.first){
        // 세로

        if( type.second){

            //홀수

            length = 1;
            up = row, down = row;

            while(maxlength > length){

                up-=1;
                down+=1;

                if( up < 0){
                    break;
                }

                if( down >= 8){
                    break;
                }

                if( map[up][col] != map[down][col]){
                    break;
                }


                length +=2;
            }


        }else{
            // 짝수

            length = 2;
            up = row, down = row+1;

            if( up >= 0 && down < 8 && map[up][col] != map[down][col]){
                return;
            }


            while(maxlength > length){

                up-=1;
                down+=1;

                if( up < 0){
                    break;
                }

                if( down >= 8){
                    break;
                }

                if( map[up][col] != map[down][col]){
                    break;
                }


                length +=2;
            }

        }

    }else{
        // 가로
        if( type.second){
            //홀수

            length = 1;
            left = col, right = col;

            while(maxlength > length){

                left-=1;
                right+=1;


                if( left < 0){
                    break;
                }

                if( right >= 8){
                    break;
                }

                if( map[row][left] != map[row][right]){
                    break;
                }


                length +=2;
            }



        }else{


            // 짝수
            length = 2;
            left = col, right = col+1;

            if( left >= 0 && right < 8 && map[row][left] != map[row][right]){
                return;
            }

            while(maxlength > length){

                left-=1;
                right+=1;

                if( left < 0){
                    break;
                }

                if( right >= 8){
                    break;
                }

                if( map[row][left] != map[row][right]){
                    break;
                }


                length +=2;
            }
        }
    }

    if( maxlength == length){
        ans++;
    }
}

int main() {

    for (int t = 1; t <= 10; t++) {

        ans = 0;
        cin >> maxlength;

        for (int i = 0; i < 8; i++) {
            cin >> map[i];
        }

        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 8; k++) {
                for (int l = 0; l < 2; l++) {


                    pair<int, int> temp;
                    temp.first = l;
                    temp.second = maxlength % 2;
                    palin(temp, j, k);


                }
            }
        }


        cout << "#" << t << " " << ans << '\n';
    }


    return 0;
}