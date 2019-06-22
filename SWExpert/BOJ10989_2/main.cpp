#include <iostream>

using namespace std;

const int MAX = (int)1e7;

//ascending
class myHeap{
private:
    int idx; // 추가될 값의 idx
    int data[MAX+1]{};

public:

    myHeap(int x){
        this->idx = x;
    }
    void insert(int x){
        data[idx++] = x;

        int my = idx-1;
        while(true){
            int parent = my/2;
            if( parent == 0){
                break;
            }

            if( data[parent] > data[my] ){
                int temp = data[parent];
                data[parent] = data[my];
                data[my] = temp;
            }else{
                break;
            }

            my/=2;
        }
    }

    int top(){
        return data[1];
    }

    void pop(){
        int removed = data[1];
        data[1] = data[idx-1];
        int my = 1;
        while(true){
            int leftChild = my*2;
            int rightChild = my*2+1;


            if( leftChild <= idx-1){
                if( data[leftChild] < data[my]){
                    int temp = data[leftChild];
                    data[leftChild] = data[my];
                    data[my] = temp;
                }else{
                    break;
                }
            }else if( rightChild <= idx-1){
                int minOne = data[leftChild] < data[rightChild] ? leftChild : rightChild;
                if( data[minOne] < data[my]){
                    int temp = data[minOne];
                    data[minOne] = data[my];
                    data[my] = temp;
                }else{
                    break;
                }
            }else{
                break;
            }

            my *=2;

        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,x;
    cin >> n;
    myHeap mHeap(1);
    int count = n;
    while(count--){
        cin>> x;
        mHeap.insert(x);
    }

    while(n--){
        cout<<mHeap.top()<<'\n';
        mHeap.pop();
    }

    return 0;
}