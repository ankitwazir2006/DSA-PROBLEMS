class Solution {
public:
    int strStr(string haystack, string needle) {
        int occurance;
        if(haystack.find(needle)!=string::npos){
            return haystack.find(needle);
        }
        return -1;
    }
};