class Solution {
    bool isvowel( char ch){
        return  ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u';
             
    }
public:
    int maxVowels(string s, int k) {
        int ans=0;
        int count=0;
        for(int  i = 0 ; i <k ; i++){
            char ch = s[i];
            if(isvowel(ch)){
                count++;
            }
        }
        ans=count;
        for(int i = k ; i< s.length(); i++){
            if(isvowel(s[i-k])){
                count--;
            }
            if(isvowel(s[i])){
                count++;
            }
            ans=max(ans,count);
        }
        return ans;
                         
    }
};