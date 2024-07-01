class Solution {
public:
    int maximumGap(vector<int>& arr) 
    {
        int n = arr.size();
        if(n == 1)
        {
            return 0;
        }        
        if(n == 2)
        {
            return abs(arr[0] - arr[1]);
        }

        int maxele = arr[0];
        int minele = arr[0];

        // Find the maximum and minimum elements in the array
        for(auto i:arr)
        {
            maxele = max(maxele,i);
            minele = min(minele,i);
        }

        // Calculate the bucket size
        int bucketsz = ceil(float(maxele-minele)/(n-1));

        // If the bucket size is zero, return 0 as the maximum gap
        if(bucketsz == 0)
        {
            return 0;
        }

        // Create arrays to store the maximum and minimum values of each bucket
        vector<int>maxofb(n,INT_MIN);
        vector<int>minofb(n,INT_MAX);

        // Assign each element to its corresponding bucket and update the maximum and minimum values of each bucket
        for(int i=0;i<n;i++)
        {
            int whichb = ((arr[i] - minele)/bucketsz);

            maxofb[whichb] = max(maxofb[whichb],arr[i]);
            minofb[whichb] = min(minofb[whichb],arr[i]);
        }

        // Initialize the answer as the bucket size and the previous maximum value as the maximum value in the first non-empty bucket
        int ans = bucketsz, pre = maxofb[0];

        // Iterate through the buckets and find the maximum gap
        for(int i=1;i<n;i++)
        {
            // Skip empty buckets
            if(minofb[i] == INT_MAX)
            {
                continue;
            }

            // Update the answer by comparing it with the difference between the minimum value of the current bucket and the previous maximum value
            ans = max(ans,minofb[i]-pre);
            pre = maxofb[i];
        }

        // Return the maximum gap
        return ans;
    }
};
