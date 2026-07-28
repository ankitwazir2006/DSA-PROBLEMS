class Solution {
public:
    string smallestPalindrome(string s) {
        int mid=s.length()/2;
        sort(s.begin(),s.begin()+mid);
        int l=0;
        int e=s.length()-1;
        while(l<e){
            s[e]=s[l];
            e--;
            l++;
        }
        return s;
    }
};