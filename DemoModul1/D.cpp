#include <bits/stdc++.h>
using namespace std;

int main() {

    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<long long> A(N);
        for (int i = 0; i < N; i++) cin >> A[i];

        if (N == 1) {
            cout << A[0] << "\n";
            continue;
        }

        const long long NEG_INF = LLONG_MIN / 2;
        vector<long long> dp(N, NEG_INF);
        dp[0] = A[0];

        // Deque stores indices, front = index with maximum dp value
        deque<int> dq;
        dq.push_back(0);

        for (int j = 1; j < N; j++) {
            // Remove indices out of window [j-K, j-1]
            while (!dq.empty() && dq.front() < j - K) {
                dq.pop_front();
            }

            if (!dq.empty()) {
                dp[j] = dp[dq.front()] + A[j];
            }

            // Maintain decreasing monotonic deque
            while (!dq.empty() && dp[dq.back()] <= dp[j]) {
                dq.pop_back();
            }
            dq.push_back(j);
        }

        cout << dp[N - 1] << "\n";
    }

    return 0;
}