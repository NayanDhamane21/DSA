class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;

        vector<vector<int>> adj(n);
        vector<int> out, ind(n, 0);

        priority_queue<int, vector<int>, greater<int>> q;

        // Build graph and calculate indegrees
        for (auto& it : prerequisites) {
            adj[it[1]].push_back(it[0]);
            ind[it[0]]++;
        }

        // Add courses with no prerequisites
        for (int i = 0; i < n; i++) {
            if (ind[i] == 0) {
                q.push(i);
            }
        }

        // Kahn's Algorithm
        while (!q.empty()) {
            int c = q.top();
            q.pop();

            out.push_back(c);

            for (int i : adj[c]) {
                ind[i]--;

                if (ind[i] == 0) {
                    q.push(i);
                }
            }
        }

        // Cycle detected
        if (out.size() != n) {
            return {};
        }

        return out;
    }
};