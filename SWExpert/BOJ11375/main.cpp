#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1001;

int N,M;

int job[MAX];

void BFS(vector<vector<int> > &employee, int node){
    for (int i = 0; i < employee[node].size(); ++i) {

        job[i] = employee[node][i];

    }
}

void solve(vector<vector<int> > &employee){
    for (int i = 1; i < N; ++i) {
        if( job[i] == 0){
            BFS(employee, i);
        }else{

        }
    }
}


int main() {


    cin >> N >> M;
    vector<vector<int> > employee(N+1);

    for (int i = 1; i <= N; ++i) {
        int a;
        cin >> a;
        vector<int> element(a);
        employee[i] = element;

        for (int j = 0; j < a; ++j) {
            int b;
            cin >> b;
            employee[i].push_back(b);
        }
    }

    solve(employee);

    return 0;
}