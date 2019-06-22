#include <iostream>
#include <vector>

using namespace std;

const int MAX = 10001;

string d[MAX];

int main() {

    int n;
    cin >> n;

    d[0] = "0";
    d[1] = "1";
    for(int i=2; i<=n; i++){
        int sz1 = d[i-1].size();
        int sz2 = d[i-2].size();
        int size = min(sz1, sz2);
        vector<int> res;
        bool flag = false;
        for(int j=size-1; j>=0; j--){
            int temp =0;
            int a,b;
            a = d[i-1][j]-'0';
            b = d[i-2][j]-'0';

            if(flag) temp += 1;
            temp += (a + b);
            if( temp >= 10){
                flag = true;
            }else{
                flag = false;
            }
            res.push_back(temp%10);
        }

        if( size < sz1){
            for(int j = d[i-2].size()-1; j>=size; j--){
                int temp = d[i-2][j]-'0';
                if( flag ){
                    temp += 1;

                    if( temp >= 10){
                        flag = true;
                    }else{
                        flag = false;
                    }
                    res.push_back(temp%10);
                }
            }
        }else if( size < sz2){
            for(int j = d[i-1].size()-1; j>=size; j--){
                int temp = d[i-1][j]-'0';
                if( flag ){
                    temp += 1;

                    if( temp >= 10){
                        flag = true;
                    }else{
                        flag = false;
                    }
                    res.push_back(temp%10);
                }
            }
        }else{
            if(flag){
                res.push_back(1);
                flag = false;
            }
        }

        string temp ="";
        for(int j=res.size()-1; j>=0; j--){
            temp += to_string(res[j]);
        }
        d[i] = temp;
    }


    cout<< d[n];


    return 0;
}