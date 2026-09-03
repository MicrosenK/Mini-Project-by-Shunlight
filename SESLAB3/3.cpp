#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Array pergerakan untuk 4 arah: Atas, Bawah, Kiri, Kanan
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main() {
    // Optimasi I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, X, Y;
    if (!(cin >> N >> M >> X >> Y)) return 0;

    // Normalisasi index ke 0-based
    X--; 
    Y--;

    vector<vector<int>> grid(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<bool>> visited(N, vector<bool>(M, false));
    queue<pair<int, int>> q;

    q.push({X, Y});
    visited[X][Y] = true;
    int totalArea = 0;

    while (!q.empty()) {
        int currentX = q.front().first;
        int currentY = q.front().second;
        q.pop();
        
        totalArea++;

        for (int i = 0; i < 4; i++) {
            int nextX = currentX + dx[i];
            int nextY = currentY + dy[i];

            if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < M) {
                // Syarat: belum dikunjungi dan tingginya <= tinggi saat ini
                if (!visited[nextX][nextY] && grid[nextX][nextY] <= grid[currentX][currentY]) {
                    visited[nextX][nextY] = true;
                    q.push({nextX, nextY});
                }
            }
        }
    }

    cout << totalArea << "\n";

    return 0;
}