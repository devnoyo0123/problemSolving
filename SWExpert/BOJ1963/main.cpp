#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

bool prime[10001];
bool check[10001];

int tc, ans;
bool done;

void getPrime(){

    for(int i=2; i<10001; i++){
        if(!prime[i]){
            for(int j = i + i; j<= 10001; j+=i ){
                prime[j] = true;
            }
        }

    }
}

void BFS(int start, int end){
    queue<pair<int, int> >qu;
    qu.push({start,0});
    check[start] = true;

    while(!qu.empty()){
        pair<int, int> temp = qu.front(); qu.pop();

        if( temp.first == end){
            done = true;
            ans = temp.second;
            break;
        }

        //천의 자리
        int temp2 = temp.first;
        temp2 = temp2 - (temp2/1000)*1000;

        for(int i=1; i<10; i++){

            temp2 += i*1000;
            if(!prime[temp2] && !check[temp2]){
                check[temp2] = true;
                qu.push({temp2, temp.second + 1});
            }
            temp2 -= i*1000;
        }
        //백의 자리
        temp2 = temp.first;
        temp2 -= ((temp2%1000)/100)*100;

        for(int i=0; i<10; i++){

            temp2 += i*100;

            if(!prime[temp2] && !check[temp2]){
                check[temp2] = true;
                qu.push({temp2, temp.second +1});
            }
            temp2 -= i*100;
        }
        //십의 자리
        temp2 = temp.first;
        temp2 -= ((temp2%100)/10)*10;

        for(int i=0; i<10; i++){

            temp2 += i*10;

            if(!prime[temp2] && !check[temp2]){
                check[temp2] = true;
                qu.push({temp2, temp.second+1});
            }
            temp2 -= i*10;
        }
        //일의 자리
        temp2 = temp.first;
        temp2 -= temp2%10;

        for(int i=0; i<10; i++){

            temp2 += i;

            if(!prime[temp2] && !check[temp2]){
                check[temp2] = true;
                qu.push({temp2, temp.second+ 1});
            }
            temp2 -= i;
        }
    }
}

int main() {

    int a,b;

    getPrime();

    cin >> tc;
    while(tc--){
        done = false;
        ans = 0;
        memset(check, 0, sizeof(check));
        cin >> a >> b;

        BFS(a,b);
        if(done){
            cout<<ans<<'\n';

        }else{
            cout<<"Impossible\n";

        }
    }


    return 0;
}