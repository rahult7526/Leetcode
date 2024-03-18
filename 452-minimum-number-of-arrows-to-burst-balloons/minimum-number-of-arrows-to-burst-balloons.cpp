class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end());
        int mini = 1, b = INT_MAX;
        for (int i = 0; i < n - 1; i++) {
            b = min(b,points[i][1]);
            if(b < points[i+1][0])
            {
                mini++;
                b = points[i+1][1];
            }   
        }
        return mini;
    }
};