#include <iostream>

using namespace std;

const int MAX = 10001; // push만 10000번 한경우


int st1[MAX];
int head1, tail1;
int N;

int main() {

    cin >> N;

    for (int i = 0; i < N; ++i) {
        string tmp = "";
        cin >> tmp;
        if( tmp == "push"){
            int a;
            cin >> a;
            st1[tail1++] = a;
        }else if( tmp == "front"){

            if( tail1 == head1){
                cout<<-1<<'\n';
                continue;
            }

            cout<<st1[head1]<<'\n';
        }else if( tmp == "pop"){

            if( tail1 == head1){
                cout<<-1<<'\n';
                continue;
            }

            cout<<st1[head1++]<<'\n';

        }else if( tmp == "size"){
            cout<<tail1-head1<<'\n';
        }else if( tmp == "empty"){
            if( tail1 == head1){
                //비어있으면
                cout<<"1\n";
            }else{
                cout<<"0\n";
            }
        }else if( tmp == "back"){

            if( tail1 == head1){
                cout<<-1<<'\n';
                continue;
            }

            cout<<st1[tail1-1]<<'\n';

        }
    }

    return 0;
}