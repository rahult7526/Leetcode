class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i = 0; i < nums.size(); i++)
            pq.push({nums[i], i});

        int mod = 1e9+7;
        int cnt = 0;
        int ans = 0;

        while(!pq.empty() && cnt < right) {
            auto temp = pq.top();
            pq.pop();

            int sum = temp.first;
            int indx = temp.second;

            if(cnt >= left - 1)
                ans = ( ans + sum ) % mod;
            
            if(indx < n-1)
                pq.push({sum + nums[indx+1], indx+1});
            
            cnt++;
        }

        return ans;
        
    }
};