class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(char ch : s)
        {
            mp[ch]++;
        }
        vector<int> v;
        vector<pair<char,int>> newMp(mp.begin(),mp.end());

        sort(newMp.begin(), newMp.end(), [](pair<char, int> a,pair<char, int> b)
        {
            return b.second < a.second;
        });

        string ans = "";
        for(auto pair : newMp)
        {
            ans.append(pair.second,pair.first);
        }
        return ans;
    }
};