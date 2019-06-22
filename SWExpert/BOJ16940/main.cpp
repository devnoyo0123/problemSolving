#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 100001;


int n;

int main() {

    cin >> n;

    vector<int> adj[MAX];
    vector<int> ans(n);
    vector<int> order(n+1);
    vector<int> res;
    vector<bool> c(MAX, false);
    int a,b;
    for(int i=0; i<n-1; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i=0; i<n; i++){
         cin >> ans[i];
         order[ans[i]] = i;
    }

    for (int j = 0; j < n; ++j) {
        sort(adj[j].begin(), adj[j].end(), [&](const int &a, const int &b){
            return order[a] < order[b];
        });
    }

    queue<int> q;
    c[1] = true;
    q.push(1);


    while(!q.empty()){
        int cur = q.front(); q.pop();
        res.push_back(cur);
        for(int i=0; i< adj[cur].size(); i++){
            int next = adj[cur][i];
            if(!c[next]){
                c[next] = true;
                q.push(next);
            }
        }
    }

    for(int i=0; i<ans.size();i++){
        if( ans[i] != res[i]){
            cout<<0;
            return 0;
        }
    }
    cout<<1;

    return 0;
}

/*
 *
 *
4
1 2
1 3
2 100000
1 2 3 100000
 * */