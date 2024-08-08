class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {

        vector<vector<int>> ans;
        vector<vector<int>> dir;
        // R, D, L, U 
        dir.push_back({0,1});
        dir.push_back({1,0});
        dir.push_back({0,-1});
        dir.push_back({-1,0});
        vector<int> limit={1,1,2,2};
        int curDir=0;
        int j=0;
        while(ans.size() < (rows * cols) )
        {   
            vector<int> D=dir[curDir];
            int l=0;
            // ans.push_back({rStart,cStart});

            while(l<limit[curDir])
            {
                // if(ans.back()[0]!=rStart&&ans.back()[1])
                if(rStart<rows&&rStart>=0&&cStart<cols&&cStart>=0)
                    ans.push_back({rStart,cStart});
                rStart+=D[0];
                cStart+=D[1];
                l++;
                j++;
                // cout <<rStart<<" "<<cStart<<endl;
            }
            limit[curDir]+=2;
            curDir++;
            curDir=curDir%4;
        }
        return ans;
        
        
    }
};