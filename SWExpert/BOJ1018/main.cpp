#include <iostream>
#include <vector>

using namespace std;

int n,m,ans = -1;

const int white[8][8] = {
{'W','B','W','B','W','B','W','B'},
{'B','W','B','W','B','W','B','W'},
{'W','B','W','B','W','B','W','B'},
{'B','W','B','W','B','W','B','W'},
{'W','B','W','B','W','B','W','B'},
{'B','W','B','W','B','W','B','W'},
{'W','B','W','B','W','B','W','B'},
{'B','W','B','W','B','W','B','W'}
};

const int black[8][8] = {
{'B','W','B','W','B','W','B','W'},
{'W','B','W','B','W','B','W','B'},
{'B','W','B','W','B','W','B','W'},
{'W','B','W','B','W','B','W','B'},
{'B','W','B','W','B','W','B','W'},
{'W','B','W','B','W','B','W','B'},
{'B','W','B','W','B','W','B','W'},
{'W','B','W','B','W','B','W','B'}
};


void solve(vector<string> &a){

    for(int i=0; i+7<n; i++){
        for(int j=0; j+7<m; j++){
            int bcount = 0;
            int wcount = 0;
            for(int l1=i; l1<i+8; l1++){
                for(int l2=j; l2<j+8; l2++){
                    if( black[l1-i][l2-j] != a[l1][l2])
                        bcount++;

                    if( white[l1-i][l2-j] != a[l1][l2])
                        wcount++;
                }
            }

            if( ans == -1 || ans > bcount){
                ans = bcount;
            }

            if( ans == -1 || ans > wcount){
                ans = wcount;
            }
        }
    }


}

int main() {


    string tmp = "";
    cin >> n >> m;
    vector<string> a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];

    solve(a);

    cout<<ans<<'\n';
    return 0;
}