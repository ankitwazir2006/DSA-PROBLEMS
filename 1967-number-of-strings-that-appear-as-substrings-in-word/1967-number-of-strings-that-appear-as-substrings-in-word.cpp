class Solution {
private:
    bool appears(string s, string word) {
        for (int i = 0; i < word.length(); i++) {

            int j = 0;

            while (j < s.length() && i + j < word.length() &&
                   word[i + j] == s[j]) {
                j++;
            }

            if (j == s.length())
                return true;
        }
        return false;
    }

public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;
        for (int i = 0; i < patterns.size(); i++) {
            string s = patterns[i];
            if (appears(s, word)) {
                count++;
            }
        }
        return count;
    }
};