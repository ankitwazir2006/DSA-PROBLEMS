class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> m;
        for(int i = 0;i<text.length(); i++){
            char ch= text[i];
             m[ch]++;
        }
        return min({m['b'],m['a'],m['o']/2,m['l']/2,m['n']});
    }
};