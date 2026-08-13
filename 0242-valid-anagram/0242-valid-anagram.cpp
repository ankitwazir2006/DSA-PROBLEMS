class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }
        int arr[26];
        int arr2[26];
        for(int i= 0 ; i<s.size();i++){
            arr[s[i]-'a']++;
            arr2[t[i]-'a']++;
        }
        for(int i = 0 ; i< s.size();i++){
            if(arr[s[i]-'a']!=arr2[s[i]-'a']){
                return false;
            }
        }
        return true;
    }
};