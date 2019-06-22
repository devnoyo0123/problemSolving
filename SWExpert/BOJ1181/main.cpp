#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(string &a, string &b){
    if( a.length() == b.length()){
        return a < b;
    }else{
        return a.length() < b.length();
    }
}
int main() {

    int n;
    cin >> n;
    set<string> s;
    string temp ="";
    while(n--){
        cin >> temp;
        s.insert(temp);
    }
    set<string>::iterator itr;
    vector<string> v(s.size());
    int idx= 0;
    for(itr = s.begin(); itr != s.end(); itr++){
        v[idx++] = *itr;
    }

    sort(v.begin(), v.end(), cmp);

    for(int i=0; i<s.size(); i++){
        cout<<v[i]<<'\n';
    }

    return 0;
}