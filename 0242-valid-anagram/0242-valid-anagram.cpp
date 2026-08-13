class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }
         unordered_map<char,int> mp1;
         unordered_map<char,int>mp2;
         for(int i = 0 ; i< s.size();i++){
            char c1= s[i];
            char c2=t[i];
            mp1[c1]++;
            mp2[c2]++;
         }
         for(int i = 0 ; i<s.size();i++){
            if(mp1[s[i]]!=mp2[s[i]]){
                return false;
            }
         }
         return true;
    }
};