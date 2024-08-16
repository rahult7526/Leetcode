class Solution {
public:
    int countSeniors(vector<string>& details) {
        int final = 0;
        for (const auto& detail : details) {
            // Check the first digit of the age
            if (detail[11] > '6') {
                final++;
            }
            // If the first digit is '6', check the second digit
            else if (detail[11] == '6' && detail[12] != '0') {
                final++;
            }
        }
        return final;
    }
};