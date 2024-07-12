class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int i = 0;
        int cnt = 0;
        int mini = 0;
        int j = 0;
        int maxi = 0;
        while(i<n) {
            if(j == n) {
                cnt++;
                break;
            }
            maxi = max(maxi, arr[j]);
            if(maxi - mini == j-i) {
                cnt++;
                mini = maxi + 1;
                maxi = 0;
                i = j+1;
            }
            j++;
        }
        return cnt;
    }
};