#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    set<string> Deuddo;
    set<string> Bodo;

    int n, m;
    cin >> n >> m;

    string temp = "";
    for(int i=0; i<n; i++){
        cin >> temp;
        Deuddo.insert(temp);
    }

    for(int i = 0; i < m; i++){
        cin >> temp;
        if( Deuddo.find(temp) != Deuddo.end())
            Bodo.insert(temp);
    }

    cout<<Bodo.size()<<'\n';
    for(set<string>::iterator it = Bodo.begin();
            it != Bodo.end(); it++){
        cout<<*it<<'\n';
    }

    return 0;
}