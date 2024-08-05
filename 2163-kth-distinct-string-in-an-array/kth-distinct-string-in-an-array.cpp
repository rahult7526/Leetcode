class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string, int> dict;
        for(auto &a : arr) dict[a]++;
        int n=0;
        for(int i = 0; i < arr.size(); i++){
            if(dict[arr[i]] == 1){
                if(++n == k) return arr[i];
            }
        }
        return "";
        
    }
};