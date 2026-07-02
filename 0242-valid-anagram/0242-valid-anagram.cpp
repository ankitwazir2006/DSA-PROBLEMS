class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }
        unordered_map<char,int>mp1;
        unordered_map<char,int>mp2;
        for(int i = 0 ; i<s.length(); i++){
            char ch=s[i];
            mp1[ch]++;
        }
        for(int i = 0 ; i<t.length(); i++){
            char ch=t[i];
            mp2[ch]++;
        }
         for(int i = 0 ; i <s.length(); i++){
            char ch=s[i];
            if(mp1[ch]!=mp2[ch]){
                return false;
            }
         }
           return true;
    }
  
};