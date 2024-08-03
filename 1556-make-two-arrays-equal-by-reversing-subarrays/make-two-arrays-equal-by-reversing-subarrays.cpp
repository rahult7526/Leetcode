class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector<int> freq(1001,0);
        for(int val:arr){
            freq[val]++;
        }
        for(int val:target){
            freq[val]--;
        }
        for(int val:freq){
            if(val!=0) return 0;
        }
        return 1;
        
    }
};