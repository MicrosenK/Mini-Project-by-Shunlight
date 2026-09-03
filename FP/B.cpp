#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int student_to_dept[1000005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    for (int i = 0; i <= 1000000; ++i) {
        student_to_dept[i] = -1;
    }

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        for (int j = 0; j < n; ++j) {
            int id;
            cin >> id;
            student_to_dept[id] = i;
        }
    }

    queue<int> main_queue;
    vector<queue<int>> dept_queues(t);
    
    // Vector untuk menampung semua output agar dicetak barengan di akhir
    vector<int> final_outputs;

    string command;
    while (cin >> command) {
        if (command == "ENQUEUE") {
            int id;
            cin >> id;
            
            if (id < 0 || id > 1000000) continue;

            int dept = student_to_dept[id];

            if (dept != -1) {
                if (dept_queues[dept].empty()) {
                    main_queue.push(dept);
                }
                dept_queues[dept].push(id);
            } else {
                int new_dept = dept_queues.size();
                dept_queues.emplace_back();
                student_to_dept[id] = new_dept;
                main_queue.push(new_dept);
                dept_queues[new_dept].push(id);
            }

        } else if (command == "DEQUEUE") {
            if (main_queue.empty()) continue;

            int front_dept = main_queue.front();
            int served_id = dept_queues[front_dept].front();
            dept_queues[front_dept].pop();
            
            // Simpan ke vector, jangan langsung di-print
            final_outputs.push_back(served_id);

            if (dept_queues[front_dept].empty()) {
                main_queue.pop();
            }
        }
    }

    // Print semua jawaban sekaligus setelah input berhenti
    for (int ans : final_outputs) {
        cout << ans << "\n";
    }

    return 0;
}