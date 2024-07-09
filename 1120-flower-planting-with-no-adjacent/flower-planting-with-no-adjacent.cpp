class Solution {
public:
void dfs(int start, vector<int> adj[], vector<int> &vis, vector<int> &ans){
    vis[start] = 1;
    set<int> st;
    for(auto it : adj[start]){
        st.insert(ans[it]);
    }
    for(int i=1;i<=4;i++){
        if(st.find(i)==st.end()){
            ans[start] = i;
            break;
        }
    }
    for(auto it : adj[start]){
        if(vis[it]==0){
            dfs(it, adj, vis, ans);
        }
    }
}
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> adj[n+1];
        for(auto it : paths){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> ans(n+1, 0);
        vector<int> vis(n+1, 0);
        vis[0] = 1;
        for(int i=1;i<=n;i++){
            if(vis[i]==0){
                dfs(i, adj, vis, ans);
            }
        }
        vector<int> res;
        for(int i=1;i<ans.size();i++){
            res.push_back(ans[i]);
        }
        return res;
    }
};