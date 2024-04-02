class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n  = s.length();
        int fre1[200] = {0},fre2[200] = {0};
        for(int i = 0; i<n; i++){
            if(fre1[s[i]] != fre2[t[i]])
            return false;
        fre1[s[i]]= i+1;
        fre2[t[i]]= i+1;     
        }
        return true;
    }
};