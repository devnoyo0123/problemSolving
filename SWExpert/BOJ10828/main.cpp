#include <iostream>

using namespace std;

const int MAX = 10001; // push만 10000번 한경우


int st1[MAX];
int top1;
int N;

int main() {

    cin >> N;

    for (int i = 0; i < N; ++i) {
        string tmp = "";
        cin >> tmp;
        if( tmp == "push"){
            int a;
            cin >> a;
            st1[top1++] = a;
        }else if( tmp == "top"){

            if( top1 == 0){
                cout<<-1<<'\n';
                continue;
            }

            cout<<st1[top1-1]<<'\n';
        }else if( tmp == "pop"){

            if( top1 == 0){
                cout<<-1<<'\n';
                continue;
            }

            cout<<st1[top1-1]<<'\n';
            top1--;
        }else if( tmp == "size"){
            cout<<top1<<'\n';
        }else if( tmp == "empty"){
            if( top1 == 0){
                //비어있으면
                cout<<"1\n";
            }else{
                cout<<"0\n";
            }
        }
    }

    return 0;
}