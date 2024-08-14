class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        priority_queue<int> pq;

        for(int step=1; step<=n; step++) {
            for(int j=0; j+step<n; j++) {
                pq.push(abs(nums[j] - nums[j+step]));
                
                if(pq.size() > k)
                    pq.pop();
            }

            if(pq.size() == k) {
                for(int extra=1; extra<=100; extra++) {
                    for(int j=0; j+step+extra<n; j++) {
                        pq.push(abs(nums[j] - nums[j+step+extra]));
                        
                        if(pq.size() > k)
                            pq.pop();
                    }
                }
                return pq.top();
            }
        }

        return 0;
    }
};