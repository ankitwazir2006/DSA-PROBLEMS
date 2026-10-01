class Solution {
public:
    bool isValid(string s) {
        stack<char> stac;
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if (ch == '(' || ch == '{' || ch == '[') {
                stac.push(ch);
            } else {
                if (!stac.empty()) {
                    char top = stac.top();
                    if ((ch == ')' && top == '(') ||
                        (ch == '}' && top == '{') ||
                        (ch == ']' && top == '[')) {
                        stac.pop();
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
            }
        }
        if (stac.empty()) {
            return true;
        } else {
            return false;
        }
    }
};