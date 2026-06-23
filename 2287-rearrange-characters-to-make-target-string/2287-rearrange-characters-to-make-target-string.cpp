class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char ,int>freq1;
        int mini= INT_MAX ;
        for(int i = 0 ; i<s.length();i++){
            char ch = s[i];
            freq1[ch]++;
        }
        unordered_map<char ,int>freq2;
        for(int i = 0 ; i<target.length();i++){
            char ch = target[i];
            freq2[ch]++;
        }
        for(int i = 0 ; i<target.length();i++){
             char ch = target[i];
             if(freq2[ch]>0){
                mini = min(mini,freq1[ch]/freq2[ch]);
                freq2[ch]=0;
             }
           
         
        }
           return mini;
        
    }
};