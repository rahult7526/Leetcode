class Solution {
public:
    string countAndSay(int n) { 
        string ans = "1"; 
        for(int i = 2;i <= n;i++) 
        {
            string temp = ""; 
            int j = 0; 
            while(j < ans.size()) 
            {
                int cnt = 0; 
                char ch = ans[j];
                while(j <= ans.size() && ans[j]==ch)
                {
                    cnt++; 
                    j++; 
                }
                temp += to_string(cnt)+ ch; 
                }
            ans = temp;
        }
        return ans; 
    }
};