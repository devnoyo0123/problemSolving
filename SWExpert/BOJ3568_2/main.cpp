#include <iostream>

using namespace std;



int main() {



    string str = "";
    string commonType = "";

    int cnt = 0;
    while(true) {
        bool flag = false;
        cin >> str;
        int size = (int)str.size();
        for(int i = 0; i < size; i++){
            if( str[i] == ';'){
                flag = true;
                break;
            }
        }

        if( cnt == 0 ){
            commonType = str;
        }

        if( cnt > 0){
            cout << commonType;
            for (int i = size-1; i >= 0; --i) {
                if(str[i]== ',' || str[i] == ';'){
                    continue;
                }

                if(str[i] == '['){
                    cout<<"]";
                    continue;
                }else if( str[i] == ']'){
                    cout<<"[";
                    continue;
                }

                if( (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')){
                    cout<<" ";
                    for (int j = 0; j <= i; ++j) {
                        cout<<str[j];
                    }
                    break;
                }

                cout<<str[i];
            }
            cout<<";";
            cout<<"\n";
        }

        if( flag ){
            break;
        }
        cnt++;

    }

    return 0;
}

