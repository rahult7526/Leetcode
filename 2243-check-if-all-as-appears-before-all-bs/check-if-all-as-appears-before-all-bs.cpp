class Solution {
public:
    bool checkString(string s) {
        
    int count = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'a')
        {
            count++;
        }
    }
    string As(count, 'a');
    bool ans = true;
    if (s.find(As) != 0)
        ans = false;
    else
        ans = true;
        
    return ans;

    }
};