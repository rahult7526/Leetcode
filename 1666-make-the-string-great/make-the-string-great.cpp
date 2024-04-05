class Solution {
public:
    string makeGood(string s) {
        while(1){
            string ans;
            bool check = false;
            for(int i=0;i<s.size();i++){
                if(i < s.size() - 1 && abs(s[i] - s[i+1]) == 32) {
                    i++;
                    check = true;
                } else {
                    ans += s[i];
                }
            }
            s = ans;
            if(!check)break;
        }
        return s;
    }
};