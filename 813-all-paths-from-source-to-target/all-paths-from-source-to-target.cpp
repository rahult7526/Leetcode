class Solution {
public:
void dfs(int i,int target,vector<int>&path,vector<vector<int>>&ans,vector<vector<int>>& graph)
{
    if(i==target)
    {
        ans.push_back(path);
    }
    for(auto x:graph[i])
    {
        path.push_back(x);
        dfs(x,target,path,ans,graph);
        path.pop_back();
    }
}
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        vector<int>path;
         path.push_back(0);
        dfs(0,graph.size()-1,path,ans,graph);
        return ans;
    }
};