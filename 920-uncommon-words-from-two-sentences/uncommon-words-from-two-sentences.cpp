class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> m1;
        unordered_map<string, int> m2;
        int i, flag=0;
        vector<string> ans;
        string temp="";
        for(i=0 ; i<s1.length() ; i++)
        {
            if(s1[i]!=' ')
                temp += s1[i];
            else
            {
                m1[temp]++;
                temp.clear();
            }
        }
        m1[temp]++;
        temp.clear();
        for(i=0 ; i<s2.length() ; i++)
        {
            if(s2[i]!=' ')
                temp += s2[i];
            else
            {
                m2[temp]++;
                temp.clear();
            }
        }
        m2[temp]++;
        temp.clear();

        for(auto it: m1)
        {
            if(it.second==1)
            {
                flag=0;
                for(auto j: m2)
                {
                    if(it.first==j.first)
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                    ans.push_back(it.first);
            }
        }
        for(auto it: m2)
        {
            if(it.second==1)
            {
                flag=0;
                for(auto j: m1)
                {
                    if(it.first==j.first)
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                    ans.push_back(it.first);
            }
        }
        return ans;
    }
};
