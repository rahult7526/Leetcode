class Solution {
public:
    long long int countSubs(vector<int>& nums, int k, int mx) {
        long long int count = 0;
        int left = 0;
        unordered_map<int, int> freq;

        for (int right = 0; right < nums.size(); ++right) {
            
            freq[nums[right]]++;
            
            while (freq[mx] >= k) {
                freq[nums[left]]--;
                left++;                   
            }
            
            count += right - left + 1;
                    
        }
        return count;
    }
    long long countSubarrays(vector<int>& nums, int k) {
        int mx = -1;
        for(int m: nums)
        {
            mx = max(mx, m);
        }
        long long int Tsubs = nums.size()*(nums.size()+1)/2;
    
        return (long long) Tsubs - countSubs(nums, k, mx);
       
       
    }
};