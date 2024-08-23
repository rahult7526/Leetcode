class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a%b);
    }
    int lcm(int a, int b) {
        return (a * b) / gcd(a,b);
    }
    string fractionAddition(string e) {
        int numerator = 0, denomenator = 1;
        int nu, de, l,j, i = 0;
 
        for (i = 0;i < e.size();) {
            if ((i == 0 && e[i] != '-') || e[i] == '-' || e[i] == '+') {
                j = (i==0 && e[i]!='-') ? i : i+1;
                nu = 0;
                while (e[j] != '/') {
                    nu = nu * 10 + (e[j++] - '0');
                }
                de = 0;
                j++;
                while (j < e.size() && isdigit(e[j])) {
                    de = de * 10 + (e[j++] - '0');
                }
                l = lcm(de, denomenator);
                nu *= l / de;
                numerator *= l / denomenator;

                if (e[i] == '-')
                numerator -= nu;
                else
                numerator += nu;
                denomenator = l;
            }
            i = j;
        }
        int g = gcd(numerator, denomenator);
        numerator /= g;
        denomenator /= g;

        if (denomenator < 0) {
            numerator *= -1;
            denomenator *= -1;
        }
        return to_string(numerator) + "/" + to_string(denomenator);
    }
};