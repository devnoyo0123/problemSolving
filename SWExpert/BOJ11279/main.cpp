#include <iostream>

using namespace std;

const int MAX = 100004;

class PQ{
    int data[MAX];
    int len;

public:
    PQ(){
        for(int i=0; i< MAX; i++){
            data[i] = 0;
        }
        len = 1;
    }

    void push(int x){
        data[len++] = x;

        int idx = len-1;

        while(idx > 1){
            if( data[idx] > data[idx/2]){
                int temp = data[idx];
                data[idx] = data[idx/2];
                data[idx/2] = temp;
            } else break;
            idx/=2;
        }
    }

    int top(){
        return data[1];
    }

    void pop(){

        data[1] = data[len-1];
        data[len-1] = 0;
        len--;

        int idx = 1;
        int cIdx;


        while(true){

            if( idx*2 + 1 < len){
                //자식이 둘 있을때

                if(data[idx*2] > data[idx*2+1]){
                    // 왼쪽 자식이 더 크다.
                    cIdx = idx*2;
                }else{
                    cIdx = idx*2+1;
                }

            }else if( idx*2 < len && idx*2 + 1 >= len){
                //왼쪽자식만 있을때
                cIdx = idx*2;
            }else if( idx*2 >= len){
                //자식이 없음
                break;
            }

            if( data[idx] < data[cIdx]){
                int temp = data[cIdx];
                data[cIdx] = data[idx];
                data[idx] = temp;
                idx = cIdx;
            }else break;

        }

    }

    bool empty(){
        return len == 1;
    }

};

int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    PQ pq;
    int num;
    for(int i=0; i<n; i++){
        cin >> num;
        if( num == 0){
            cout<< (pq.empty() ? 0 : pq.top())<<'\n';
            if(!pq.empty()){
                pq.pop();
            }

        }else{
            pq.push(num);
        }
    }

    return 0;
}