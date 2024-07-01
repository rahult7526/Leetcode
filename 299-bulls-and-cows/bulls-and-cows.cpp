class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> sec, gues;
        int Bulls = 0, Cows = 0, n = secret.size();
        for (int i = 0; i < n; i++) {
            if (secret[i] == guess[i]) {
                Bulls++;
            } else {
                sec[secret[i]]++;
                gues[guess[i]]++;
            }
        }
        for (auto x : sec) {
            char ch = x.first;
            int frq = x.second;
            Cows += min(frq, gues[ch]);
        }
        return to_string(Bulls) + 'A' + to_string(Cows) + 'B';
    }
};