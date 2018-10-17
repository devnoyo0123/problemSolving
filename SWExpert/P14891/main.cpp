#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>


using namespace std;


const int KMAX = 20;

int TC, K, ans;

int mag[5][9]; //[]:1~4, [][]:1~8사용
int rotDir[5];

vector<pair<int, int> > k;
void print(){
    for(int i=1; i<=4; i++){
        for (int j = 1; j <=8 ; ++j) {
            cout<<mag[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";


}


void calc(){
    int sum = 0;
    for (int i = 1; i <=4 ; ++i) {

//        cout<<mag[i][1]<<"\n";

        if( mag[i][1] == 1){
            // S
            int tmp = pow(2,i-1);
//            cout<<i<<"번째 점수: "<<tmp<<"\n";
            sum +=tmp;
        }
    }
    ans  = sum;
}

void rotate(){
    for (int i = 1; i <=4 ; ++i) {
        if( rotDir[i] == 1){
            // 시계방향 돌리기
            int tmp = mag[i][8];
            for (int k = 7; k >= 1 ; --k) {
                mag[i][k+1] = mag[i][k];
            }
            mag[i][1] = tmp;
        }else if( rotDir[i] == -1){
            // 반시계 방향 돌리기
            int tmp = mag[i][1];
            for (int j = 2; j <=8 ; ++j) {
                mag[i][j-1] = mag[i][j];
            }
            mag[i][8] = tmp;
        }
    }
}

void check(int whichMag, int dir){
    int tmp, tmp2;
    tmp = tmp2 = whichMag;

    // 나 자신 돌리고
    rotDir[whichMag] = dir;
//    cout<<whichMag<<"자석을 "<<dir<<"방향으로 회전\n";


    // 좌측으로 이동하면서 회전방향 체크
    while(tmp-1 >=1){
        if(mag[tmp-1][3] == mag[tmp][7]){
            // 자성이 같으면
            break;
        }else{
            int nDir;
            if(rotDir[tmp] == 1){
                nDir = -1;
            }else{
                nDir = 1;
            }

//            cout<<"mag["<<tmp-1<<"][3]:"<<mag[tmp-1][3]<<", "<<"mag["<<tmp<<"][7]:"<<mag[tmp][7]<<"\n";
            rotDir[tmp-1] = nDir;


//            cout<<tmp-1<<"자석을 "<<nDir<<"방향으로 회전\n";
//            cout<<"좌측이동\n";
            tmp-=1;
        }
    }

    // 우측으로 이동
    while( tmp2+1 <= 4){
        if( mag[tmp2][3] == mag[tmp2 + 1][7]){
            //자성이 같으면
            break;
        }else{
            int nDir;
            if(rotDir[tmp2] == 1){
                nDir = -1;
            }else{
                nDir = 1;
            }
//            cout<<"mag["<<tmp2<<"][3]:"<<mag[tmp2][3]<<", "<<"mag["<<tmp2+1<<"][7]:"<<mag[tmp2+1][7]<<"\n";
            rotDir[tmp2+1] = nDir;

//            cout<<tmp2+1<<"자석을 "<<nDir<<"방향으로 회전\n";
//            cout<<"우측이동\n";
            tmp2+=1;
        }
    }
}

void solve(){
    for (int i = 0; i < k.size(); ++i) {
        pair<int, int> tmp = k[i];
        memset(rotDir,0, sizeof(rotDir));
        int numOfMag = tmp.first;
        int dir = tmp.second;
//        cout<<i+1<<"번째 회전\n";
        check(numOfMag, dir);
        rotate();
//        print();
    }

    calc();
}


int main() {


        memset(mag,0, sizeof(mag));
        ans = 0;
        k.clear();

        for (int j = 1; j <=4 ; ++j) {
            string str;
            cin >> str;
            for (int i = 0; i < 8 ; ++i) {
                mag[j][i+1] = (str[i]) - '0';
            }
        }

        cin >> K;
        for (int i = 0; i < K ; ++i) {
            int a,b;
            cin >> a >> b;
            k.push_back({a,b});
        }

        solve();
        cout<<ans<<"\n";



    return 0;
}