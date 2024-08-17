class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
    int n = points.size(), m = points[0].size();
    vector<long long> dp(m, 0);

    // Initialize the first row of the dp array
    for (int j = 0; j < m; ++j) {
        dp[j] = points[0][j];
    }

    // Process each row
    for (int i = 1; i < n; ++i) {
        vector<long long> left(m, 0), right(m, 0), new_dp(m, 0);

        // Compute the left array
        left[0] = dp[0];
        for (int j = 1; j < m; ++j) {
            left[j] = max(left[j - 1], dp[j] + j);
        }

        // Compute the right array
        right[m - 1] = dp[m - 1] - (m - 1);
        for (int j = m - 2; j >= 0; --j) {
            right[j] = max(right[j + 1], dp[j] - j);
        }

        // Update the dp array for the current row
        for (int j = 0; j < m; ++j) {
            new_dp[j] = points[i][j] + max(left[j] - j, right[j] + j);
        }

        dp = new_dp;  // Move to the next row
    }

    // The answer is the maximum value in the last row
    return *max_element(dp.begin(), dp.end());
}
};
