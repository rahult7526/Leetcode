static const int fast = []{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    return 0;
}();
class Solution {
public:
    void f(int i, vector<int>& nums, int target, vector<int>& v, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(v);
            return;
        }
        if (i == nums.size() || target < 0) {
            return;
        }

        // Include current number
        v.push_back(nums[i]);
        f(i + 1, nums, target - nums[i], v, ans);
        v.pop_back();  // backtrack

        // Skip duplicates
        while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
            i++;
        }

        // Exclude current number
        f(i + 1, nums, target, v, ans);
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> v;

        // Sort the array to handle duplicates more efficiently
        sort(nums.begin(), nums.end());

        f(0, nums, target, v, ans);
        return ans;
    }
};