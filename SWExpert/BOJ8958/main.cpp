#include <iostream>

using namespace std;

int tc;

int main() {

    cin >> tc;
    string str;
    int score,temp;
    for (int t = 1; t <=tc ; ++t) {

        cin >> str;
        score = 0;
        temp = 1;
        for(char ch : str){
            if( ch == 'O'){
                score +=temp;
                temp++;
            }else{
                temp = 1;
            }
        }
        cout<<score<<'\n';

    }

    return 0;
}