#include <iostream>

using namespace std;

const int MAX = 25;

int a[MAX];
int t[MAX];

bool ok;

bool check(){
    for(int i=1; i<MAX; i+=4){
        int val = t[i];
        int cnt = 1;
        for(int j= i+1; j<=i+4; j++){
            if( val == t[j]){
                cnt++;
            }
        }
        if( cnt != 4){
            return false;
        }
    }
    return true;
}

void rot1(){
    for(int i=1; i<MAX; i++){
        t[i] = a[i];
    }

    int temp[3];
    temp[0] = t[5];
    temp[1] = t[6];

    t[5] = t[13];
    t[6] = t[14];
    t[13] = t[21];
    t[14] = t[22];
    t[21] = t[17];
    t[22] = t[18];
    t[17] = temp[0];
    t[18] = temp[1];


    if(check()){
        ok = true;
    }

}

void rot2(){

    for(int i=1; i<MAX; i++){
        t[i] = a[i];
    }
    // tmp[0] = 7, tmp[1] = 8
    // 7 - 19, 8 - 20, 19 - 23, 20 - 24, 23 - 15, 24 - 16, 15 - tmp[0], 16 - tmp[1]
    // tmp[2] - 9, 9 - 11, 11 - 12, 12 - 10, 10 - tmp[2]
    int temp[3];
    temp[0] = t[7];
    temp[1] = t[8];

    t[7] = t[15];
    t[8] = t[16];
    t[15] = t[23];
    t[16] = t[24];
    t[23] = t[19];
    t[24] = t[20];
    t[19] = temp[0];
    t[20] = temp[1];


    if(check()){
        ok = true;
    }

}

void rot3(){
    for(int i=1; i<MAX; i++){
        t[i] = a[i];
    }

    int temp[3];
    temp[0] = t[5];
    temp[1] = t[7];

    t[5] = t[1];
    t[7] = t[3];
    t[1] = t[24];
    t[3] = t[22];
    t[24] = t[11];
    t[22] = t[9];
    t[11] = temp[0];
    t[9] = temp[1];


    if(check()){
        ok = true;
    }
}

void rot4(){
    for(int i=1; i<MAX; i++){
        t[i] = a[i];
    }

    int temp[3];
    temp[0] = t[6];
    temp[1] = t[8];

    t[6] = t[2];
    t[8] = t[4];
    t[2] = t[23];
    t[4] = t[21];
    t[23] = t[10];
    t[21] = t[12];
    t[10] = temp[0];
    t[12] = temp[1];


    if(check()){
        ok = true;
    }
}

void rot5(){
    for(int i=1; i<MAX; i++){
        t[i] = a[i];
    }

    int temp[3];
    temp[0] = t[5];
    temp[1] = t[6];

    t[5] = t[17];
    t[6] = t[18];
    t[17] = t[21];
    t[18] = t[22];
    t[21] = t[13];
    t[22] = t[14];
    t[13] = temp[0];
    t[14] = temp[1];


    if(check()){
        ok = true;
    }
}

void rot6(){
    for(int i=1; i<MAX; i++){
        t[i] = a[i];
    }

    int temp[3];
    temp[0] = t[7];
    temp[1] = t[8];

    t[7] = t[19];
    t[8] = t[20];
    t[19] = t[23];
    t[20] = t[24];
    t[23] = t[15];
    t[24] = t[16];
    t[15] = temp[0];
    t[16] = temp[1];


    if(check()){
        ok = true;
    }
}

void rot7(){
    for(int i=1; i<MAX; i++){
        t[i] = a[i];
    }

    int temp[3];
    temp[0] = t[5];
    temp[1] = t[7];

    t[5] = t[9];
    t[7] = t[11];
    t[9] = t[24];
    t[11] = t[22];
    t[24] = t[1];
    t[22] = t[3];
    t[1] = temp[0];
    t[3] = temp[1];


    if(check()){
        ok = true;
    }
}

void rot8(){
    for(int i=1; i<MAX; i++){
        t[i] = a[i];
    }

    int temp[3];
    temp[0] = t[6];
    temp[1] = t[8];

    t[6] = t[10];
    t[8] = t[12];
    t[10] = t[23];
    t[12] = t[21];
    t[23] = t[2];
    t[21] = t[4];
    t[2] = temp[0];
    t[4] = temp[1];


    if(check()){
        ok = true;
    }
}

int main() {

    for(int i=1; i< MAX; i++){
        cin >> a[i];
    }

    if(!ok){
        rot1();
    }

    if(!ok){
        rot2();
    }

    if(!ok){
        rot3();
    }

    if(!ok){
        rot4();
    }

    if(!ok){
        rot5();
    }

    if(!ok){
        rot6();
    }

    if(!ok){
        rot7();
    }

    if(!ok){
        rot8();
    }

    if(ok){
        cout<<1;
    }else{
        cout<<0;
    }



    return 0;
}