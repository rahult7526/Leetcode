class Solution {
public:
    vector<pair<string,int>> countingSort(vector<pair<string,int>>& nums,int& d,int& n){
        vector<pair<int,int>> temp;
        for(int i=0;i<nums.size();++i){
            temp.push_back(make_pair(nums[i].first[n-d]-'0',nums[i].second));
        }
        vector<int> count(10);
        for(auto it:temp){
            count[it.first]++;
        }
        for(int i=1;i<10;++i){
            count[i]+=count[i-1];
        }
        vector<pair<string,int>> res(temp.size());
        for(int i=temp.size()-1;i>=0;--i){
            res[count[temp[i].first]-1] = nums[i];
            count[temp[i].first]--;
        }
        return res;
    }
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<pair<string,int>> num;
        for(int i=0;i<nums.size();++i){
            num.push_back(make_pair(nums[i],i));
        }
        int m=nums.size(),n=nums[0].size();
        vector<vector<pair<string,int>>> temp(n+1);
        temp[0]=num;
        // Radix Sort
        for(int i=1;i<=n;++i){
            temp[i]=countingSort(temp[i-1],i,n);
        }
        vector<int> ans(queries.size());
        for(int i=0;i<queries.size();++i){
            int trim = queries[i][1];
            int k = queries[i][0];
            ans[i] = temp[trim][k-1].second;
        }
        return ans;
    }
};
