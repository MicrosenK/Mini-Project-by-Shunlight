#include <iostream>
#include <vector>

using namespace std;

const int MAX_JUMP = 20;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int total_users, total_queries;
    if (!(cin >> total_users >> total_queries)) return 0;

    vector<int> level(total_users + 1, 0);
    vector<vector<int>> ancestor(total_users + 1, vector<int>(MAX_JUMP, 1)); 

    level[1] = 0;
    for (int j = 0; j < MAX_JUMP; ++j) {
        ancestor[1][j] = 1;
    }

    for (int i = 2; i <= total_users; ++i) {
        int boss;
        cin >> boss;
        
        level[i] = level[boss] + 1;
        ancestor[i][0] = boss;
        
        for (int j = 1; j < MAX_JUMP; ++j) {
            ancestor[i][j] = ancestor[ancestor[i][j - 1]][j - 1];
        }
    }

    while (total_queries--) {
        int u, v;
        cin >> u >> v;

        if (level[u] < level[v]) {
            swap(u, v);
        }

        int gap = level[u] - level[v];
        for (int j = 0; j < MAX_JUMP; ++j) {
            if ((gap >> j) & 1) {
                u = ancestor[u][j];
            }
        }

        if (u == v) {
            cout << u << "\n";
            continue;
        }

        for (int j = MAX_JUMP - 1; j >= 0; --j) {
            if (ancestor[u][j] != ancestor[v][j]) {
                u = ancestor[u][j];
                v = ancestor[v][j];
            }
        }

        cout << ancestor[u][0] << "\n";
    }

    return 0;
}