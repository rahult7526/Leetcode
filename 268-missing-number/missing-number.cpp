class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int totalXor = 0;
        for(auto num : nums)totalXor ^= num;
        for(int num = 0; num <= nums.size(); num++){
            totalXor ^= num;
        }
        return totalXor;
    }
};