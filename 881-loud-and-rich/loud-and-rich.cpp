class Solution {
public:
    void dfs(int node, vector<bool>&visited, vector<int>adj[], stack<int>&st) {
        visited[node] = true;
        for (auto child : adj[node]) {
            if (visited[child])
                continue;
            dfs(child, visited, adj, st);
        }
        st.push(node);
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<int>ans(n, 0);
        stack<int>order;
        vector<int>adj[n];

        for (int i = 0; i < n; i++)
            ans[i] = i;

        for (auto vec : richer) {
            adj[vec[0]].push_back(vec[1]);
        }

        vector<bool>visited(n, false);
        for (int i = 0; i < n; i++)
            if (!visited[i])
                dfs(i, visited, adj, order);

        while (!order.empty()) {
            int node = order.top();
            order.pop();
            for (auto child : adj[node]) {
                if (quiet[ans[child]] > quiet[ans[node]])
                    ans[child] = ans[node];
            }
        }
        return ans;
    }
};