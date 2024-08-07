class Solution {
public:
    string numberToWords(int num) {
        return helper(num, 0);
    }

    string helper(int num, int iter) {
        int len = getNumLength(num);
        string answer = "";
    
        if (len <= 3) {
            answer = getNDigits(num, len);
        } else {
            answer = helper(num / 1000, iter+1);
            string returnAnswer = getNDigits(num, 3);
            if (returnAnswer != "") answer += " " + returnAnswer;
            else return answer;
        }


        if (iter != 0) if (answer[answer.size()-1] != ' ') answer += ' ';
        if (iter == 1) {
            answer += "Thousand";
        }
        else if (iter == 2) {
            answer += "Million";
        }
        else if (iter == 3) {
            answer += "Billion";
        }

        return answer;
    }

    string getNDigits(int num, int n) {
        if (n == 1) return getNumString(num, 0);

        string answer;
        int firstDigit = (num / 100) % 10;
        int secondDigit = (num / 10) % 10;
        int thirdDigit = num % 10;

        if (firstDigit != 0) answer += getNumString(firstDigit, 2);
        if (secondDigit != 0) {
            if (secondDigit == 1) {
                if (answer.size() > 0 && answer[answer.size()-1] != ' ') answer += " ";
                answer += getTenthDigits(num % 100);
                return answer;
            } else {
                if (answer.size() > 0 && answer[answer.size()-1] != ' ') answer += " ";
                answer += getNumString(secondDigit, 1);
            }
        }

        if (thirdDigit != 0) {
            if (answer.size() > 0 && answer[answer.size()-1] != ' ') answer += " ";
            answer += getNumString(thirdDigit, 0);
        }

        return answer;
    }

    string getTenthDigits(int num) {
        string answer = "";

        if (num == 10) answer += "Ten";
        else if (num == 11) answer += "Eleven";
        else if (num == 12) answer += "Twelve";
        else if (num == 13) answer += "Thirteen";
        else if (num == 14) answer += "Fourteen";
        else if (num == 15) answer += "Fifteen";
        else if (num == 16) answer += "Sixteen";
        else if (num == 17) answer += "Seventeen";
        else if (num == 18) answer += "Eighteen";
        else if (num == 19) answer += "Nineteen";

        return answer;  
    }

    string getNumString(int digit, int k) {
        string answer = "";

        if (k == 1) {
            if (digit == 2) answer += "Twenty";
            else if (digit == 3) answer += "Thirty";
            else if (digit == 4) answer += "Forty";
            else if (digit == 5) answer += "Fifty";
            else if (digit == 6) answer += "Sixty";
            else if (digit == 7) answer += "Seventy";
            else if (digit == 8) answer += "Eighty";
            else if (digit == 9) answer += "Ninety";
            return answer;
        }

        if (digit == 0) answer += "Zero";
        if (digit == 1) answer += "One";
        else if (digit == 2) answer += "Two";
        else if (digit == 3) answer += "Three";
        else if (digit == 4) answer += "Four";
        else if (digit == 5) answer += "Five";
        else if (digit == 6) answer += "Six";
        else if (digit == 7) answer += "Seven";
        else if (digit == 8) answer += "Eight";
        else if (digit == 9) answer += "Nine";
    
        if (k == 2 && digit != 0) {
            answer += " Hundred";
        }

        return answer;
    }

    int getNumLength(int num) {
        if (num == 0) return 1;
        return 1 + floor(log10(num));
    }
};