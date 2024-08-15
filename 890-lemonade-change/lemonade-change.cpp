class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
        int twenty = 0;

        for(auto n: bills) {
            if(n == 5) {
                five++;
            }

            else if(n == 10) {
                if(five > 0) {
                    ten++;
                    five--;
                }
                else {
                    return false;
                    break;
                }
            }

            else {
                if(five > 0 && ten > 0) {
                    five--;
                    ten--;
                }
                else if(five > 2) {
                    five -= 3;
                }
                else {
                    return false;
                    break;
                }
            }
        }
        return true;
    }
};